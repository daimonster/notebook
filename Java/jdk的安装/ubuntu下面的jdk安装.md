  
1. 下载8u181安装包
```
wget -c http://download.oracle.com/otn-pub/java/jdk/8u181-b13/96a7b8442fe848ef90c96a2fad6ed6d1/jdk-8u181-linux-x64.tar.gz?AuthParam=1537699170_57e1ce7801f66ee9231ec584c87754f8
```
2. 解压，链接等操作
```
tar -xzvf jdk-8u181-linux-x64.tar.gz
sudo mkdir -p /opt/files(可能需要)
sudo mv jdk1.8.0_181/ /opt/files/
sudo ln -s files/jdk1.8.0_181 java
```
3. 设置环境变量
```
sudo vi ~/.bashrc
# this is the configuration for java
export JAVA_HOME=/opt/java
export JRE_HOME=${JAVA_HOME}/jre
export CLASSPATH=.:${JAVA_HOME}/lib:${JRE_HOME}/lib
export PATH=${JAVA_HOME}/bin:$PATH
```

4. 检查安装是否成功
```
java -version
```
显示信息的就表示安装成功