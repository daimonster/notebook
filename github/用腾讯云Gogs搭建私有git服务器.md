## 前言
经常有需要写不能公开代码的项目，所以只好自己搭建一个私人的git服务器

Gogs的好处在于比Gitlib轻量化了好多，而且是国人写的，官方主页也是中文的

[Gogs首页](https://gogs.io/)

腾讯云服务器配置：
* Ubuntu16.04 LTS
* 腾讯云学生版1G内存 1Mbps

## 准备安装
环境是标准的LNM环境：(我之前为了学PHP就已经安装好啦)
```
sudo apt install nginx mysql-server git
```

## 配置数据库

```
SET GLOBAL storage_engine = 'InnoDB';
CREATE DATABASE gogs CHARACTER SET utf8 COLLATE utf8_bin;
GRANT ALL PRIVILEGES ON gogs.* TO ‘root’@‘localhost’ IDENTIFIED BY 'YourPassword';
FLUSH PRIVILEGES;
QUIT；
```
如果mysql是5.0以上版本的默认engine就是InnoDB,就可以不加第一句话（mysql版本查询命令`mysql --version`）
这里的`YourPassword`指的是你需要输入你的mysql的root账户密码

## 创建git用户
创建一个git用户来专门管理Gogs-web服务
```
sudo adduser git
//如果需要给git来添加sudo权限的话
sudo usermod -G sudo git
```

## 下载Gogs
[Gogs官方下载页](https://gogs.io/docs/installation/install_from_binary)
切换到git账户

```
su git
```
下载最新版本
```
wget -c 最新版本链接.zip
unzip 最新版本.zip
```

## 配置Gogs

修改Gogs service配置文件
```
vim /home/git/gogs/scripts/init/debian/gogs
```
```
PATH=/sbin:/usr/sbin:/bin:/usr/bin
DESC="Go Git Service"
NAME=gogs
SERVICEVERBOSE=yes
PIDFILE=/var/run/$NAME.pid
SCRIPTNAME=/etc/init.d/$NAME
WORKINGDIR=/home/git/gogs #这个根据自己的目录修改
DAEMON=$WORKINGDIR/$NAME
DAEMON_ARGS="web"
USER=git  #如果运行gogs不是用的这个用户，修改对应用户
```
切换回root账户
```
sudo cp /home/git/gogs/scripts/init/debian/gogs /etc/init.d/
sudo chmod +x /etc/init.d/gogs
cp /home/git/gogs/scripts/systemd/gogs.service /etc/systemd/system/
sudo service gogs start
```
这样就讲Gogs服务启动起来了 这样还没完

还要到浏览器页面:http://localhost:3000/install 进行配置,(loacalhost改成你自己的腾讯云服务器公网地址，记得开放腾讯云服务器3000端口)

配置页面需要特别注意的是 域名和服务器地址(好像是叫这两个)需要改成腾讯云服务器的公网地址

改错了也没关系，可以使用
```
sudo vi /home/git/gogs/custom/conf/app.ini
```
来修改配置

### 切换端口
如果有的时候需要切换端口，也是在上面app.ini设置，重启下服务器就OK

之后就可以直接访问网页了，跟github是差不多的，不在介绍了，哈哈！





## 参考文章
[使用Gogs 搭建个人git仓库](https://www.jianshu.com/p/d946314bce2f)
[手把手教学–ubuntu安装gogs实现自己的代码管理](https://www.2cto.com/kf/201707/657119.html)
[一步搞定私有Git服务器部署(Gogs)](https://www.jianshu.com/p/424627516ef6)

### Gogs首页
[https://www.jianshu.com/p/424627516ef6](https://www.jianshu.com/p/424627516ef6)