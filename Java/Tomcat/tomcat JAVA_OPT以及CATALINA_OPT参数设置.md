## JAVA内存模型
* **Young，年轻代（易被 GC）**。Young 区被划分为三部分，Eden 区和两个大小严格相同的 Survivor 区，其中 Survivor 区间中，某一时刻只有其中一个是被使用的，另外一个留做垃圾收集时复制对象用，在 Young 区间变满的时候，minor GC 就会将存活的对象移到空闲的Survivor 区间中，根据 JVM 的策略，在经过几次垃圾收集后，任然存活于 Survivor 的对象将被移动到 Tenured 区间。

* **Tenured，终身代**。Tenured 区主要保存生命周期长的对象，一般是一些老的对象，当一些对象在 Young 复制转移一定的次数以后，对象就会被转移到 Tenured 区，一般如果系统中用了 application 级别的缓存，缓存中的对象往往会被转移到这一区间。

* **Perm，永久代**。主要保存 class,method,filed 对象，这部门的空间一般不会溢出，除非一次性加载了很多的类，不过在涉及到热部署的应用服务器的时候，有时候会遇到 java.lang.OutOfMemoryError : PermGen space 的错误，造成这个错误的很大原因就有可能是每次都重新部署，但是重新部署后，类的 class 没有被卸载掉，这样就造成了大量的 class 对象保存在了 perm 中，这种情况下，一般重新启动应用服务器可以解决问题。

## JAVA_OPT以及CATALINA_OPT的区别与联系
这是在配置的时候我一直在关注的问题  
相同点：都是用来设置 JVM 相关运行参数的变量  
区别：  

* JAVA_OPTS：用于当 Java 运行时选项“start”、“stop”或“run”命令执行。  
* CATALINA_OPTS：用于当 Java 运行时选项“start”或“run”命令执行。  

首先，在启动 Tomcat 时，任何指定变量的传递方式都是相同的，可以传递到执行“start”或“run”命令中，但只有设定在 JAVA_OPTS 变量里的参数被传递到“stop”命令中。对于 Tomcat 运行过程，可能没什么区别，影响的是结束程序，而不是启动程序。 

第二个区别是更微妙，其他应用程序也可以使用 JAVA_OPTS 变量，但只有在 Tomcat 中使用 CATALINA_OPTS 变量。如果你设置环境变量为只使用 Tomcat，最好你会建议使用 CATALINA_OPTS 变量，而如果你设置环境变量使用其它的 Java 应用程序，例如 JBoss，你应该把你的设置放在JAVA_OPTS 变量中。  

## JVM参数及解释
```
CATALINA_OPTS="
-Dfile.encoding=UTF-8 #文件编码设置
-server #表示这是应用于服务器的设置
-Xms6000m #启动JVM时的初始堆大小。此值可以设置与-Xmx相同，以避免每次垃圾回收完成后JVM重新分配内存。 
-Xmx6000M 
-Xss512k 
-XX:NewSize=2250M #设置年轻代大小
-XX:MaxNewSize=2250M #设置最大的年轻代大小
-XX:PermSize=128M #设置永久代大小 永久带存放固定的class和method
-XX:MaxPermSize=256M #设置最大永久代大小
-XX:NewRatio=4 #设置年轻代（包括 Eden 和两个 Survivor 区）与终身代的比值（除去永久代）。设置为 4，则年轻代与终身代所占比值为 1：4，年轻代占整个堆栈的 1/5
-XX:+AggressiveOpts 
-XX:+UseBiasedLocking 
-XX:+DisableExplicitGC #这个将会忽略手动调用 GC 的代码使得 System.gc() 的调用就会变成一个空调用，完全不会触发任何 GC
-XX:+UseParNewGC 
-XX:+UseConcMarkSweepGC 
-XX:MaxTenuringThreshold=31 #设置垃圾最大年龄，默认为：15。如果设置为 0 的话，则年轻代对象不经过 Survivor 区，直接进入年老代。对于年老代比较多的应用，可以提高效率。如果将此值设置为一个较大值，则年轻代对象会在 Survivor 区进行多次复制，这样可以增加对象再年轻代的存活时间，增加在年轻代即被回收的概论。
-XX:+CMSParallelRemarkEnabled 
-XX:+UseCMSCompactAtFullCollection 
-XX:LargePageSizeInBytes=128m 
-XX:+UseFastAccessorMethods 
-XX:+UseCMSInitiatingOccupancyOnly
-Duser.timezone=Asia/Shanghai 
-Djava.awt.headless=true"
```

我自己的tomcat服务器设置（2G1核服务器设置）
```
CATALINA_OPTS="
-Dfile.encoding=UTF-8
-server
-Xms1024m
-Xmx1024m
-XX:PermSize=256m
-XX:MaxPermSize=256m
-XX:MaxTenuringThreshold=10
-XX:+DisableExplicitGC
```
