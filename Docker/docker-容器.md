## 容器
容器的状态用
```
docker contaier ls
```

### 启动容器

启动一个容器的终端，并允许交互
```
docker run -it ubuntu:16.04 /bin/bash
```

当利用 docker run 来创建容器时，Docker 在后台运行的标准操作包括：

* 检查本地是否存在指定的镜像，不存在就从公有仓库下载
* 利用镜像创建并启动一个容器
* 分配一个文件系统，并在只读的镜像层外面挂载一层可读写层
* 从宿主主机配置的网桥接口中桥接一个虚拟接口到容器中去
* 从地址池配置一个 ip 地址给容器
* 执行用户指定的应用程序
* 执行完毕后容器被终止

***
### 后台运行
下面命令
```
docker run ubuntu:16.04 /bin/sh -c "while true; do echo hello world; sleep 1; done"
```
是把输出的结果打印到宿主机上面
加上-d 的话实在容器内部执行

```
docker run -d ubuntu:16.04 /bin/sh -c "while true; do echo hello world; sleep 1; done"
```
获得容器输出信息，用
```
docker container logs
```

***

### 终止容器
使容器停止
```
docker container stop
```
使容器启动
```
docker container start
```
***

### 进入容器
有的时候我们需要进入后台正在运行中的容器
这个时候推荐使用exec命令
```
$ docker run -dit ubuntu
69d137adef7a8a689cbcb059e94da5489d3cddd240ff675c640c8d96e84fe1f6

$ docker container ls
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS              PORTS               NAMES
69d137adef7a        ubuntu:latest       "/bin/bash"         18 seconds ago      Up 17 seconds                           zealous_swirles

$ docker exec -i 69d1 bash
ls
bin
boot
dev
...

$ docker exec -it 69d1 bash
root@69d137adef7a:/#
```
这可以看出使用exit命令不会使容器停止

***

### 导入和导出容器
导出容器
```
$ docker container ls -a
CONTAINER ID        IMAGE               COMMAND             CREATED             STATUS                    PORTS               NAMES
7691a814370e        ubuntu:14.04        "/bin/bash"         36 hours ago        Exited (0) 21 hours ago                       test
$ docker export 7691a814370e > ubuntu.tar
```
导入容器
```
$ cat ubuntu.tar | docker import - test/ubuntu:v1.0
$ docker image ls
REPOSITORY          TAG                 IMAGE ID            CREATED              VIRTUAL SIZE
test/ubuntu         v1.0                9d37a6082e97        About a minute ago   171.3 MB
```
使用制定URL或者某个目录来导入
```
$ docker import http://example.com/exampleimage.tgz example/imagerepo
```
注：用户既可以使用 docker load 来导入镜像存储文件到本地镜像库，也可以使用 docker import 来导入一个容器快照到本地镜像库。这两者的区别在于容器快照文件将丢弃所有的历史记录和元数据信息（即仅保存容器当时的快照状态），而镜像存储文件将保存完整记录，体积也要大。此外，从容器快照文件导入时可以重新指定标签等元数据信息。
***

### 删除容器
删除一个终止状态的容器
```
docker container rm
```
清理所有终止状态的容器
```
docker container prune
```
