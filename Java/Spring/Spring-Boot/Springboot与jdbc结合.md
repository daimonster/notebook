## pom中添加依赖
* mysql不用说了
### 添加jdbc依赖 
```
<dependency>
		<groupId>org.springframework.boot</groupId>
		<artifactId>spring-boot-starter-jdbc</artifactId>
</dependency>
```
### 添加jpa依赖
```
<dependency>
		<groupId>org.springframework.boot</groupId>
		<artifactId>spring-boot-starter-data-jpa</artifactId>
</dependency>
```

## 在application.properties中添加mysql的连接
```
spring.datasource.url=jdbc:mysql://118.126.64.234:10023/high_concurrency_parise?useUnicode=true&characterEncoding=utf8&useSSL=false
spring.datasource.username=**
spring.datasource.password=******
```

## 实体前加注解
* 实体类之前加@Entity
* 主键之前加上@Id

## 添加Dao包
* 在Dao添加接口UserDao继承JpaRepository，里面有一些操作
    ```
    public interface UserDao extends JpaRepository<User,String >{
    }
    ```

## 进行测试
* test里面进行测试，springboot已经给好样例了