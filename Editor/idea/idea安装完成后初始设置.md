## idea的JVM参数设置
在`D:\Program Files\IntelliJ IDEA 2017.2.7\bin`文件夹里面，两个 vmoptions 文件，需针对不同的JDK进行配置：

32 位：idea.exe.vmoptions  
64 位：idea64.exe.vmoptions  

```
-Xms512m
-Xmx1024m
-XX:MaxPermSize=512m
-XX:ReservedCodeCacheSize=256m
-XX:+UseConcMarkSweepGC
-XX:SoftRefLRUPolicyMSPerMB=50
-ea
-Dsun.io.useCanonCaches=false
-Djava.net.preferIPv4Stack=true
-XX:+HeapDumpOnOutOfMemoryError
-XX:-OmitStackTraceInFastThrow
```

这是默认的idea64.exe.vmoptions参数设置，有需要修改

## 设置idea的编码格式
通过file->setting->Editor->File Encodings,一共由三处设置   
* IDE Encoding:UTF-8
* Project Encoding
* Default encodeing properties files:UTF-8   
有的idea的编码设置默认设置是GBK，如果不设置的话会出现错误

## maven设置
通过setting->Build,Executing,Deployment->Build Tools->Maven里面
* Maven home directory:设置本地的maven地址
* User setting file: 设置用户设置文件
* Local repository: 设置本地仓库
* 在左侧importing选项卡里面把Automatically download中的Sources和Document选项悬赏
* 在左侧runner中添加"-Xms512m -Xmx1024m"

