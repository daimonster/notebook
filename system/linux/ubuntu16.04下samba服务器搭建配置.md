## 前言
此fa

## 安装Samba服务程序

```
sudo apt-get install samba smbclient
```

## 修改配置文件
```
sudo vi /etc/samba/smb.conf
```

在文件末尾添加
```
[Movies]
comment = Share Folder
path = /home/daiftp/NewDisk/Movies
guest ok = no
browseable = yes
writable = yes
create mask = 0770
directory mask = 0770
```
