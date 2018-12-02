## Spring 首页设置的问题
工程的首页设置，我试了很多次一直没有找到正确的路径，后来将其放在了webapp下面就能正确显示了：  
附上首页文件内容：  
```
<!DOCTYPE html>
<html>
<script>
    window.location.href = '/o2o/local/login';
</script>
</html>
```

## 遇到数据库无法读取的问题
* 检查了很多文件，解决方案是在jdbc.properties每行的属性前面加上jdbc.
* 还有经常连接不上的问题是因为连接池c3p0的版本太低了，导致连接出错  

***
## 配置mybatis是遇到的问题
### 出现org.apache.ibatis.builder.IncompleteElementException: Could not find result map
这是因为在mxl里面设置的返回值我写的是*resultMap* 正确的是*resultType* resultType是在自身的xml文件里面设置的  

***
## 当运行spring-boot的时候无法正常启动
* 这是在pom中tomcat的配置scope：provided出现了问题，目前的解决办法是注释掉    

***
## 配置logback出现的问题
### SpringBoot与LogBack创建LOG_PATH_IS_UNDEFINED文件夹
* 可猜测出 catalina.home 这个属性 没有被定义。
在logback.xml中设置属性前判断是否被定义
```
<?xml version="1.0" encoding="UTF-8"?>
<configuration>
 
    <if condition='isDefined("catalina.home")'>
        <then>
            <property name="log.folder" value="${catalina.home}/logs"/>
        </then>
        <else>
            <property name="log.folder" value="./target/logs"/>
        </else>
    </if>
 
    <appender name="companyMyAppServiceAppender" class="ch.qos.logback.core.FileAppender">
        <file>${log.folder}/company.myApp.log</file>
        ...
    </appender>
 
    ...
 
</configuration>
```

同时需要添加依赖
```
<dependency>
    <groupId>org.codehaus.janino</groupId>
    <artifactId>janino</artifactId>
    <version>3.0.8</version>
</dependency>
```
***
## 运行jstl出现"java.lang.NoClassDefFoundError: javax/servlet/jsp/jstl/core/Config" 错误
添加两个依赖jstl-api和jstl-impl  
```
<!-- jstl -->
<dependency>
    <groupId>javax.servlet.jsp.jstl</groupId>
    <artifactId>jstl</artifactId>
    <version>1.2</version>
</dependency>
<!-- jstl-api -->
<dependency>
    <groupId>javax.servlet.jsp.jstl</groupId>
    <artifactId>jstl-api</artifactId>
    <version>1.2</version>
</dependency>
<!-- jstl-impl -->
<dependency>
    <groupId>org.glassfish.web</groupId>
    <artifactId>jstl-impl</artifactId>
    <version>1.2</version>
</dependency>
```
