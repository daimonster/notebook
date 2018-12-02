## ubuntu下apt安装
```
sudo apt install maven
```

## 下载Maven

1. 打开Maven官网下载页面：http://maven.apache.org/download.cgi
下载:apache-maven-3.5.0-bin.tar.gz

1. 解压下载的安装包到某一目录，比如：/Users/yuanweipeng/Documents/maven

## 配置环境变量

打开terminel输入以下命令：
```
vi ~/.zshrc
```

在次文件中添加设置环境变量的命令:
```
export M2_HOME=/Users/yuanweipeng/Documents/maven/apache-maven-3.5.0
export PATH=$PATH:$M2_HOME/bin
```

添加之后保存并推出，执行以下命令使配置生效：
```
source ~/.zshrc
```

## maven设置


### settings文件的路径
settings.xml的默认路径就：个人目录/.m2/settings.xml
如：
**windowns**: C:\Users\你的用户名\.m2\settings.xml
**linux**: /home/你的用户名/.m2/settings.xml

### 镜像仓库
由于墙的原因，所以设置国内镜像仓库
选择setting.xml中大概在145行<mirrors>标签里面，添加
```
<mirror>
    <id>alimaven</id>
    <name>aliyun maven</name>
    <url>http://maven.aliyun.com/nexus/content/groups/public/</url>
    <mirrorOf>central</mirrorOf>
</mirror>
```
这是阿里云的仓库
```
<mirror>
    <id>maven.net.cn</id>
    <mirrorOf>central<mirrorOf>
    <name>central mirror in China</name>
    <url>http://maven.net.cn/nexus/content/groups/public/</url>
    <mirrorOf>central</mirrorOf>
</mirror>
```
### 修改存放地址
默认存放地址：C:\Users\Administrator\.m2\repository 里面
仍然是settings,大概在53行
```
<localRepository>D:\maven-jars</localRepository>
```
然后将settings文件复制到maven-jars文件夹里面

## 查看配置是否生效

输入：mvn -v命令，输出如下：
```
Apache Maven 3.5.0 (ff8f5e7444045639af65f6095c62210b5713f426; 2017-04-04T03:39:06+08:00)
Maven home: /Users/yuanweipeng/Documents/maven/apache-maven-3.5.0
Java version: 1.8.0_121, vendor: Oracle Corporation
Java home: /Library/Java/JavaVirtualMachines/jdk1.8.0_121.jdk/Contents/Home/jre
Default locale: zh_CN, platform encoding: UTF-8
OS name: "mac os x", version: "10.12.6", arch: "x86_64", family: "mac"
```

则配置成功。