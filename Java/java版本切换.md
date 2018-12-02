## 背景(Why)

现在经常遇到一些事情需要不同的 JDK 环境. 比如编译 android4.4源码要 JDK6 ,编译 play framework(1.2.7) 需要JDK7(JDK8会报错)，这个时候要是能一键切换就能方便很多。下面我就向大家介绍一下OSX下zsh terminal一键切换JDK版本的方法。

## 如何切换(How)
```
vi ~/.zshrc
```

在配置文件底部添加如下配置：
```
#JDK Switch
export JAVA_6_HOME=/Library/Java/JavaVirtualMachines/1.6.0.jdk/Contents/Home
export JAVA_7_HOME=/Library/Java/JavaVirtualMachines/jdk1.7.0_67.jdk/Contents/Home
export JAVA_8_HOME=/Library/Java/JavaVirtualMachines/jdk1.8.0_73.jdk/Contents/Home

export JAVA_HOME=$JAVA_8_HOME

alias jdk8='export JAVA_HOME=$JAVA_8_HOME'
alias jdk7='export JAVA_HOME=$JAVA_7_HOME'
alias jdk6='export JAVA_HOME=$JAVA_6_HOME'
```

然后命令行输入jdk6/jdk7/jdk8 就可以得到相应的版本

## 运行效果

### Switch JDK6
```
$ jdk6
$ java -version
java version "1.6.0_65"
Java(TM) SE Runtime Environment (build 1.6.0_65-b14-468-11M4833)
Java HotSpot(TM) 64-Bit Server VM (build 20.65-b04-468, mixed mode)
```

### Switch JDK7
```
$ jdk7
$ java -version
java version "1.7.0_67"
Java(TM) SE Runtime Environment (build 1.7.0_67-b01)
Java HotSpot(TM) 64-Bit Server VM (build 24.65-b04, mixed mode)
```

### Switch JDK8
```
$ jdk8
$ java -version
java version "1.8.0_73"
Java(TM) SE Runtime Environment (build 1.8.0_73-b02)
Java HotSpot(TM) 64-Bit Server VM (build 25.73-b02, mixed mode)
```

切换起来so easy啊, 一颗赛艇😄
