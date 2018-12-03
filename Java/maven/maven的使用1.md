### maven目录结构
```
src
    -main
        -java
            -package
    -test
        -java
            -package
    resources //用来存放资源文件
```

### mvn 常用命令
```
mvn -v //查看maven版本
    compile //编译
    test // 测试
    package // 打包
    clean // 删除target
    install 安装jar包到本地仓库中
```

### 1 用IDEA创建MAVEN工程,创建之后的pom.xml文件如下:
```
<?xml version="1.0" encoding="UTF-8"?>

<project xmlns="http://maven.apache.org/POM/4.0.0"
         xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>
    <groupId>dai.maven.test</groupId>
    <artifactId>manventest</artifactId>
    <version>1.0-SNAPSHOT</version>

</project>
```
pom.xml常用标签解释:

+ groupId定义了项目属于哪个组，这个组往往和项目所在的组织或公司存在关联。譬如在googlecode上建立了一个名为myapp的项目，那么groupId就应该是com.googlecode.myapp，如果你的公司是mycom，有一个项目为myapp，那么groupId就应该是 com.mycom.myapp。

+ artifactId定义了当前Maven项目在组中唯一的ID，我们为这个maventest项目定义artifactId为maventest.

+ version指定了maventest项目当前的版本

+ packaging指的是打包的方式,不指定默认的是jar
+ name 项目描述名
+ url 项目地址

### 2 编写主代码
```
package dai.maven.test;

public class maventest {
    public String sayHello(){
        return "Hello Maven";
    }

    public static void main(String[] args) {
        System.out.print(new maventest().sayHello());
    }
}
```

### 3 使用maven进行编译
运行命令:
```
mvn clean compile
```

+ clean告诉Maven清理输出目录target/，compile告诉Maven编译项目主代码

+ 从输出中看到Maven首先执行了clean:clean任务，删除target/目录。默认情况下，Maven构建的所有输出都在target/目录中;

+ 接着执行resources:resources任务(未定义项目资源，暂且 略过);

+ 最后执行compiler:compile任务，将项目主代码编译至target/classes目录(编译好的类为 com/juvenxu/mvnbook/helloworld/HelloWorld.Class)。

### 4 编写测试代码

在idea中执行`alt + n`命令来添加依赖

pom代码中就添加了如下代码:
```
<dependencies>
    <dependency>
        <groupId>junit</groupId>
        <artifactId>junit</artifactId>
        <version>4.7</version>
        <scope>test</scope>
    </dependency>
</dependencies>
```

+ 这里添加了一个依赖——groupId 是junit，artifactId是junit，version是4.7

+ 前面提到groupId、artifactId和version是任何一个Maven项目最基本的坐标，JUnit也不例外， 有了这段声明，Maven就能够自动下载junit-4.7.jar。

+ 上述POM代码中还有¡一个值为test的元素scope，scope为依赖范围，若依赖范围为test则表示该依赖只对测试有效。换句话说，测试代码中的import JUnit代码是没有问题的，但是如果在主代码中用import JUnit代码，就会造成编译错误。如果不声明依赖范围，那么默认值就是compile，表示该依赖对主代码和测试代码都有效。
+ optional 设置依赖是否可选,默认是false 
+ exclusions 排除依赖的列表
+ depencyManagenment 依赖管理,主要用在父模块中,供子模块使用
+ build 对构件行为提供相应的支持经常在里面会看到
    + plugins 插件列表
+ parent 通常用于子模块对于父模块的继承
+ modules 运行多个maven项目

### 5 添加maven的编译插件
```
<build>
    <finalName>XXX</finalName>
    <plugins>
    	<plugin>
    		<!-- https://mvnrepository.com/artifact/org.apache.maven.plugins/maven-compiler-plugin -->
   			<groupId>org.apache.maven.plugins</groupId>
   			<artifactId>maven-compiler-plugin</artifactId>
   			<version>3.7.0</version>
   			<configuration>
   				<source>1.8</source>
   				<target>1.8</target>
   				<encoding>UTF8</encoding>
   			</configuration>
	    </plugin>
    </plugins>
  </build>
```
这样不会出现编译警告

### 6 打包和运行
使用如下命令进行打包:
```
mvn clean package
```
打包之后就生成了`maventest-1.0-SNAPSHOT.jar`

如果想要其它的Maven项目执行这个jar,就必须
```
mvn clean install
```

### 7 运行测试命令
对test文件进行测试执行命令
```
mvn test
```