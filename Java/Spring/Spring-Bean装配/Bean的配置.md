## Spring容器的高层视图
要使应用程序中的Spring容器成功启动，需要同时具备一下三方面的条件：
* Spring框架的类包都已经放到应用程序的类路径下；
* 应用程序为Spring提供了完备的Bean配置信息；
* Bean的类都已经放到应用程序的类路径下
Spring启动时应用程序提供bean的配置信息，并在Spring容器中生成一份相应的Bean配置注册表，然后根据这张注册表实例化Bean，装配好Bean之间的依赖关系，为上层应用提供就绪的运行环境。  

Bean配置信息是Bean的元数据信息，它由一下4个方面组成：
* Bean的实现类。
* Bean的属性信息，如数据源的连接数、用户名、密码等。
* Bean的依赖关系，Speing根据依赖关系配置完成Bean之间的装配。
* Bean的行为配置，如生命周期范围及声明周期各过程的回调函数等。
Bean元数据信息在Speing容器中的内部对应物是由一个个BeanDefinition形成的Bean注册表，Bean的注册注册方式有`XML <bean>`，`Groovry beans`,`Java类@Configuration`.`注解@Autowired`。XML形式是最基本、最传统的。

## Bean的基本配置
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="
    http://www.springframework.org/schema/beans
    http://www.springframework.org/schema/beans/spring-beans-4.0.xsd
    "
    <bean id="car" class="com.smart.simple.Car">
    <bean id="boss" class="com.smart.simple.Boss">
```

## Bean的配置项
* Id: bean的唯一标识
* class：具体要实例化的类
* Scope：作用域
* Constructor arguments：构造器的参数
* Properties：其它属性，重要的两种方式：一种是构造器注入和设值注入
* Autowiring mode： 自动装配模式
* lazy-initialization mode： 懒加载模式
* Initialization/destruction method： 初始化和销毁方法

## Bean的作用域Scope
* singleton: 单例，指一个bean容易只存在一份
* prototype: 原型模式，每次通过容器的getBean方法获取prototype定义的Bean时，都将产生一个新的Bean实例
* session：对于每次HTTP Session，使用session定义的Bean产生一个新实例。同样只有在Web应用中使用Spring时，该作用域才有效
* globalsession：每个全局的HTTP Session，使用session定义的Bean都将产生一个新实例。典型情况下，仅在使用portlet context的时候有效(portlet 定义了globalsession)。同样只有在Web应用中使用Spring时，该作用域才有效