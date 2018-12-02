1. idea界面的远程配置
    这两部不算很难，只要按照截图设置就行。
    ![idea远程界面设置](http://118.126.64.234:3000/daimonster/NoteBook/raw/master/images/idea_remote_setting1.png)
    ![idea远程界面设置](http://118.126.64.234:3000/daimonster/NoteBook/raw/1c95c2899216a737858981e2405a2019190827b7/images/idea_remote_setting2.png)

4. 在bin文件夹里面catelina.sh在文件开始添加
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

5. 启动tomcat，这个时候必须要用catelina.
    ```  
    sudo catalina.sh run > /dev/null 2>&1 &
    ```
    关闭就是
    ```  
    sudo catalina.sh stop
    ```

