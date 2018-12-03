[TOC]

## 1 PHP文件系统

### 1.1 PHP文件的读取
***

文件读取的函数是file_get_contents,可以将整个文件读到一个字符串之中
```
$content = file_get_constents('./test.test');//不知道为什么我的电脑里面必须要用绝对路径
```
也可以控制读取内容的开始点以及长度

PHP也提供类似于C语言操作文件的方法，使用fopen，fgets，fread等方法，fgets可以从文件指针中读取一行，freads可以读取指定长度的字符串。
```
$fp = fopen('./text.txt', 'rb');
while(!feof($fp)) {
    echo fgets($fp); //读取一行
}
fclose($fp);
```
<br>
```
$fp = fopen('./text.txt', 'rb');
$contents = '';
while(!feof($fp)) {
    $contents .= fread($fp, 4096); //一次读取4096个字符
}
fclose($fp);
```
### 1.2 判断文件是否存在
***
PHP用来判断是否存在的函数有两个is_file和file_exists.
```
if(file_exits($filename)){
    echo file_get_contents($filename);
}
```
is_file确切来说是给定的路径是否是一个文件：
```
$filename = './test.txt'
if(is_file($filename)){
    echo file_get_contents($filename);
}
```
is_readable 和 is_writeable，顾名思义，就是判断文件是否可以读写
```
if (is_writeable($filename)) {
    file_put_contents($filename, 'test');
}
if (is_readable($filename)) {
    echo file_get_contents($filename);
```
### 1.3 获取文件属性
***
* fileowner：获得文件的所有者
* filectime：获取文件的创建时间
* filemtime：获取文件的修改时间
* fileatime：获取文件的访问时间

```
$filename = './test.php';
echo '文件所有者'.fileowner($filename);
echo '文件创建时间'.date('Y-m-d H:i',filectime($filename));
echo '文件修改时间'.date('Y-m-d H:i',filemtime($filename));
```
### 1.4 获得文件的大小
***
文件的大小以字节数表示，我们可以进行转换
```
$pdfname = '/home/dai/桌面/byte-of-python-chinese-edition.pdf';
$size = filesize($pdfname)/pow(1024,2);
$size = number_format($size, 2);
echo 'byte-of-python-chinese-edition:'.$size.'MB';
```
### 1.5 PHP写入文件
***
与读取文件一样，可以有直接的函数和C风格的写入函数
```
$filename = './test.txt';
$data = 'test';
file_put_contents($filename, $data);
```
```
$fp = fopen('./test.txt', 'w');
fwrite($fp, 'hello');
fwrite($fp, 'world');
fclose($fp);
```

### 1.6 删除文件
***
删除文件
```
unlink($filename);
```
删除文件夹
```
rmdir($filename);
```

如果文件夹中存在文件，可以先循环删除目录中的所有文件，然后再删除该目录，循环删除可以使用glob函数遍历所有文件。

```
foreach (glob("*") as $filename) {//glob() 函数返回匹配指定模式的文件名或目录。
    unlink($filename);
}
```
