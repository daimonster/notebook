### archtype插件

作用:用于创建符合maven规定的目录骨架
之后就是按照使用1步骤填写groupId,artifactId

### 生成骨架命令
有两种方式,第一种:
```
mvn archtype:generate
```

第二种:
```
mvn archetype:generate -DgroupId=com.imooc.maven04 -DartifactId=maven04-demo -Dversion=1.0.0SNAPSHOT -Dpackage=com.imooc.maven04-demo
```

### maven的坐标和仓库
+ 坐标:构件通过坐标作为其唯一的标识

+ 仓库:分为两种,本地仓库和远程仓库

+ 镜像仓库:由于墙的原因,我们这里访问镜像仓库,可以加快下载的速度

在maven的安装文件里面(用命令`mvn -v`就可以查看安装地址),进入到conf文件夹,
里面编辑settings.xml,找到<mirrors>标签,将镜像仓库的地址添加进去

这里写一个阿里云的中央仓库
```
<mirrors>
    <mirror>
        <id>alimaven</id>
        <name>aliyun maven</name>
        <url>http://maven.aliyun.com/nexus/content/groups/public/</url>
        <mirrorOf>central</mirrorOf>
    </mirror>
</mirrors>
```

+ 更改本地仓库的位置
maven默认的仓库地址是存在.2地址里面的,如果想要修改还是在上面的settings.xml,找到<localRepository>标签,在里面添加

```
<localRepository>/path/to/repo</localRepository>// 里面添加的是你想要更改的仓库地址
```

### maven的生命周期和插件
完整的项目构件过程包括:

清理,编译,测试,打包,集成测试,验证,部署

maven的生命周期: 

clean(清理项目),default(构建项目,compile,test,package,install),site(生成项目站点)



