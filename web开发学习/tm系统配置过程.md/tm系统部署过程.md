## 前序准备
要求:  
* 删除mysql,php,apache
* 要注意的是配置文件port.conf和payload.conf在tm_conf配置文件里面

## 环境启动过程
```
sudo mkdir /var/run/mysqld/
sudo ln -s /opt/lampp/var/mysql/mysql.sock /var/run/mysqld/mysqld.sock
cd /opt/lampp/ && sudo ./xampp start
cd  ~/Library/TMsystem/demo && sudo ./show.sh
```

## 安装前端系统
### 基本上按照4前端配置手册来配置系统  
出现了一点问题的是mysql的sock问题,在文件里面也提到,用如下命令
```
sudo mkdir /var/run/mysqld/
sudo ln -s /opt/lampp/var/mysql/mysql.sock /var/run/mysqld/mysqld.sock
```
然后出现了网页`compile error`的问题,然后发现是htdocs文件夹的授权问题
```
sudo chmod 777 -R htdocs
```
解决问题

### php文件里面的配置

在tm_php文件里面的`app/core/controllers`文件里面
```
define ( 'CONF_PATH', '/home/lishaobo/tm317_with_packet/demo/port.conf' ); 第四行
define ( 'CONF_PATH_PAYLOAD', '/home/lishaobo/tm317_with_packet/demo/payload_config.conf' ); 5
passthru ("cd /home/dai/Library/TMsystem/demo/  \n  ./stopstart.sh -f /home/dai/data/data_final.pcap",$t); 207
exec ("cd /home/dai/Library/TMsystem/demo/  \n  ./start.sh -f /home/dai/data_final.pcap",$t); 216
exec ("cd /home/lishaobo/tm317_with_packet/demo \n  ./start.sh   -i 2 -p 1 ",$t); 226
exec ("cd /home/isit/tm_v1.0.3201505222317/demo/  \n  ./shutdown ",$t); 250
exec ("cd /home/lishaobo/tm317_with_packet/demo  \n  ./pit  -i 0 -p 1 > /dev/null",$t); 263
```

## 后端系统的配置
1. 编译文件
进入tm系统文件夹
```
sudo ./configture
sudo make
```
1. 安装mysql的库
```
sudo apt install libmysqlclient-dev
```
2. 剩下来的在`3tm命令手册里面`讲解了详细的内容
