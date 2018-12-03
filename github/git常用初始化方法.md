## 准备工作
1. 安装git
    ```
    sudo apt install git
    ```
2. 创建一个ssh密钥
    如果已经有ssh密钥了，则这一步不要执行
    ```
    ssh-keygen -t rsa -C '账号'
    ```
3. 复制公钥内容
    ```
    gedit ~/.ssh/id_rsa.pub
    ```
    复制文件的内容

1. 添加到ssh and GPG keys
    打开github，在设置里里面找到ssh and GPG keys，然后添加id_rsa.pub内容

## 本地工作
有两种方式：
1. 将本地文件推送到远程仓库中
    + 初始化文件夹
    ```
    git init 文件夹
    ```
    * 将本地文件与远程仓库联系起来
    ```
    git remote add origin git@server/仓库.git
    ```
    * 推送到远程仓库
    **只需要第一次推送的加上-u**
    ```
    git push -u origin master 
    ```

2. 从远程仓库下载文件
    ```
    git clone git@server/仓库.git
    ```

## 另外一些远程连接的管理
```
1、查看远程连接 git remote -v

2、添加远程连接 git remote add origin + url

3、删除远程连接 git remote rm origin 

4、远程分支对应 git branch --set-upstream-to=origin/branch-name 
```