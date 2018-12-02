## IOC和DI

### 概念

IOC:控制翻转(inverse of control).意思就是控制反转了,将对在自身对象中的一个内置对象的控制反转,反转之后不再由自己本身的对象进行控制这个内置对象的创建,而是由第三方系统去控制这个内置对象的创建.

DI:依赖注入(Dependency Injection),意思是自身对象中的内置对象是通过注入的方式进行创建的.

两者的关系:IOC就是一种软件设计思想,DI是这种软件设计思想的一个实现.而Spring中的核心机制就是DI.

好处就是耦合性降低,灵活装配

### Bean容器的初始化
+ 基础: 两个包
    + org.springframework.beans
        BeanFactory 提供配置结构和基本功能,加载并初始化Bean
    + prg.springframework.context
        ApplicationContext保存了Bean对象并在Spring中被广泛使用

### Spring注入
Spring注入是指在启动Spring容器加载bean配置(xml文件等)的时候,完成对变量的赋值行为

常用的两种注入方式:
+ 设值注入
+ 构造注入


