## 利用Iptables进行端口转发
### 打开转发开关
1. 临时打开
    ```
    sudo su
    echo 1 >/proc/sys/net/ipv4/ip_forward
    ```

2. 永久打开
    编辑/etc/sysctl.conf文件，将net.ipv4.ip_forward=1前面的#注释去掉，保存文件，然后执行sudo sysctl -p使其生效  
### 使用场景
1. 同一台机器内的端口转发
    外部80端口转发到8080端口  
    ```
    sudo iptables -t nat -A PREROUTING -p tcp --dport 80 -j REDIRECT --to-port 8080
    ```
    另外一个例子  
    ```
    sudo iptables -t nat -A PREROUTING -p tcp -i eth0 -d 125.69.67.213 --dport 3000 -j DNAT --to 125.69.67.213:22
    ```

### 查看所有规则
```
sudo iptables -L -n
```
-n参数意思是用数字显示  
### iptables规则保存到文件
```
sudo sh -c "iptables-save > /etc/iptables.rules"
```
### 从文件恢复iptables的规则
```
sudo iptables-restore /etc/iptables.rules
```

### 开机启动加载iptables规则
注：配置的规则系统默认重启后就失效，因此做开机启动时加载iptables的配置也有必要。  
在/etc/network/interfaces的末尾添加如下一行：  
```
pre-up iptables-restore < /etc/iptables.rules
```
如果想在关机的时候自动保存修改过的iptables规则，可添加如下行  
```
post-down iptables-save > /etc/iptables.up.rules
```

