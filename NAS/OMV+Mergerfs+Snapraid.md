## OMV+Mergerfs+Snapraid搭建过程
### OMV系统安装
OMV文件我存到了/NAS/Backup/OMV中  
[OMV官网下载地址超连接](https://sourceforge.net/projects/openmediavault/files/)

* 准备启动介质
    * linux系统
        ```
        df -kh // 查看需要装载的硬盘所在的/dev/sdX
        sudo dd if=openmediavault_2.1_amd64.iso of=/dev/sdX bs=4096 // 这个我没试过。慎重使用
        ```
    * windows系统  
    路径是打开ultraiso点击文件->打开->选择你下载的openmediavault_1.0.20_amd64.iso文件->点击启动->写入硬盘镜像

* 安装过程  
    插入U盘，U盘启动安装系统，这个没什么难度，略过

* 设置OMV  
    如果出现设置错误，可以在本地输入命令omv-firstaid，重置ip地址、WebUI端口、管理员密码等操作。  

    * 设置页面刷新时间，会话超时设置为0时，系统不自动登出。  
    * 安装OMV-Extras
        ```
        sudo apt-get install dirmngr
        wget http://omv-extras.org/openmediavault-omvextrasorg_latest_all4.deb 
        dpkg-i openmediavault-omvextrasorg_latest_all4.deb 
        sudo apt-get update
        ```
        之后刷新浏览器，会在“系统”中看见多了一个“OMV-Extras”，进入“OMV-Extras”，选择一个未选择的源—点击编辑—启用—保存，重复这几个步骤以启用所有源，之后保存并应用。

    * 启用SMB，sftp，ssh服务
    * 创建用户： 创建常用用户记得加入sudo,ssh用户组

### SnapRAID设置
[SnapRaid官方下载](https://www.snapraid.it/download)  
[SnapRaid官方文档](https://www.snapraid.it/manual)  
看了官方文件SnapRaid是专门针对家庭NAS来设计的

* OMV中SnapRaid插件安装  
    插件中查找snapraid，点击安装即可

* 配置在/etc/snapraid.conf中，这里给个其它人的例子
    ```
    # 校验文件的位置
    # 显然，校验文件不能放在数据盘上，否则就没有意义了
    parity /media/disk3/snapraid.parity

    # 如需添加更多的校验文件则继续添加
    # 最多是 6 份校验，承受磁盘磁盘阵列中最多同时坏掉 6 块盘的情况
    #2-parity /media/disk4/snapraid.2-parity
    #3-parity /media/disk5/snapraid.3-parity

    # 重要的索引文件，建议保存多份（内容是一样的）
    # 我在系统盘（SSD）上存了一份，然后在三块磁盘上都各存一份
    # 系统盘上的这份同时又会被 BorgBackup 异地备份
    # 最少要两个content
    content /home/snapraid/snapraid.content
    content /media/disk1/snapraid.content
    content /media/disk2/snapraid.content
    content /media/disk3/snapraid.content

    # 指定数据盘及其挂载点
    # 这里不一定要写确切的挂载点，可以是这块盘上的任意目录
    # 目录以外的内容会被完全忽略
    data d1 /media/disk1/
    data d2 /media/disk2/

    # 忽略所有隐藏文件和目录（不做冗余）
    # 在 Unix-like 里就是 . 开头的文件和目录
    # 在 Windows 里就是带隐藏属性的文件和目录
    nohidden

    # 排除列表与包含列表，注意顺序！下文详解
    exclude *.unrecoverable
    exclude *.nobackup
    exclude *.nobackup/
    exclude /tmp/
    exclude /lost+found/
    #include /foo
    #include /bar/

    # 生成校验数据时，每处理 10 GiB 数据自动保存一次，方便断点继续
    autosave 10
    ```

* 配置文件配置之后可以进行snapraid sync 进行同步  
    * 特别要注意的是在进行数据传输的过程中最好进行snapraid命令，经常会有错误发生！！！
    * 第一次时间会很长，不建议用网页来执行命令，登陆后台用如下命令  
        ```
        nohup snapraid sync>~/sync.log 2>&1 &
        ```

* 设置同步  
    使用systemd timer来进行同步，omv也自带同步功能

* 与 mergerfs 配合
    可以配合mergerfs配合，只用一个大的数据盘

## 参考文章
[mergerfs](https://wzyboy.im/post/1148.html)  
[snapraid](https://wzyboy.im/post/1186.html)

