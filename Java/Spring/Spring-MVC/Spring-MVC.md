# MVC
## 概述
Spring MVC框架围绕DispatcherServlet这个核心展开，DispatcherServlet是Spring MVC的总导演，总策划，它能负责截获请求并将其分派给相应的处理器处理。SpringMVC框架包括注解驱动控制器、请求及相应处理、视图解析、本地化解析、上传文件解析、异常处理及表单标签绑定等内容。

## Front Controller
Front Controller (Dispatcher) 分发请求

## Controller
操作业务细节（Handle Request-->Create Model）

## View template
为用户提供UI，重点关注数据的呈现

## Model
业务数据的信息表示，关注支撑业务信息的构成，通常是多个业务实体的组合。

## MVC本质（Model-View-Controller）
MVC的核心思想是业务数据抽取与业务数据呈现相分离


## Restful（Representational State Transfer）
* 组成由Resources,Reprentation,state transfer，优雅的url表达方式，表示资源的状态和状态的转移
* Resource 表示的资源：就是网络上的一个信息实体
* Representation 表现层：我们把资源具体呈现出来的形式，就叫做表现层。比如文本、HTML、JSON等
* State Transfer 状态转化：访问一个网站，就代表了客户端和服务器的一个互动过程。在这个过程中，势必涉及到数据和状态的变化。  
具体来说，就是HTTP协议里面，四个表示操作方式的动词：GET、POST、PUT、DELETE。它们分别对应四种基本操作：GET用来获取资源，POST用来新建资源（也可以用于更新资源），PUT用来更新资源，DELETE用来删除资源。
* URL设计： 
在url中不应该用动词  
/模块/资源/｛标识｝/集合1/...
/user/{uid}/friends -> 好友列表
/user/{uid}/followers -> 关注列表
* GET：查询操作
* POST：添加、修改操作
* PUT：修改操作
* DELETE： 删除操作

## 围绕handler开发
![spring运行过程图例](http://118.126.64.234:10022/daimonster/Images/raw/1b1609cc1191508bfa21d78c7578892c6f825ae0/spring/spring%E8%BF%90%E8%A1%8C%E8%BF%87%E7%A8%8B.png)

这里将DispatcherServerlet简称为DS  
1. 用户将请求发送给DS
2. 映射url，将每个url对应到每个具体的handler，查找负责处理该请求处理器
3. DS将请求分发给适配器
3. 适配器将请求发给对应代码的controller处理
3. 返回ModelAndView对象,MAV对象包含视图逻辑名和模型数据信息
3. MAV中包含的是逻辑视图名而非真正的视图对象，在这一步完成逻辑视图名到真实视图对象的解析工作
3. 当得到真实视图对象的时候，DS就使用这个View对象对MAV中的模型数据进行渲染。
3. 返回给用户

## Http请求映射原理
![Http请求映射](http://118.126.64.234:10022/daimonster/Images/raw/master/spring/Http%E8%AF%B7%E6%B1%82%E6%98%A0%E5%B0%84%E5%8E%9F%E7%90%86.png)
* 注解映射技巧：
    1. 支持标准风格的url
    2. ant风格的url(即?和*和**等字符)
    3. 带{xxx}占位符的url
* 例子：  
    * user/*/creation: 可以匹配user/aaa/creation,user/aafw/creation等
    * user/**/creation: 可以匹配user/creation,user/aafw/bbb/creation等
    * user/{userId}: 匹配user/123,user/abc等URL

## 请求方法细节处理
![code exam](http://118.126.64.234:10022/daimonster/Images/raw/master/spring/http-mvc%E4%BB%A3%E7%A0%81%E4%BE%8B%E5%AD%90.png)
### 请求参数绑定
蓝色，url占位符的匹配，通过@PathVarivable来绑定url和方法中的参数
### 请求方式限制
绿色，去请求方法去限制
### 请求转发和重定向
红色，用来限定请求的重定向还是请求的转发 
### 数据模型和复制
黄色，用来承载返回给用户的数据 

![return json data](http://118.126.64.234:10022/daimonster/Images/raw/master/spring/%E8%BF%94%E5%9B%9Ejson%E6%95%B0%E6%8D%AE.png)
### 返回json值
* produces 限定json文件格式
* 将放回数据转换成json文件

![cookie request](http://118.126.64.234:10022/daimonster/Images/raw/master/spring/%E8%BF%94%E5%9B%9Ejson%E6%95%B0%E6%8D%AE.png)
### cookie访问
* required = false 不强制传入对应的cookie
