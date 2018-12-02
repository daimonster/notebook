## 参考
[阮一峰-systemd命令篇](http://www.ruanyifeng.com/blog/2016/03/systemd-tutorial-commands.html)

## systemd简介
它的设计目标是，为系统的启动和管理提供一套完整的解决方案。  
![systemd的结构图](http://118.126.64.234:10022/daimonster/Images/raw/master/systemd/systemd-structure.png)  

## 常用命令
Systemd 并不是一个命令，而是一组命令，涉及到系统管理的方方面面。  
### systemctl
systemctl是 Systemd 的主命令，用于管理系统。  
```
# 重启系统
$ sudo systemctl reboot

# 关闭系统，切断电源
$ sudo systemctl poweroff

# CPU停止工作
$ sudo systemctl halt

# 暂停系统
$ sudo systemctl suspend

# 让系统进入冬眠状态
$ sudo systemctl hibernate

# 让系统进入交互式休眠状态
$ sudo systemctl hybrid-sleep

# 启动进入救援状态（单用户状态）
$ sudo systemctl rescue
```

### systemd-analyze
systemd-analyze命令用于查看启动耗时。  
```
# 查看启动耗时
$ systemd-analyze
```

### hostnamectl
hostnamectl命令用于查看当前主机的信息。  

### localectl
localectl命令用于查看本地化设置。
```
# 查看本地化设置
$ localectl

# 设置本地化参数。
$ sudo localectl set-locale LANG=en_GB.utf8
$ sudo localectl set-keymap en_GB
```

### timedatectl
timedatectl命令用于查看当前时区设置。  

### loginctl
loginctl命令用于查看当前登录的用户。  

***
## Unit
### 概述
Systemd 可以管理所有系统资源。不同的资源统称为 Unit（单位）。  

Unit 一共分成12种。  

>* Service unit：系统服务
>* Target unit：多个 Unit 构成的一个组
>* Device Unit：硬件设备
>* Mount Unit：文件系统的挂载点
>* Automount Unit：自动挂载点
>* Path Unit：文件或路径
>* Scope Unit：不是由 Systemd 启动的外部进程
>* Slice Unit：进程组# 显示某个 Unit 是否正在运行
>* Snapshot Unit：Systemd 快照，可以切回某个快照
>* Socket Unit：进程间通信的 socket
>* Swap Unit：swap 文件
>* Timer Unit：定时器

* systemctl list-units命令可以查看当前系统的所有 Unit 。  

* 除了status命令，systemctl还提供了三个查询状态的简单方法，主要供脚本内部的判断语句使用。 
    ```
    # 显示某个 Unit 是否正在运行
    $ systemctl is-active application.service

    # 显示某个 Unit 是否处于启动失败状态
    $ systemctl is-failed application.service

    # 显示某个 Unit 服务是否建立了启动链接
    $ systemctl is-enabled application.service
    ``` 

### Unit的管理
对于用户来说，最常用的是下面这些命令，用于启动和停止 Unit（主要是 service）。

```
# 立即启动一个服务
$ sudo systemctl start apache.service

# 立即停止一个服务
$ sudo systemctl stop apache.service

# 重启一个服务
$ sudo systemctl restart apache.service

# 杀死一个服务的所有子进程
$ sudo systemctl kill apache.service

# 重新加载一个服务的配置文件
$ sudo systemctl reload apache.service

# 重载所有修改过的配置文件
$ sudo systemctl daemon-reload

# 显示某个 Unit 的所有底层参数
$ systemctl show httpd.service

# 显示某个 Unit 的指定属性的值
$ systemctl show -p CPUShares httpd.service

# 设置某个 Unit 的指定属性
$ sudo systemctl set-property httpd.service CPUShares=500
```

## Unit 的配置文件
### 概述
每一个 Unit 都有一个配置文件，告诉 Systemd 怎么启动这个 Unit 。  
Systemd 默认从目录/etc/systemd/system/读取配置文件。但是，里面存放的大部分文件都是符号链接，指向目录/usr/lib/systemd/system/，真正的配置文件存放在那个目录。  
### 配置文件的格式
一旦修改配置文件，就要让 SystemD 重新加载配置文件，然后重新启动，否则修改不会生效。  
```
$ sudo systemctl daemon-reload
$ sudo systemctl restart httpd.service
```
配置文件就是普通的文本文件，可以用文本编辑器打开。  
systemctl cat命令可以查看配置文件的内容。  
```
$ systemctl cat atd.service

[Unit]
Description=ATD daemon

[Service]
Type=forking
ExecStart=/usr/bin/atd

[Install]
WantedBy=multi-user.target
```
### 配置文件的区块
[Unit]区块通常是配置文件的第一个区块，用来定义 Unit 的元数据，以及配置与其他 Unit 的关系。它的主要字段如下。  
>* Description：简短描述
>* Documentation：文档地址
>* Requires：当前 Unit 依赖的其他 Unit，如果它们没有运行，当前 Unit 会>启动失败
>* Wants：与当前 Unit 配合的其他 Unit，如果它们没有运行，当前 Unit 不会启动失败
>* BindsTo：与Requires类似，它指定的 Unit 如果退出，会导致当前 Unit 停止运行
>* Before：如果该字段指定的 Unit 也要启动，那么必须在当前 Unit 之后启动
>* After：如果该字段指定的 Unit 也要启动，那么必须在当前 Unit 之前启动
>* Conflicts：这里指定的 Unit 不能与当前 Unit 同时运行
>* Condition...：当前 Unit 运行必须满足的条件，否则不会运行
>* Assert...：当前 Unit 运行必须满足的条件，否则会报启动失败

[Install]通常是配置文件的最后一个区块，用来定义如何启动，以及是否开机启动。它的主要字段如下。  
> * WantedBy：它的值是一个或多个 Target，当前 Unit 激活时（enable）符号链接会放入/etc/systemd/system目录下面以 Target 名 + .wants后缀构成的子目录中
> * RequiredBy：它的值是一个或多个 Target，当前 Unit 激活时，符号链接会放入/etc/systemd/system目录下面以 Target 名 + .required后缀构成的子目录中
> * Alias：当前 Unit 可用于启动的别名
> * Also：当前 Unit 激活（enable）时，会被同时激活的其他 Unit

[Service]区块用来 Service 的配置，只有 Service 类型的 Unit 才有这个区块。它的主要字段如下。  
> * Type：定义启动时的进程行为。它有以下几种值。
> * Type=simple：默认值，执行ExecStart指定的命令，启动主进程
> * Type=forking：以 fork 方式从父进程创建子进程，创建后父进程会立即退出
> * Type=oneshot：一次性进程，Systemd 会等当前服务退出，再继续往下执行
> * Type=dbus：当前服务通过D-Bus启动
> * Type=notify：当前服务启动完毕，会通知Systemd，再继续往下执行
> * Type=idle：若有其他任务执行完毕，当前服务才会运行
> * ExecStart：启动当前服务的命令
> * ExecStartPre：启动当前服务之前执行的命令
> * ExecStartPost：启动当前服务之后执行的命令
> * ExecReload：重启当前服务时执行的命令
> * ExecStop：停止当前服务时执行的命令
> * ExecStopPost：停止当其服务之后执行的命令
> * RestartSec：自动重启当前服务间隔的秒数
> * Restart：定义何种情况 Systemd 会自动重启当前服务，可能的值包括always（总是重启）、on-success、on-failure、on-abnormal、on-abort、on-watchdog
> * TimeoutSec：定义 Systemd 停止当前服务之前等待的秒数
> * Environment：指定环境变量
## Target
启动计算机的时候，需要启动大量的 Unit。如果每一次启动，都要一一写明本次启动需要哪些 Unit，显然非常不方便。Systemd 的解决方案就是 Target。  

简单说，Target 就是一个 Unit 组，包含许多相关的 Unit 。启动某个Target 的时候，Systemd 就会启动里面所有的 Unit。从这个意义上说Target 这个概念类似于"状态点"，启动某个 Target 就好比启动到某种态。  

传统的init启动模式里面，有 RunLevel 的概念，跟 Target 的作用很类似。不同的是，RunLevel 是互斥的，不可能多个 RunLevel 同时启动，但是多个 Target 可以同时启动。
## 日志管理
Systemd 统一管理所有 Unit 的启动日志。带来的好处就是，可以只用journalctl一个命令，查看所有日志（内核日志和应用日志）。日志的配置文件是/etc/systemd/journald.conf。
```
# 查看所有日志（默认情况下 ，只保存本次启动的日志）
$ sudo journalctl
```