## spring事务管理高层抽象包括三个接口
### PlatformTransactionManager 平台事务管理器
用来管理事务的接口：包含了事务的提交、回滚等信息

下面有一些具体的实现类：如DataTransactionManager,HibernateTransactionManager，JpaTransactionManager，JdoTransactionManager等等

会根据不同的持久层框架来提供不同的PlatformTransactionManager接口实现

DataTransactionManager：Spring JDBC或者是Mybatis

HibernateTransactionManager: Hibernate

### TransactionDefinition 事务定义信息（隔离、传播、超时、只读）
事务的四大特征：原子性、一致性、隔离性、持久性

事务操作的隔离级别，传播行为，是否超时、只读等信息
在这个里面会有一些常量：  
IOSLATION开头的常量，事务的隔离级别  
PROPAGATION: 事务的传播行为  
TIMEOUT：超时信息  
还有方法获得隔离级别,超时信息，是否只读  

#### 隔离
不考虑隔离性就会产生：脏读、不可重复读、幻读等安全性为题，隔离级别就是来解决这些问题的  
脏读：一个事务读取了另一个事务改写但还未提交数据，如果这些数据被回滚，则读到的数据是无效的。
不可重复读：在同一个事务中，多次读取同一个数据返回的结果有所不同  
幻读：一个事务读取了几行记录之后，另一个事务插入一些记录，幻读就发生了，在后来的查询中，第一个事务就会发现有些原来没有的记录  
隔离级别：  
DEFAULT： 使用后端数据库默认的隔离级别  
READ_UNCOMMITED：允许你读取还未提交的改变了的数据。可能导致脏、幻、不可重复读  
READ_COMMITED：允许并发事务已经提交后读取。可防止脏读，但幻、不可重复仍可能发生。  
REPEATABLE_READ: 对相同字段的读取是一致的，除非数据被事务本身改变，反正脏、不可重复，幻读能发生  
SERIALIZABLE: 完全服从ACID的隔离级别，确保不发生脏、幻、不可重复读。这在所有的隔离级别中是最慢的，它是典型的通过完全锁定在事务中涉及到数据表来完成的  

#### 传播行为
出现复杂的方法：调用Service1.aaa()和Service2.bbb().才能完成一个业务？  

事务的传播行为：主要用来解决业务层方法之间的调用问题  
1. PROPAGATION_REQUIRED（保证在一个事务里面）  
    支持当前事务，如果不存在，就新建一个：如果aaa里面有事务，就使用事务，如果没有，就新建  
1. PROPAGATION_REQUIRES_NEW（保证不再一个事务里面）   
    如果aaa中有事务，就把事务挂起，自己创建一个新的事务，也就是aaa和bbb不再一个事务里面  
1. PROPAGATION_NESTED  
    如果当前事务存在，则嵌套事务运行  

### TeansactionStatus 事务具体运行状态
事务是否已经提交，是否有保存点，是否是一个新的事务  
有一些方法：  
1. hasSavepoint()：是否有保存点  
1. isCompleted():是否已经完成  
1. isNewTeansaction()
1. isRollbackOnly()：
1. setRollbackOnly()