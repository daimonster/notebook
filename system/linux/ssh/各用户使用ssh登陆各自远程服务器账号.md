### 配置步骤

1. 添加用户  
    ```
    useradd tomcat # 创建新用户
    passwd tomcat # 设置密码
    ```
2. 建立密钥对
    ```
    su tomcat # 切换到用户
    ssh-keygen -b 1024 -t rsa # 生成密钥
    ```

    -b 1024 采用长度为1024字节的公钥/私钥对，最长4096字节。  
    -t rsa 采用rsa加密方式的公钥/私钥对，除了rsa还有dsa方式，rsa方式最短不能小于768字节长度。  
    如果还需要使用更多其他参数请参考man ssh-keygen  
    还有其他的方式，参见github密钥创建  

3. 拷贝密钥到需要ssh的客户端
    将/home/tomcat/.ssh/id_rsa拷贝到ssh的客户端  
    可能需要将id_rsa的用户权限改成其他的用户
    ```
    sudo chown *** id_rsa
    ```

4. 设置密钥对的权限  
    ```
    chmod 700 /home/tomcat/.ssh/ # 给密钥目录设置权限
    cd /home/tomcat/.ssh/
    mv id_rsa.pub authorized_keys
    chmod 600 authorized_keys # 给私钥文件设置权限
    ```
    这里要注意了：如果你还想加入用其它公钥进入的话，就将公钥内容>>到authorized_keys中去  

1. 将本地的公钥传送到远程服务器中
    ```
    ssh user@host 'mkdir -p .ssh && cat >> .ssh/authorized_keys' < ~/.ssh/id_rsa.pub
    ```

5. 打开ssh密钥登录功能
    ```
    sudo su # 切换到root帐号
    vi /etc/ssh/sshd_config
    # 取消RSAAuthentication yes和PubkeyAuthentication yes前面的#
    # 进入密码登陆 PasswordAuthentication no
    service sshd restart # 重启ssh服务b
    ```
6. ssh客户端登录

7. 遇到的新问题,明明已经将公钥输入到authoried_keys,为什么还是显示连接失败?  
    这个问题花了2个小时才解决  
    将该用户加入ssh用户组  