## 用户权限
```
manager-gui     #允许访问html接口(即URL路径为/manager/html/*)
manager-script   #允许访问纯文本接口(即URL路径为/manager/text/*)
manager-jmx   #允许访问JMX代理接口(即URL路径为/manager/jmxproxy/*)
manager-status   #允许访问Tomcat只读状态页面(即URL路径为/manager/status/*)
```
<user username="用户名" password="密码" roles="角色（可多个）"/>这个很简单，就是用来表示用户的，其中roles对应的就是上面定义的角色，可以有多个角色，多个角色用“，”隔开即可。也可以配置多个用户。  
## 用户设置
1. 如果想要进入/manager/html页面，则新建或编辑conf/Catalina/localhost/manager.xml
    添加如下内容  
    ```
    <?xml version="1.0" encoding="UTF-8"?>
    <Context privileged="true" antiResourceLocking="false"
        docBase="${catalina.home}/webapps/manager">
    <Valve className="org.apache.catalina.valves.RemoteAddrValve" allow="^.*$" />
    </Context>
    ```
    同理，如果想要进入/host-manager/html页面，则新建或编辑conf/Catalina/localhost/host-manager.xml  
    添加内容 
    ```
    <?xml version="1.0" encoding="UTF-8"?>
    <Context privileged="true" antiResourceLocking="false"
        docBase="${catalina.home}/webapps/host-manager">
    <Valve className="org.apache.catalina.valves.RemoteAddrValve" allow="^.*$" />
    </Context>
    ```

2. 首先修改 conf/tomcat-users.xml 文件
    添加内容
    ```
    <user username="admin" password="admin" roles="standard,manager-gui"/>
    ```

3. 如果出现卡在登录框不能登陆问题
    清除浏览器缓存，重新启动tomcat  
## 访问host-manager
在根目录,`vim webapps/host-manager/META-INF/context.xml`  
```
<Context antiResourceLocking="false" privileged="true" >
<Valve className="org.apache.catalina.valves.RemoteAddrValve"
        allow="^.*$" />  #修改这里
</Context>
```
另外，角色权限里面必须要有admin-gui，没有是访问不了的
    


