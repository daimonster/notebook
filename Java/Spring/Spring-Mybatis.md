## 类和名称的映射
* 别名：com.imooc.seckill --> seckill 使用 package scan
* 配置实现：<mapper resource="mapper/SeckillDao.xml"/> 等等 --> 自动扫描配置文件
* dao实现: mapper 自动实现DAO接口，自动注入spring容器

## 创建mybatis-conf.xml文件
```
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <!--配置全局属性-->
    <settings>
        <!--使用jdbc的getGeneratedKeys获取数据库自增主键值-->
        <setting name="useGeneratedKeys" value="true"/>
        <!--使用列别名替换列名-->
        <setting name="useColumnLabel" value="true"/>
        <!--开启驼峰命名转换-->
        <setting name="mapUnderscoreToCamelCase" value="true"/>
    </settings>
</configuration>
```

## 在spring文件夹里面创建jdbc.properties
```
jdbc.driver=com.mysql.jdbc.Driver
jdbc.url=jdbc:mysql://118.126.64.234:10023/test?useUnicode=true&characterEncoding=utf8
jdbc.username=****
jdbc.password=****
```