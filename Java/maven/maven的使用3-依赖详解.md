## 依赖范围
+ <scope> 控制依赖与3中classpath的关系
    scope 的值一个是六种,分别是:
    + compile 默认的范围,编译测试运行都有效
    + provided 测试和编译的时候有效
    + runtime 在测试和运行时有效
    + test 只会在测试范围有效¡¡
    + system 测试和编译的时候有效,与本机系统相关联,可移植性差,比如java_home,一直到其它机器上就会产生错误
    + import 导入的范围,它只是用在dependencyManagement中,表示从其它的pom中导入dependecy的配置

## 依赖传递
```
在依赖里面
```

## 依赖冲突

1. 短路优先
1. 路径相同,先声明先优先

## 聚合和继承
聚合
```
<package>pom</package>
...
<modules>
    <module>../hongxing-bge</module>
    <module>../hongxing-nange</module>
    <module>../hongxing-shanji</module>
</modules>
```
继承
```
<dependencyManagement>
    dependencies>
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.11</version>
            <scope>test</scope>
        </dependency>
    </dependencies>
</dependencyMangement>

//在子pom.xml添加
<parent>
    父pom的坐标
</parent>
```

## 建立web项目
使用Archetype-webapp建立maven项目¡