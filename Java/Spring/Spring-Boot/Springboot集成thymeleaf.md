## 添加thymeleaf依赖
```
<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-thymeleaf</artifactId>
</dependency>
```

## applications.properties中添加配置项
```
<!-- thymeleaf -->
		<dependency>
			<groupId>org.springframework.boot</groupId>
			<artifactId>spring-boot-starter-thymeleaf</artifactId>
</dependency>
```

## 遇到的问题
* 出现了服务器无法启动的问题，可能是maven依赖没有配置好，反正就重新刷新了下就能正常启动了