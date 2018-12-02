## 一、本文参考
[本文参考翻译自官方安装文档](https://docs.docker.com/engine/installation/linux/docker-ce/ubuntu/)

***

## 二、准备工作
### Docker版本
Docker v17.12 CE(免费版本)

### 系统要求
Xenial 16.04 

Docker CE is supported on Ubuntu on x86_64, armhf, s390x (IBM Z), and ppc64le (IBM Power) architectures.

### 卸载旧版本
Dcoker有旧的版本叫做`docker`或者`docker-engine`如果有安装的话
```
sudo apt-get remove docker docker-engine docker.io
```

ps：我安装的这个版本叫做docker-ce.

***

## 三、开始安装
1. 更新
    ```
    sudo apt-get update
    ```
1. 安装transport-https
    ```
    sudo apt-get install \
    apt-transport-https \
    ca-certificates \
    curl \
    software-properties-common
    ```
2. 添加Docker官方GPG钥匙：
    ```
    curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -
    ```
    检查一下你的钥匙
    ```
    sudo apt-key fingerprint 0EBFCD88
    ```
    如果显示以下内容说明你得到正确钥匙
    ```
    pub   4096R/0EBFCD88 2017-02-22
        Key fingerprint = 9DC8 5822 9FC7 DD38 854A  E2D8 8D81 803C 0EBF CD88
    uid                  Docker Release (CE deb) <docker@docker.com>
    sub   4096R/F273FCD8 2017-02-22
    ```
3. 设置 stable repository(这个不知道怎么翻译好,稳定版仓库?)
    ```
    sudo add-apt-repository \
    "deb [arch=amd64] https://download.docker.com/linux/ubuntu \
    $(lsb_release -cs) \
    stable"
    ```
    如果你需要安装edge版本,则需要在上面命令的stable版本的后面添加edge
4. 安装Dcoker CE
    ```
    sudo apt-get update && sudo apt-get install docker-ce
    ```
5. 测试是否安装成功
    ```
    sudo docker run hello-world
    ```
    如果安装成功的话会显示测试信息之后退出
    
6. 要是你不想总是运行Docker前面加上sudo
    ```
    sudo groupadd docker && sudo usermod -aG docker $USER

    ```
    然后注销登录使得设置生效
    然后运行
    ```
    docker run hello-world
    ```


***

## 四、更新和卸载
### 更新
更新就是更新列表,然后继续安装就OK了
```
sudo apt-get update && sudo apt-get install docker-ce
```
### 卸载Docker
```
sudo apt-get purge docker-ce
```
如果有没删干净的文件
```
sudo rm -rf /var/lib/docker
```
