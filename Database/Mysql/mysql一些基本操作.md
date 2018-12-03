## 登陆mysql数据库可以通过如下命令：
mysql -u root -p -h 地址
然后通过 show databases; 就可以查看当前的数据库。
我们选择 mysql数据库就行下一步操作，使用use mysql 命令，显示当前数据库的表单：show tables
## 查看所有用户
```
use mysql;
select user,host from mysql.user; 

```

## 修改用户密码
```
update user set authentication_string=password('xxxxxx') where user='xxxxxx';
```
## 创建数据库
```
CREATE DATABASE tianchunwei DEFAULT CHARACTER SET utf8
```

## 求差,并,交运算
```
select emp_no from employees 
except(union,intersect) select emp_no from dept_manager;
```

## 计算分组中元素的个数
```
select title,count(title) as t
from titles
group by title
having t>= 2;
```
## 插入数据
```
INSERT INTO
  tb_person_info(name, profile_img, email, gender)
VALUES
  ("测试","test","test","1" );
```
## 更新操作
```
update user set password=password('123') where user='root'; 
```