## 简介
简述一下我用docker来配置laravel环境

### 软件镜像
+ php:7.2-rc-fpm-alpine
+ mysql:5.6
+ nginx:1.12.2-alpine
### 配置环境
+ Ubuntu:16.04
+ macOS:Sierra

以上两个操作系统我都实验过,均能运行

***
## 准备
注意点:要是宿主机上面开着mysql和nginx服务的,请停止服务,要不然两个服务分别占用:3306和80或443端口,使得容器无法启动
```
service mysql stop 
ps -ef|grep nginx
kill pid# nginx 的进程号
```
## 配置过程
### 从github上下载配置文件
```
git clone https://github.com/daimonster/PHP-env.git
```
切换版本
```
git checkout laravel5.5
```

### 生成php镜像
```
cd php && docker build -t dai/php:laravel .
```
特别要注意的是镜像名字不能随便填,如果想要改成别的名字,一定要记得将docker-compose.yml文件中的镜像的名字改成一样的

顺便介绍一些有用的docker操作:
+ 批量删除所有镜像：docker rmi $(docker images -q)
+ 批量停止所有容器：docker stop $(docker ps -aq)
+ 批量删除所有容器：docker rm $(docker ps -aq)

### 运行docker-composer
docker-compose.yml内容
```
version: "3"
services:
    nginx:
        image: nginx:1.12.2-alpine
        ports:
            #改成127.0.10.10这样不会与localhost冲突
            - "127.0.10.10:80:80"
            - "127.0.10.10:443:443"
        volumes:
            - ~/Git-Documents:/home/code:rw # ~/Git-Documents 是我自己的存放代码的目录,需要改成自身存放代码的地方
            - ./conf/nginx/nginx.conf:/etc/nginx/nginx.conf:ro#配置nginx
            - ./conf/nginx/vhost:/etc/nginx/conf.d:ro#配置nginx
            - ./log/nginx:/var/log/nginx:rw
        networks:
            - code-network

    php:
        image: dai/php:laravel
        volumes:
            - ~/Git-Documents:/home/code:rw # 这里同上
            - ./conf/php/php.ini-development:/usr/local/etc/php/php.ini:ro # 配置php
        networks:
            - code-network
    mysql:
        image: mysql:5.6
        ports:
            - "3310:3306"
        volumes:
            - ./conf/mysql/my.cnf:/etc/mysql/my.cnf:ro
            - ./data/mysql:/var/lib/mysql:rw
            - ./log/mysql:/var/log/mysql:rw
        environment:
            MYSQL_ROOT_PASSWORD: "root"
            MYSQL_USER: "test"
            MYSQL_PASSWORD: "test123"
networks:
    code-network:
        driver: bridge

```

运行命令:
```
# 前台运行
docker-composer up
# 后台运行
docker-composer up -d
```

### 对php容器进行修改
用`docker ps`查看正在运行中的容器,然后进入php容器
```
docker exec -it [容器ID] sh
```

创建laravel项目
```
composer create-project laravel/laravel Laravel --prefer-dist "5.4.*"
```

给访问用户权限
```
sudo chown -R :www-data /home/ubuntu/Code/Laravel
sudo chmod -R 775 /home/ubuntu/Code/Laravel/storage
```
如果能成功显示laravel页面,就OK了
