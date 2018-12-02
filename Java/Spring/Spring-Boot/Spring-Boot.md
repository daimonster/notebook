## 概述
Spring-boot是用最小的配置快速跑起spring应用

## 使用
* Spring tool suite-->eclipse
* idea

### idea 创建过程
1. new project 左边的选项卡选择spring Initializr jdk选择1.8
2. 填写groupId和ArtifactId这两个选项：  
    groupId： 决定了src/java和test/java文件夹中包的存放地址  
    ArtifactId： 决定了工程名称以及存放工程的文件夹（存放地址即为当前文件夹/$ArtifactId）
3. web选web sql选mybatis 最上中间springboot版本选择(默认)
4. 再次确认项目位置，finish

## pom简介
### spring-boot-starter-parent
* 引用管理的功能
* 识别application properties：识别线上和线下的配置

## application properti
* server.port // 注册端口
* server.servlet.context-path=/demo // 注册访问路径

## 注解
### RestController
* 就是Controller和ResponseBody