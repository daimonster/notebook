## 创建实体类
* 创建一个实体类，这个就不用多说了

## Dao层的实现
### pom配置
* 添加mybatis依赖 mybatis-spring-boot-starter
* 添加mysql连接以来 不需要添加版本，因为已经有了parent指定
* 添加c3p0连接池
```
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-web</artifactId>
</dependency>

<!--数据库依赖-->
<dependency>
    <groupId>org.mybatis.spring.boot</groupId>
    <artifactId>mybatis-spring-boot-starter</artifactId>
    <version>1.3.2</version>
</dependency>

<dependency>
    <groupId>mysql</groupId>
    <artifactId>mysql-connector-java</artifactId>
    <scope>runtime</scope>
</dependency>
<!-- https://mvnrepository.com/artifact/com.mchange/c3p0 -->
<dependency>
    <groupId>com.mchange</groupId>
    <artifactId>c3p0</artifactId>
    <version>0.9.5.2</version>
</dependency>
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-tomcat</artifactId>
    <scope>provided</scope>
</dependency>
<dependency>
    <groupId>org.springframework.boot</groupId>
    <artifactId>spring-boot-starter-test</artifactId>
    <scope>test</scope>
</dependency>
```

## 在application.properties中添加jdbc.*
```
# 修改网址入口
server.servlet.context-path= /****

# DataSource
jdbc.driver=com.mysql.jdbc.Driver
jdbc.url=jdbc:mysql://118.126.64.234:10023/****?useUnicode=true&characterEncoding=utf8&useSSL=false
jdbc.username=zCKAAEaFQUI=
jdbc.password=e9l3FAxqtZ/pboy2Vfh4Ag==

#Mybatis
mybatis_config_file=mybatis-config.xml
mapper_path=/mapper/**.xml
entity_package=com.imooc.****.entity
```

## 添加mybatis-config
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
		PUBLIC "-//mybatis.org//DTD Config 3.0//EN"
		"http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
	<!-- 配置全局属性 -->
	<settings>
		<!-- 使用jdbc的getGeneratedKeys获取数据库自增主键值 -->
		<setting name="useGeneratedKeys" value="true" />

		<!-- 使用列标签替换列别名 默认:true -->
		<setting name="useColumnLabel" value="true" />

		<!-- 开启驼峰命名转换:Table{create_time} -> Entity{createTime} -->
		<setting name="mapUnderscoreToCamelCase" value="true" />
	</settings>
</configuration>
```

### 创建DataSourceConfiguration
这里有一处包地址修改
```
@Configuration
// 配置mybatis mapper的扫描路径
@MapperScan("com.example.demotest.dao")//修改包地址
public class DataSourceConfiguration {
    @Value("${jdbc.driver}")
    private String jdbcDriver;
    @Value("${jdbc.url}")
    private String jdbcUrl;
    @Value("${jdbc.username}")
    private String jdbcUsername;
    @Value("${jdbc.password}")
    private String jdbcPassword;

    /**
     * 生成与spring-dao.xml对应的bean dataSource
     *
     * @return
     * @throws PropertyVetoException
     */
    @Bean(name = "dataSource")
    public ComboPooledDataSource createDataSource() throws PropertyVetoException {
        // 生成datasource实例
        ComboPooledDataSource dataSource = new ComboPooledDataSource();
        // 跟配置文件一样设置以下信息
        // 驱动
        dataSource.setDriverClass(jdbcDriver);
        // 数据库连接URL
        dataSource.setJdbcUrl(DESUtil.getDecryptString(jdbcUrl));
        // 设置用户名
        dataSource.setUser(DESUtil.getDecryptString(jdbcUsername));
        // 设置用户密码
        dataSource.setPassword(DESUtil.getDecryptString(jdbcPassword));
        // 配置c3p0连接池的私有属性
        // 连接池最大线程数
        dataSource.setMaxPoolSize(30);
        // 连接池最小线程数
        dataSource.setMinPoolSize(10);
        // 关闭连接后不自动commit
        dataSource.setAutoCommitOnClose(false);
        // 连接超时时间
        dataSource.setCheckoutTimeout(10000);
        // 连接失败重试次数
        dataSource.setAcquireRetryAttempts(2);
        return dataSource;
    }
}
```

### 创建SessionFactoryConfiguration
```
@Configuration
public class SessionFactoryConfiguration {
	// mybatis-config.xml配置文件的路径
	private static String mybatisConfigFile;

	@Value("${mybatis_config_file}")
	public void setMybatisConfigFile(String mybatisConfigFile) {
		SessionFactoryConfiguration.mybatisConfigFile = mybatisConfigFile;
	}

	// mybatis mapper文件所在路径
	private static String mapperPath;

	@Value("${mapper_path}")
	public void setMapperPath(String mapperPath) {
		SessionFactoryConfiguration.mapperPath = mapperPath;
	}

	// 实体类所在的package
	@Value("${type_alias_package}")
	private String typeAliasPackage;

	@Autowired
	@Qualifier("dataSource")
	private DataSource dataSource;

	/**
	 * 创建sqlSessionFactoryBean 实例 并且设置configtion 设置mapper 映射路径 设置datasource数据源
	 * 
	 * @return
	 * @throws IOException
	 */
	@Bean(name = "sqlSessionFactory")
	public SqlSessionFactoryBean createSqlSessionFactoryBean() throws IOException {
		SqlSessionFactoryBean sqlSessionFactoryBean = new SqlSessionFactoryBean();
		// 设置mybatis configuration 扫描路径
		sqlSessionFactoryBean.setConfigLocation(new ClassPathResource(mybatisConfigFile));
		// 添加mapper 扫描路径
		PathMatchingResourcePatternResolver pathMatchingResourcePatternResolver = new PathMatchingResourcePatternResolver();
		String packageSearchPath = ResourcePatternResolver.CLASSPATH_ALL_URL_PREFIX + mapperPath;
		sqlSessionFactoryBean.setMapperLocations(pathMatchingResourcePatternResolver.getResources(packageSearchPath));
		// 设置dataSource
		sqlSessionFactoryBean.setDataSource(dataSource);
		// 设置typeAlias 包扫描路径
		sqlSessionFactoryBean.setTypeAliasesPackage(typeAliasPackage);
		return sqlSessionFactoryBean;
	}
}
```

## mapper编写  
### AreaDao.xml编写
这里有两处包地址修改
```
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
    PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
    "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.imooc.demo.dao.AreaDao"> // 修改包地址
	<select id="queryArea" resultType="com.imooc.demo.entity.Area"> // 修改包地址
		SELECT area_id, area_name,
		priority, create_time, last_edit_time
		FROM tb_area
		ORDER BY priority
		DESC
	</select>
</mapper>
```

## 编写测试类
