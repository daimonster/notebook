## 显示所有用户
```
cat /etc/passwd
```

## 添加和删除用户
### 添加用户
```
sudo adduser xxx #这样的命令会在home目录下添加一个帐号 
sudo useradd xxx #仅仅是添加用户， 不会在home目录添加帐号 
```

### 删除用户
```
sudo userdel -r newuser
```
另外删除组的命令是：
```
sudo groupdel -R username
```

### 添加和删除用户sudo权限
+ 添加
```
sudo gpasswd -a username sudo 
#或者
sudo usermod -G sudo git
```
+ 删除
```
sudo gpasswd -d username sudo
```

## 其他操作
```
usermod -l u1 user1 #修改用户名
```





https://blog.csdn.net/huiwudiyi/article/details/78259629

https://blog.csdn.net/zxssoft/article/details/80634997
https://blog.csdn.net/liangzi_lucky/article/details/52441495
https://blog.csdn.net/websinesafe/article/details/80620437