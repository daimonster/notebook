## 全局命令
* 查看所有键 `keys *`
* 键总数 `dbsize`
* 检查键是否存在 `exists key`
* 删除键 `del key`
* 键过期 `expire key seconds`
* 键的数据类型 `type key`

## 字符串操作
* 设置值`set key value`  
nx： 必须键不存在才可以设置，用于添加  
xx:  必须键存在才可以设置成功，用于更新
* 获取值`get key`
* 批量设置值 `mset VALUE1..VALUEN`
* 批量获取值 `mget VALUE1..VALUEN`
* 自增`incr key`,自减`decr`,自增指定数字`incrby`，自减指定数字`decrby`，自增浮点数`incrbyfloat`
* 追加值 `append key value`
* 字符串长度 `strlen key`
* 先返回可以值再设置 `getset key value`
* 获取部分字符串 `getrange key start end`

## 哈希
* 设置值`hset key field value`
* 获取值`hget key field`
* 删除值`hdel key field`
* 计算field的个数`hlen key`
* 批量设置,获取值   
  `hmset key field1...filedn`  
  `hmset key field1 value1...filedn valuen`  
  `hmget key field1...filedn`  
* 检查键是否存在 `hexists key field`
* 获取所有field `hkeys field`
* 获取所有value `hvals value`
* 获取所有field-value `htall value`
* 计算value的字符长度 `hstrlen key field`

## list操作
### 添加操作
* rpush 于将一个或多个值插入到列表的尾部(最右边) `RPUSH KEY_NAME VALUE1..VALUEN`。
* lpush 于将一个或多个值插入到列表的头部(最左边) `LPUSH KEY_NAME VALUE1..VALUEN`。
* 向某个元素(pivot)前或后插入元素 `linsert key before|after pivot value`
### 查找操作
* 查找指定范围list
*  全部列表 `LRANGE mylist 0 -1`.
*  部分列表 `LRANGE mylist start end`.
*  获取列表制定索引下标的元素 `lindex key index`
*  获取列表长度 `llen key`
### 删除
* 从左侧弹出元素并删除 `lpop key`
* 从右侧弹出元素并删除 `lpop key`
* 删除指定元素 `lrem key count value`
  * count > 0 从左到右 删除最多count个元素
  * count < 0 从右到左 删除最多count个元素
  * count = 0 删除所有元素
* 按照索引范围修剪列表 `trim key start end`  
  保留start到end范围的列表
### 修改
* 修改指定所有下表的元素 `lset key index newValue`
### 阻塞操作
* 阻塞式弹出  
  * `brpop key[key...] timeout`
  * `blpop key[key...] timeout`
  * timeout: 阻塞时间，如果等于0，则无限阻塞下去
  * 如果此间添加了数据，则立即返回

## set集合  
集合类型也是用来保存多个字符串元素，但是集合中不允许有重复元素，并且集合中的元素是无序的，不能通过索引下标来获取元素.
### 集合内操作
* 添加 `sadd key value1..valuen`
* 删除 `srem key value1..valuen`
* 删除 `srem key value1..valuen`
* 计算元素个数 `scard key`
* 判断元素是否在集合中 `sismember key`
* 随机从集合中返回指定个数元素 `srandmember key [count]`
* 随机弹出一个元素 `spop key`
* 获取所有元素 `smembers key`
### 集合间操作
* 求多个集合的交集 `sinter key [key...]`
* 求多个集合的并集 `sunion key [key...]`
* 求多个集合的差集 `sdiff key [key...]`
* 将交集、并集、差集  
  `sinterstore destination key [key...]`  
  `sunionstore destination key [key...]`  
  `sdiffstore destination key [key...]`  

## zset集合  
