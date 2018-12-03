1 下载文件并解压
```
tar -xavf 文件
```

2 安装
```
make // 进入redis源文件，并安装
cd ./src // 进入src文件夹
make install // 这样可以直接命令执行redis-server,redis-cli等命令
```

3 配置
安装文件里面有个redis.conf文件的，修改里面的内容，想要设置远程连接
```
bing localhost // 注释掉
deamonize no // 改成yes
protect-mode yes // 改成no 保护模式取消
```

设置快捷启动
```
alias sredis="redis-server /opt/Redis/redis-4.0.11/redis.conf"
```