## 参考
[awk 入门教程](http://www.ruanyifeng.com/blog/2018/11/awk.html)

## 简介
awk是处理文本文件的一个应用程序，它依次处理文件的每一行，并读取里面的每一个字段

## 基本用法
* 通常使用
    ```
    # 格式
    $ awk 动作 文件名

    # 示例
    $ awk '{print $0}' demo.txt
    ```
    其中$0是当前行  
    awk会根据空格和制表符，将每一行分成若干字段，依次用$1、$2、$3代表第一个字段、第二个字段、第三个字段等等。  

* 指定的分隔符，则加上参数-F，如：
    ```
    $ awk -F ':' '{ print $1 }' demo.txt
    ```

## 变量
* 变量NF表示当前行有多少个字段，因此$NF就代表最后一个字段。$(NF-1)代表倒数第二个字段。  
    ```
    $ awk -F ':' '{print $1, $(NF-1)}' demo.txt
    root /root
    daemon /usr/sbin
    bin /bin
    sys /dev
    sync /bin
    ```
    上面代码中，print命令里面的逗号，表示输出的时候，两个部分之间使用空格分隔。 

* 变量NR表示当前处理的是第几行。  
    ```
    $ awk -F ':' '{print NR ") " $1}' demo.txt
    1) root
    2) daemon
    3) bin
    4) sys
    5) sync
    ```

* 其它内置变量
    ```
    FILENAME：当前文件名
    FS：字段分隔符，默认是空格和制表符。
    RS：行分隔符，用于分割每一行，默认是换行符。
    OFS：输出字段的分隔符，用于打印时分隔字段，默认为空格。
    ORS：输出记录的分隔符，用于打印时分隔记录，默认为换行符。
    OFMT：数字输出的格式，默认为％.6g。
    ```
## 函数
* 示例
    ```
    $ awk -F ':' '{ print toupper($1) }' demo.txt
    ROOT
    DAEMON
    BIN
    SYS
    SYNC
    ```
* 其它函数
    ```
    tolower()：字符转为小写。
    length()：返回字符串长度。
    substr()：返回子字符串。
    sin()：正弦。
    cos()：余弦。
    sqrt()：平方根。
    rand()：随机数。
    ```

## 条件
* 输出符合条件的行
    ```
    $ awk '条件 动作' 文件名
    $ awk -F ':' '/usr/ {print $1}' demo.txt
    root
    daemon
    bin
    sys
    ```
* 输出奇数行
    ```
    # 输出奇数行
    $ awk -F ':' 'NR % 2 == 1 {print $1}' demo.txt
    root
    bin
    sync
    ```

## if语句
* 使用if
    ```
    $ awk -F ':' '{if ($1 > "m") print $1; else print "---"}' demo.txt
    root
    ---
    ---
    sys
    sync
    ```