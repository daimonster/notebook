1. TCP三次握手和四次挥手各自的状态

    三次握手：
    |主机|服务器|
    |:--|:--|
    |CLOSE|          LISTEN|
    |SYN_SENT |SYN_RCVD|
    |ESTABLISHED|ESTABLISHED| 

    四次挥手
    |主机|服务器|
    |:--|:--|
    |FIN_WAIT1|CLOSE_WAIT|
    |FIN_WAIT2|LAST_ACK|
    |TIME_WAIT|CLOSE|
    |CLOSE|

1. 为什么建立连接协议是三次握手，而关闭连接却是四次握手呢？ 

    这是因为服务端的LISTEN状态下的SOCKET当收到SYN报文的建连请求后，它可以把ACK和SYN（ACK起应答作用，而SYN起同步作用）放在一 个报文里来发送。但关闭连接时，当收到对方的FIN报文通知时，它仅仅表示对方没有数据发送给你了；但未必你所有的数据都全部发送给对方了，所以你可以未 必会马上会关闭SOCKET,也即你可能还需要发送一些数据给对方之后，再发送FIN报文给对方来表示你同意现在可以关闭连接了，所以它这里的ACK报文和FIN报文多数情况下都是分开发送的 
