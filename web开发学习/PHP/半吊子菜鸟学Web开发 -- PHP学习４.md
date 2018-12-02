## PHP异常处理
### １ 抛出一个异常

与Python的try except类似，PHP用try catch来捕获异常

*基本语法*
``` 
try{
    //可能出现错误或异常的代码
    //catch表示捕获，Exception是php已定义好的异常类
} catch(Exception $e){
    //对异常处理，方法：
        //1、自己处理
        //2、不处理，将其再次抛出
}
```
*处理程序*

Try - 使用异常的函数应该位于 "try"  代码块内。如果没有触发异常，则代码将照常继续执行。但是如果异常被触发，会抛出一个异常。
Throw - 这里规定如何触发异常。**注意：每一个 "throw" 必须对应至少一个 "catch"**，当然可以对应多个"catch"
Catch - "catch" 代码块会捕获异常，并创建一个包含异常信息的对象。

```
//创建可抛出一个异常的函数
function checkNum($number){
     if($number>1){
         throw new Exception("异常提示-数字必须小于等于1");
     }
     return true;
 }
 
//在 "try" 代码块中触发异常
 try{
     checkNum(2);
     //如果异常被抛出，那么下面一行代码将不会被输出
     echo '如果能看到这个提示，说明你的数字小于等于1';
 }catch(Exception $e){
     //捕获异常
     echo '捕获异常: ' .$e->getMessage();
 }
```
***
### 异常处理类

PHP具有很多异常处理类，其中Exception是所有异常处理的基类。

Exception具有几个基本属性与方法，其中包括了：

message 异常消息内容
code 异常代码
file 抛出异常的文件名
line 抛出异常在该文件的行数

其中常用的方法有：

getTrace 获取异常追踪信息
getTraceAsString 获取异常追踪信息的字符串
getMessage 获取出错信息

```
//自定义的异常类，继承了PHP的异常基类Exception
class MyException extends Exception {
    function getInfo() {
        return '自定义错误信息';
    }
}

try {
    //使用异常的函数应该位于 "try"  代码块内。如果没有触发异常，则代码将照常继续执行。但是如果异常被触发，会抛出一个异常。
    throw new MyException('error');//这里规定如何触发异常。注意：每一个 "throw" 必须对应至少一个 "catch"，当然可以对应多个"catch"
} catch(Exception $e) {//"catch" 代码块会捕获异常，并创建一个包含异常信息的对象
    echo $e->getInfo();//获取自定义的异常信息
    echo $e->getMessage();//获取继承自基类的getMessage信息
}
```
***
### 捕获异常信息
一般异常的处理流程是：
```
try {
    throw new Exception('wrong');
} catch(Exception $ex) {
    echo 'Error:'.$ex->getMessage().'<br>';
    echo $ex->getTraceAsString().'<br>';
}
echo '异常处理后，继续执行其他代码';
```
***
### 获取错误信息到日志中去
```
try {
    throw new Exception('wrong');
} catch(Exception $ex) {
    $msg = 'Error:'.$ex->getMessage()."\n";
    $msg.= $ex->getTraceAsString()."\n";
    $msg.= '异常行号：'.$ex->getLine()."\n";
    $msg.= '所在文件：'.$ex->getFile()."\n";
    //将异常信息记录到日志中
 PHP异常处理之   file_put_contents('error.log', $msg);
}
```
