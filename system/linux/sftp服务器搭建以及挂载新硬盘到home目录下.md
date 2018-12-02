## 前言

我身边一直有一个空闲不用的硬盘，一直空闲不用，闲暇的时候想到为什么不用起来呢，于是想起来搭建一个sftp服务器，当做云盘用了

## 搭建sftp服务器

1. SFTP称作“安全的FTP”，它使用ssh文件传输协议,所以必须安装openssh-server
    ```
    sudo apt-get install openssh-server
    ```

1. 创建新的用户组ftpaccess
    ```
    sudo groupadd ftpaccess
    ```

1. 修改ssh配置
    ```
    sudo vi /etc/ssh/sshd_config
    # 在文件的最后行添加如下内容
    Subsystem sftp internal-sftp
    Match group ftpaccess
    ChrootDirectory %h
    X11Forwarding no
    AllowTcpForwarding no
    ForceCommand internal-sftp
    ```

1. 重启sshd服务
    ```
    sudo service ssh restart
    ```

1. 创建访问stfp服务的用户并设置权限
    ```
    # 禁止使用ssh登录
    sudo useradd -m john -g ftpaccess -s /usr/sbin/nologin
    # 修改john的密码
    sudo passwd john
    # 改变home目录的所有者
    sudo chown root /home/john
    # 创建ftp访问目录（将来用于挂在新的硬盘），并修改所有者
    sudo mkdir /home/john/NewDsik
    sudo chown john:ftpaccess /home/john/NewDisk 
    ```

接下来服务器就应该能访问了，注意要使用22端口连接服务。

## 挂载硬盘的到home目录下

1. 显示硬盘信息并且格式化
    ```
    # 显示信息
    sudo fdisk -lu 
    # 格式化
    sudo mkfs -t ext4 /dev/sdb
    ```

1. 显示硬盘信息并找到对应分区的UUID
    ```
    df -kh
    sudo blkid
    ```

1. 卸载硬盘
    ```
    sudo umout dev/sdb1
    ```

1. 永久挂载到home目录下

    修改分区文件
    ```
    sudo vi /etc/fstab
    ```
    按照如下格式添加硬盘内容
    ```
    UUID=0001D3CE0001E53B /home/john/NewDisk ntfs defaults 0 2 
    ```
    其中第一列为UUID, 第二列为挂载目录（该目录必须为空目录），第三列为文件系统类型，第四列为参数，第五列0表示不备份，最后一列必须为２或0(除非引导分区为1) <br>
    挂载
    ```
    sudo mount -a 
    df -kh
    ```
    挂载成功



## 参考
1. [在Ubuntu 14.04上安装搭建FTP服务器详解](https://www.linuxidc.com/Linux/2016-03/129057.htm)

1. [Ubuntu - 硬盘分区、格式化、自动挂载配置](http://blog.csdn.net/hejiamian/article/details/52031910)

1. [Ubuntu 14.04 将其他盘挂载到/home的子目录下](blog.csdn.net/handsome_for_kill/article/details/52654724)