## 镜像

### 获取镜像
命令格式为
```
docker pull [选项] [Docker Registry 地址[:端口号]/]仓库名[:标签]
```
例如
```
docker pull ubuntu:16.04
```
进入Ubuntu的bash界面：
```
docker run -it ubuntu:16.04 bash
```
* -it：这是两个参数，一个是 -i：交互式操作，一个是 -t 终端。我们这里打算进入 bash 执行一些命令并查看返回结果，因此我们需要交互式终端。
* --rm：这个参数是说容器退出后随之将其删除。默认情况下，为了排障需求，退出的容器并不会立即删除，除非手动 docker rm。我们这里只是随便执行个命令，看看结果，不需要排障和保留结果，因此使用 --rm 可以避免浪费空间。
* ubuntu:16.04：这是指用 ubuntu:16.04 镜像为基础来启动容器。
* bash：放在镜像名后的是命令，这里我们希望有个交互式 Shell，因此用的是 bash。

***

### 列出镜像

列出镜像
```
docker images 或者 docker image ls
```

删掉无用镜像
```
docker image prune
```

### 删除镜像
```
docker image rm [选项] <镜像1> [<镜像2> ...]
```

### 利用commit了解镜像构成
镜像是容器的基础，每次执行docker run的时候都会指定那个镜像作为容器运行的基础。
直接使用某些镜像是可以满足一定的需求，而当这些镜像无法直接满足需求时，我们就需要定制这些镜像

进项是多层存储，每一层是前一层基础上的修改；而容器也是多层存储，是在以镜像为基础层，在其基础上加一层作为容器运行时的存储层。

运行nginx容器
```
docker run --name webserver -d -p 80:80 nginx
```
这样可以对容器的做出更改

用docker commit提交对容器的更改
```
docker commit [选项] <容器ID或容器名> [<仓库名>[:<标签>]]
```
范例
```
docker commit \
    --author "Tao Wang <twang2218@gmail.com>" \
    --message "修改了默认网页" \
    webserver \
    nginx:v2
```
但是docker commit 会使镜像变得十分臃肿，不易维护，所以尽量少用docker commit