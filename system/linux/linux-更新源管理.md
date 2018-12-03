## 新手图形设置
图形界面配置  
新手推荐使用图形界面配置： 系统设置 -> 软件和更新 选择下载服务器 -> "mirrors.aliyun.com"  

## 1.备份源
主要防止在更新了新的源之后出现错误情况，备份一下现有的源
```
sudo cp /etc/apt/sources.list /etc/apt/sources.list.old
```

## 2.编辑sources.list文件
用vim编辑器编辑
```
sudo vi sources.list
```

先将原来文件内容全部删除,vim命令是`dG`

## 3.添加源
亲测阿里云的源非常好用
```
deb http://mirrors.aliyun.com/ubuntu/ xenial main
deb-src http://mirrors.aliyun.com/ubuntu/ xenial main

deb http://mirrors.aliyun.com/ubuntu/ xenial-updates main
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates main

deb http://mirrors.aliyun.com/ubuntu/ xenial universe
deb-src http://mirrors.aliyun.com/ubuntu/ xenial universe
deb http://mirrors.aliyun.com/ubuntu/ xenial-updates universe
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-updates universe

deb http://mirrors.aliyun.com/ubuntu/ xenial-security main
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security main
deb http://mirrors.aliyun.com/ubuntu/ xenial-security universe
deb-src http://mirrors.aliyun.com/ubuntu/ xenial-security universe
```
## 4.更新
```
sudo apt update
```

我们继续来做一个测试