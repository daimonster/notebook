## root用户的禁止远程登陆
1. 修改配置文件
```
vim /etc/ssh/sshd_config 
将PermitRootLogin 后面的yes改成no
```
2. 重启ssh服务
``` 
#/etc/init.d/ssh restart
```
 
