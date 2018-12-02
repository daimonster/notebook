## 简介
`Compose` 项目是 Docker 官方的开源项目，负责实现对 Docker 容器集群的快速编排。从功能上看，跟 OpenStack 中的 Heat 十分类似。

Compose 中有两个重要的概念：

+ 服务 (service)：一个应用的容器，实际上可以包括若干运行相同镜像的容器实例。
+ 项目 (project)：由一组关联的应用容器组成的一个完整业务单元，在 docker-compose.yml 文件中定义。

***

## 安装

mac、windows安装完docker之后可直接使用
```
$ docker-compose --version
docker-compose version 1.17.1, build 6d101fb
```

### linux安装

直接二进制安装
```
$ sudo curl -L https://github.com/docker/compose/releases/download/1.17.1/docker-compose-`uname -s`-`uname -m` > /usr/local/bin/docker-compose
$ sudo chmod +x /usr/local/bin/docker-compose
```
