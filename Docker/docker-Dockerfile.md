## 简介

Dockerfile 是一个文本文件，其内包含了一条条的指令(Instruction)，每一条指令构建一层，因此每一条指令的内容，就是描述该层应当如何构建。

***

## FROM制定基础镜像

FROM 就是指定基础镜像，因此一个 Dockerfile 中 FROM 是必备的指令，并且必须是第一条指令。

例如
```
FROM nginx
FROM php
```
等等，还有一种特殊镜像，名为 scratch。这个镜像是虚拟的概念，并不实际存在，它表示一个空白的镜像。
```
FROM scratch
...
```

如果你以 scratch 为基础镜像的话，意味着你不以任何镜像为基础，接下来所写的指令将作为镜像第一层开始存在。
***

## RUN 执行命令

RUN 指令是用来执行命令行命令的。其格式有两种：

+ shell 格式：RUN <命令>，就像直接在命令行中输入的命令一样。
    ```
    RUN echo '<h1>Hello, Docker!</h1>' > /usr/share/nginx/html/index.html
    ```
+ exec 格式：RUN ["可执行文件", "参数1", "参数2"]，这更像是函数调用中的格式。

正确的Docker写法
```
FROM debian:jessie

RUN buildDeps='gcc libc6-dev make' \
    && apt-get update \
    && apt-get install -y $buildDeps \
    && wget -O redis.tar.gz "http://download.redis.io/releases/redis-3.2.5.tar.gz" \
    && mkdir -p /usr/src/redis \
    && tar -xzf redis.tar.gz -C /usr/src/redis --strip-components=1 \
    && make -C /usr/src/redis \
    && make -C /usr/src/redis install \
    && rm -rf /var/lib/apt/lists/* \
    && rm redis.tar.gz \
    && rm -r /usr/src/redis \
    && apt-get purge -y --auto-remove $buildDeps
```
***
## 构建镜像
构建镜像的命令为
```
docker build [选项] <上下文路径/URL/->
```
范例
```
docker build -t nginx:v3 . #注意要加上"."表示上下文路径
```
***

## 镜像上下文
docker bulid 命令最后的一个`.` 刚开始会认为是当前目录,其实不是,这其实指的是上下文路径.

当构建的时候，用户会指定构建镜像上下文的路径，docker build 命令得知这个路径后，会将路径下的所有内容打包，然后上传给 Docker 引擎。这样 Docker 引擎收到这个上下文包后，展开就会获得构建镜像所需的一切文件。

例如,Dcokerfile这么写:
```
COPY ./package.json /app/
```

这并不是要复制执行 docker build 命令所在的目录下的 package.json，也不是复制 Dockerfile 所在目录下的 package.json，而是复制 上下文（context） 目录下的 package.json。

## COPY 复制文件
格式:
+ COPY <源路径>... <目标路径>
+ COPY ["<源路径1>",... "<目标路径>"]

COPY 指令将从构建上下文目录中 <源路径> 的文件/目录复制到新的一层的镜像内的 <目标路径> 位置。比如：
```
COPY package.json /usr/src/app/
```

## ADD更高级的复制文件
ADD 指令和 COPY 的格式和性质基本一致。但是在 COPY 基础上增加了一些功能。

如果 <源路径> 为一个 tar 压缩文件的话，压缩格式为 gzip, bzip2 以及 xz 的情况下，ADD 指令将会自动解压缩这个压缩文件到 <目标路径> 去。

官方文档要求尽量使用COPY，ADD包含了更复杂的功能，行为不一定很清晰。

只在需要自动解压缩的场合使用ADD。

## CMD容器启动命令

Docker 不是虚拟机，容器就是进程。既然是进程，那么在启动容器的时候，需要指定所运行的程序及参数。CMD 指令就是用于指定默认的容器主进程的启动命令的。

CMD 指令的格式和 RUN 相似，也是两种格式：

+ shell 格式：CMD <命令>
+ exec 格式：CMD ["可执行文件", "参数1", "参数2"...]
+ 参数列表格式：CMD ["参数1", "参数2"...]。在指定了 ENTRYPOINT 指令后，用 CMD 指定具体的参数。

## ENTRYPOINT入口点
