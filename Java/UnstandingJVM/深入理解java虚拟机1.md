## 运行的数据区域
Java虚拟机管理的内存将会包括一下几个运行时的数据区域,如图所示:

![数据区](../images/592290-20170604223752930-353921057.png)

### 程序计数器

程序计数器是一块较小的内存空间,它可以看做是当前线程所执行的字节码的行号指示器.

### Java虚拟机栈

Java虚拟机栈也是线程私有的,它的生命周期与线程相同.