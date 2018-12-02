## 本文参考
[云服务器上部署Laravel的实例教程](http://www.php.cn/php-weizijiaocheng-372109.html)<br>

[腾讯云 创建 Laravel5.4 项目](https://laravel-china.org/articles/4254/tencent-cloud-create-laravel54-project)<br>

[阿里云服务器部署php的laravel项目,在阿里云买ECS 搭建 Linux+Nginx+Mysql+PHP环境的 ](https://my.oschina.net/earnp/blog/788456)

## 前言
最近在学Laravel,同参考文章，本来只是在虚拟机上运行，但现在正好因为手上有腾讯云的服务器，所以就直接拿来部署Laravel。

首先做下准备工作
```
sudo apt update
```
下面不是必要的，但是如果有开着apache2服务器的话，是必须做的
```
sudo service apache2 stop
update-rc.d -f apache2 remove
sudo apt-get remove apache2
```

## 1.安装Nignx
```
sudo apt install nginx && sudo service nginx start
```
安装完记得输入服务器的公网地址如果有显示
> Welcome to nginx!

就表示安装成功了

## 2.安装Mysql
```
sudo apt install mysql-server 
```
期间要注意输入账号密码


## 3.安装php7.0
### 安装
```
sudo apt install phpo7.0-fpm php7.0-mcrypt
```
这里我装的是php7.0，这个在后面配置nginx的时候碰到了一个大坑，这里先不说，等到配置nginx的时候详细说明
### 配置
```
sudo vi /etc/php/7.0/fpm/php.ini 
```
找到`cgi.fix_pathinfo`删掉注释，并将其值改为0
```
cgi.fix_pathinfo=0
```
启用php7.0-mcrypt以及重启php服务
```
sudo phpenmod mcrypt
sudo service php7.0-fpm restart
```

## 4.配置nginx
nginx的配置文件在
```
/etc/nginx/sites-available/default
```
所以
```
sudo vim /etc/nginx/sites-available/default
```
这里说下我遇到的坑，我找到的参考文章都是安装的php5，然而我安装的是php7.0,这里导致了我的ngnix不能解析php文件，网站一直显示502错误，花了我一晚上的时间，废话不多说，我把我的配置贴出来
```
server {
	listen 80 default_server;
	listen [::]:80 default_server;

	root /home/ubuntu/Code/Laravel/public;

	index index.php index.html index.htm index.nginx-debian.html;

	server_name servername or IP;# 这里填写服务器名或云服务器的IP

    location / {
        try_files $uri $uri/ /index.php?$query_string;
    }

    location = /favicon.ico { access_log off; log_not_found off; }
    location = /robots.txt  { access_log off; log_not_found off; }

    access_log off;
    error_log  /var/log/nginx/error.log error;

	location ~ \.php$ {
  		try_files $uri /index.php =404;
	  	fastcgi_split_path_info ^(.+\.php)(/.+)$;
	  	fastcgi_pass unix:/run/php/php7.0-fpm.sock;
  		fastcgi_index index.php;
		fastcgi_param SCRIPT_FILENAME $document_root$fastcgi_script_name;
		include fastcgi_params;
	}
}
```
上面可以看到我把我的网站根目录改成了Laravel项目的根目录

最后
```
sudo service nginx restart
```

## 5.创建Laravel项目
```
composer create-project laravel/laravel Laravel --prefer-dist "5.4.*"
```

## 6.给网站访问用户权限
如果不给网页请求设置权限的话，就会显示无法访问的错误
```
sudo chown -R :www-data /home/ubuntu/Code/Laravel
sudo chmod -R 775 /home/ubuntu/Code/Laravel/storage
```

输入你的公网地址，如果能显示页面就表示成功了