## 数据库

### 1 进行数据库操作的步骤
1. 连接数据库 mysqli_connect
2. 选择数据库 mysqli_select_db
3. 设置文件编码 mysqli_query("set name utf-8")
4. 发送数据库操作指令 比如查询 mysql_query("select * from user");
5. 接收返回结果 这个很多,自己查手册
6. 释放资源,关闭数据库 mysqli_free_result() mysql_close();


***

### 2 数据库的连接
这里特别要注意的是PHP7.0已经**不支持mysql_connect()函数**了，取而代之的是mysqli_connect 或者是PDO
```
$link = mysqli_connect('127.0.0.1', 'code1', '') or die('数据库连接失败');
mysqli_select_db('code1');
mysqli_query("set names 'utf8'");
$result = mysqli_query('select * from user limit 1');
$row = mysqli_fetch_assoc($result);
print_r($row);
```
对应的mysql连接操作是
`mysql -h localhost -u code1 -p`

***
### 3 选择数据库
当连接成功以后，我们需要选择一个操作的数据库，通过mysql_select_db函数来选择数据库。
`mysqli_select_db('code1');`
通常我们会先设置一下当前连接使用的字符编码，一般的我们会使用utf8编码。
`mysqli_query("set names 'utf8'");`


***

### 4 执行查询指令
先执行`mysqli_query`函数来发送查询语句
然后执行`mysqli_fetch_arry`函数来取回查询数据
```
$res = mysqli_query('select * from user limit 1');
$row = mysqli_fetch_array($res);
var_dump($row);
```

***
### 5 插入新的数据
插入数据是用`mysqli_query`来执行mysql的插入语句,在mysql中，执行插入语句以后，可以得到自增的主键id,通过PHP的mysql_insert_id函数可以获取该id。
```
$name = '李四';
$age = 18;
$class = '高三一班';
$sql = "insert into user(name, age, class) values('$name', '$age', '$class')";
mysql_query($sql); //执行插入语句
$uid = mysql_insert_id();
echo $uid;
```
***
### 6 取回数据
取回数据最常用的是`mysqli_fetch_array`(取回数据一般都是取回一行数据)
用`mysqli_fetch_row`来获取数字索引数组
用`mysqli_fetch_assoc`来获取关联索引数组
```
$row = mysql_fetch_row($result);
$row = mysql_fetch_array($result, MYSQL_NUM); //这两个方法获取的数据是一样的
$row = mysql_fetch_assoc($result);
$row = mysql_fetch_array($result, MYSQL_ASSOC);
```
用循环遍历来获取所有数字
```
$data = array();
while ($row = mysql_fetch_array($result)) {
    $data[] = $row;
}
```

***
### 7 查询分页数据
我们使用分页来显示数据，每页显示10到20条数据

`mysql`中的`limit`可以实现分页，`limit m,n`表示从m行后取n行数据，

假定当前页为`$page`,每页显示`$n`条数据,m为当前页前面所有数据，即`$m = ($page - 1) * $n`

```
$page = 2;
$pagesize = 2;
//在这里构建分页查询
$offset = ($page - 1) * $pagesize;
$sql = "select * from user limit $offset,$pagesize";
//获取翻页数据
$result = mysql_query($sql);
$data = array();
while ($row = mysql_fetch_array($result, MYSQL_ASSOC)) {
    $data[] = $row;
}
print_r($data);
```

***
### 8 删除与更新操作

这个只需要通过mysql的update和delete来进行操作

更新操作

```
$sql = "update user set name = '曹操' where id=2 limit 1";
if (mysql_query($sql)) {
    echo '更新成功';
}
```

删除操作
```
$sql = "delete from user where id=2 limit 1";
if (mysql_query($sql)) {
    echo '删除成功';
}
```
mysql_affected_rows函数来获取更新过的数据行数
```
echo '数据更新行数：'.mysql_affected_rows();
```

***
### 9 关闭数据库
```
mysql_close();
```
或者
```
$link = mysql_connect($host, $user, $pass);
mysql_close($link);
```
