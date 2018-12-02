这是针对没有pom.xml文件的工程来说

## spring工程的创建
1. Project-SDK选择1.8，之后选择next，这步没啥好说的
2. 填写groupId和ArtifactId这两个选项：  
    groupId 决定了src/java和test/java文件夹中包的存放地址  
    ArtifactId 决定了工程名称以及存放工程的文件夹（存放地址即为当前文件夹/$ArtifactId）

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
* 在左侧importing选项卡里面把Automatically download中的Sources和Document选项勾上
* 在左侧runner中添加"-Xms512m -Xmx1024m"