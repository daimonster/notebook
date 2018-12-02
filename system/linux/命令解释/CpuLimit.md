cpulimit： 当我们需要限制某些进程的CPU占用率的时候，这个命令就显得很有用

## 安装
* Debian系：
    ```
    sudo apt install cpulimit
    ```
* CentOS:
    ```
    yum install cpulimit
    ```
## 示例

* 根据ID限制：
    ```
    cpulimit -p 1234 -l 40
    ```
    意思为进程号为1234的进程只能占用40的资源

* 根据进程路径限值
    ```
    cpulimit -e /usr/local/nginx-1.4.1/sbin/nginx -l 50
    ```
    nginx只能使用50%的cpu

