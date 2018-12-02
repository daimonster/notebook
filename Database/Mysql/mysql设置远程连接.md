想要连接远程数据库,需要有一下几个步骤:

## 创建用户
```
mysql->create user 'test'@'%' identified by '123';
```

## 赋予远程登陆权限
```
mysql> use mysql;
Database changed
mysql> grant all privileges  on *（数据库）.*（表） to root（用户）@'%'（任意地址） identified by "password"（密码）;
grant all privileges  on *.* to root@'%' identified by "password";
ALTER USER ‘dai‘@‘%‘ IDENTIFIED WITH mysql_native_password;
或者使用
mysql> update user set host = '%' where user = 'root';
# Query OK, 0 rows affected (0.00 sec)
eg: grant ALTER,SELECT,INSERT,UPDATE,DELETE on test.* to *@'%'  identified by "password";
```

## 查看权限及更新权限
```
show grants for work(用户名字);
或者
select host,user from user;
```

```
flush priviledegs;
```

## 撤回权限
```
revoke privileges on databasename.tablename from 'username'@'host';
```

## 删除用户
```
drop user 'test'@'host';
```

## 其它bug处理
这样的情况完成下,我的腾讯云服务器上的mysel服务器仍然不能远程登录

我检查了如下情况:

1. 检查127.0.0.1 是能够登录的,说明能够使用网址方式连接
1. 加上参数-P3306 能够登录,说明端口是绑定的3306
1. 使用公网地址example.com 不能登录,说明有网址绑定

在这里我进入了mysql的配置文件`/etc/mysql/mysql.conf.d/mysqld.conf`查看,里面有一句

> bind-address       = 127.0.0.1

把这行注释掉,就能够成功登录了.

## 用户权限表
权限列表:
* ALTER: 修改表和索引。
* CREATE: 创建数据库和表。
* DELETE: 删除表中已有的记录。
* DROP: 抛弃(删除)数据库和表。
* INDEX: 创建或抛弃索引。
* INSERT: 向表中插入新行。
* REFERENCE: 未用。
* SELECT: 检索表中的记录。
* UPDATE: 修改现存表记录。
* FILE: 读或写服务器上的文件。
* PROCESS: 查看服务器中执行的线程信息或杀死线程。
* RELOAD: 重载授权表或清空日志、主机缓存或表缓存。
* SHUTDOWN: 关闭服务器。
* ALL: 所有权限，ALL PRIVILEGES同义词。
*  USAGE: 特殊的 "无权限" 权限。

用户账户包括 "username" 和 "host" 两部分，后者表示该用户被允许从何地接入。tom@'%' 表示任何地址，默认可以省略。还可以是 "tom@192.168.1.%"、"tom@%.abc.com" 等。数据库格式为 db@table，可以是 "test.*" 或 "*.*"，前者表示 test 数据库的所有表，后者表示所有数据库的所有表。
子句 "WITH GRANT OPTION" 表示该用户可以为其他用户分配权限。 

## 2018年11月更新创建远程连接操作
新版的可以在root权限下无密码登陆
1. 创建一个远程连接的用户
    ```
    create user 'test'@'%' identified by 'password';
    ```
1. 给予该用户权限
    ```
    grant all privileges  on *.* to 'test'@'%' identified by "password";
    ```
1. 修改远程配置文件，注释127.0.0.1
    地址在`/etc/mysql/mariadb.conf.d/50-server.cnf`

1. 服务重启
    ```
    sudo systemctl restart mysql.service
    ```