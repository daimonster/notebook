1. 创建一个tomcat用户来专门管理web服务
    ```
    sudo adduser tomcat
    //如果需要给git来添加sudo权限的话,不建议使用root权限，因为很容易被人扫描利用
    sudo usermod -G sudo tomcat
    ```
    
1. 首先解压文件之后移动到opt目录下，注意在默认目录下解压，这样文件的权限不会是root
    ```
    // 文件在Downloads文件夹下面
    sudo tar zxvf apache-tomcat-8.5.16.tar.gz && mv ** /opt/tomcat
    ```

2. 设置变量，在bin文件中的setclasspath.sh文件中在前面添加
    ```
    export JAVA_HOME=/opt/Java/jdk1.8.0_171
    export JRE_HOME=${JAVA_HOME}/jre
    ```

3. 设置conf文件夹中的server.xml文件  
   ~~将监听端口由8080改成80~~  
   在<host>标签的最后一行添加
   ```
   <Context docBase="/home/ubuntu/Pictures/upload" path="/upload"/>
   ```

4. 在bin文件夹里面catelina.sh在文件开始添加
   ```
    CATALINA_HOME=/home/ubuntu/Library/tomcat/apache-tomcat-8.5.31
    CLASSPATH=.:$JAVA_HOME/lib:$CATALINA_HOME/lib
    CATALINA_OPTS="
    -Dfile.encoding=UTF-8
    -server
    -Xms1024m
    -Xmx1024m
    -XX:PermSize=256m
    -XX:MaxPermSize=256m
    -XX:MaxTenuringThreshold=10
    -XX:+DisableExplicitGC
    -Dcom.sun.management.jmxremote 
    -Dcom.sun.management.jmxremote.port=1099
    -Dcom.sun.management.jmxremote.rmi.port=1099
    -Dcom.sun.management.jmxremote.ssl=false 
    -Dcom.sun.management.jmxremote.authenticate=false 
    -Djava.rmi.server.hostname=118.126.64.234"

    #CATALINA_OPTS="$CATALINA_OPTS -server -Xms256m -Xms512m"
    CATALINA_OPTS="$CATALINA_OPTS -Xdebug -Xrunjdwp:transport=dt_socket,server=y,suspend=n,address=5005"
    export CATALINA_OPTS
   ```
   要注意JAVA_OPTS这个参数一定要添加，否则会出现
   ```
    Error running 'TomcatRemote': 
    Unable to connect to the xx.xx.xx.xx:1099, 
    reason:
    java.rmi.ConnectException: Connection refused to host: xx.xx.xx.xx; 
    nested exception is: java.net.ConnectException: Connection timed out: connect
   ```
   错误，表明jmx没有成功启动

4. 删除webapp里面的文件  
   通过html来管理tomcat是非常危险的，所以建议删除manager和host-manager以及admin文件夹（或者放到别的文件夹保存）

5. 启动tomcat，这个时候必须要用catelina.
    ```  
    ~~sudo catalina.sh run > /dev/null 2>&1 &~~
    #不要用root权限，否则会有安全问题
    nohup /home/tomcat/tomcat/apache-tomcat-8.5.31/bin/catalina.sh run > /dev/null 2>&1 &
    ```
    关闭就是
    ```  
    sudo catalina.sh stop
    ```

## 其他
### 设置开机启动
其实这是非常不建议的，因为开机启动catalina.sh会使用root权限，导致安全问题  
但是由于我之前设置了，所以我在这里写一下，方便我改回去  
```
vi /etc/rc.d/rc.local #修改文件

export JAVA_HOME=/usr/java/jdk1.7.0_60
/usr/local/tomcat/bin/startup.sh start # 在文件的最后添加这两行
chmod +x  rc.local #将rc.local变成可执行
```

    
