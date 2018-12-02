[阮一峰： Systemd 定时器教程](http://www.ruanyifeng.com/blog/2018/03/systemd-timer.html)

## systemd与cron的对比
* systemd可以查看详细日志
* systemd可以分配最多使用的内存和cpu
* systemd可以整合多个文件单元，完成复杂任务

## 一般systemd的存放地址
* 系统默认单元文件：/lib/systemd/system
* 用户安装的软件单元文件：/etc/systemd/system
* 用户自定义的单元文件地址：/usr/lib/systemd/system

查看service单元：`systemctl list-unit-files --type service`
查看timer单元：`systemctl list-unit-files --type timer`

## 写一个sh文件
写一个硬盘显示的sh文件：  
```
#!/bin/bash
date >> /root/logs/dfshow.log
df -kh | grep /dev/sde2 | awk '{print $1": " $3}'>> /root/logs/dfshow.log
```

## 建立service单元
在`/usr/lib/systemd/system` 下建立一个mytimer.service文件，写入如下内容：
```
[Unit]
Description=MyTimer

[Service]
ExecStart=/bin/bash /path/to/dfshow.sh
```
* ExecStart：systemctl start所要执行的命令
* ExecStop：systemctl stop所要执行的命令
* ExecReload：systemctl reload所要执行的命令
* ExecStartPre：ExecStart之前自动执行的命令
* ExecStartPost：ExecStart之后自动执行的命令
* ExecStopPost：ExecStop之后自动执行的命令

## 建立timer单元

在`/usr/lib/systemd/system` 下建立一个mytimer.timer文件，写入如下内容：
```
[Unit]
Description=Runs mytimer every hour

[Timer]
OnUnitActiveSec=1h
Unit=mytimer.service

[Install]
WantedBy=multi-user.target
```
* OnActiveSec：定时器生效后，多少时间开始执行任务
* OnBootSec：系统启动后，多少时间开始执行任务
* OnStartupSec：Systemd 进程启动后，多少时间开始执行任务
* OnUnitActiveSec：该单元上次执行后，等多少时间再次执行
* OnUnitInactiveSec： 定时器上次关闭后多少时间，再次执行
* OnCalendar：基于绝对时间，而不是相对时间执行
* AccuracySec：如果因为各种原因，任务必须推迟执行，推迟的最大秒数，默认是60秒
* Unit：真正要执行的任务，默认是同名的带有.service后缀的单元
* Persistent：如果设置了该字段，即使定时器到时没有启动，也会自动执行相应的单元
* WakeSystem：如果系统休眠，是否自动唤醒系统

## [Install] 和 target
> mytimer.timer文件里面，还有一个[Install]部分，定义开机自启动（systemctl enable）和关闭开机自启动（systemctl disable）这个单元时，所要执行的命令。
>
> 上面脚本中，[Install]部分只写了一个字段，即WantedBy=multi-user.target。它的意思是，如果执行了systemctl enable mytimer.timer（只要开机，定时器自动生效），那么该定时器归属于multi-user.target。
>
> 所谓 Target 指的是一组相关进程，有点像 init 进程模式下面的启动级别。启动某个Target 的时候，属于这个 Target 的所有进程都会全部启动。
>
> multi-user.target是一个最常用的 Target，意为多用户模式。也就是说，当系统以多用户模式启动时，就会一起启动mytimer.timer。它背后的操作其实很简单，执行systemctl enable mytimer.timer命令时，就会在multi-user.target.wants目录里面创建一个符号链接，指向mytimer.timer。

## 其它
单元控制命令  
```
# 启动单元
$ systemctl start [UnitName]

# 关闭单元
$ systemctl stop [UnitName]

# 重启单元
$ systemctl restart [UnitName]

# 杀死单元进程
$ systemctl kill [UnitName]

# 查看单元状态
$ systemctl status [UnitName]

# 开机自动执行该单元
$ systemctl enable [UnitName]

# 关闭开机自动执行
$ systemctl disable [UnitName]
```
查看 mytimer.timer 的日志  
```
$ sudo journalctl -u mytimer.timer
```

