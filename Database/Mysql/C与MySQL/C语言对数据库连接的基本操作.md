## 数据类型

1. MYSQL

       MYSQL结构代表一个数据库连接句柄，包含有关服务器的连接状态的信息，几乎所有函数都是用到它
  

        typedef struct st_mysql
        {
          NET           net;                    /* Communication parameters */
          unsigned char *connector_fd;          /* ConnectorFd for SSL */
          char          *host,*user,*passwd,*unix_socket,*server_version,*host_info;
          char          *info, *db;
          struct charset_info_st *charset;
          MYSQL_FIELD   *fields;
          MEM_ROOT      field_alloc;
          my_ulonglong affected_rows;
          my_ulonglong insert_id;               /* id if insert on table with NEXTNR */
          my_ulonglong extra_info;              /* Not used */
          unsigned long thread_id;              /* Id for connection in server */
          unsigned long packet_length;
          unsigned int  port;
          unsigned long client_flag,server_capabilities;
          unsigned int  protocol_version;
          unsigned int  field_count;
          unsigned int  server_status;
          unsigned int  server_language;
          unsigned int  warning_count;
          struct st_mysql_options options;
          enum mysql_status status;
          my_bool       free_me;                /* If free in mysql_close */
          my_bool       reconnect;              /* set to 1 if automatic reconnect */

          /* session-wide random string */
          char          scramble[SCRAMBLE_LENGTH+1];

        /*
          Set if this is the original connection, not a master or a slave we have
          added though mysql_rpl_probe() or mysql_set_master()/ mysql_add_slave()
        */
          my_bool rpl_pivot;
          /*
            Pointers to the master, and the next slave connections, points to
            itself if lone connection.
          */
          struct st_mysql* master, *next_slave;

          struct st_mysql* last_used_slave; /* needed for round-robin slave pick */
        /* needed for send/read/store/use result to work correctly with replication */
          struct st_mysql* last_used_con;

          LIST  *stmts;                     /* list of all statements */
          const struct st_mysql_methods *methods;
          void *thd;
          /*
            Points to boolean flag in MYSQL_RES  or MYSQL_STMT. We set this flag
            from mysql_stmt_close if close had to cancel result set of this object.
          */
          my_bool *unbuffered_fetch_owner;
          /* needed for embedded server - no net buffer to store the 'info' */
          char *info_buffer;
          void *extension;
        } MYSQL;


2. MYSQL_RES

    MYSQL_RES结构代表返回行的查询结果（SELECT、SHOW、DESCRIBE等），从数据库读取数据，最后就是从MYSQL_RES中读取数据。 MYSQL_RES定义如下：
    ```
    typedef struct st_mysql_res {  
    my_ulonglong  row_count;  
    MYSQL_FIELD   *fields;  
    MYSQL_DATA    *data;  
    MYSQL_ROWS    *data_cursor;  
    unsigned long *lengths;               /* column lengths of current row */  
    MYSQL         *handle;                /* for unbuffered reads */  
    const struct st_mysql_methods *methods;  
    MYSQL_ROW     row;                    /* If unbuffered read */  
    MYSQL_ROW     current_row;            /* buffer to current row */  
    MEM_ROOT      field_alloc;  
    unsigned int  field_count, current_field;  
    my_bool       eof;                    /* Used by mysql_fetch_row */  
    /* mysql_stmt_close() had to cancel this result */  
    my_bool       unbuffered_fetch_cancelled;    
    void *extension;  
    } MYSQL_RES; 
    ```

## 数据库函数
### 1 mysql_real_connect

函数原型如下：
```	
MYSQL * STDCALL mysql_real_connect(MYSQL *mysql, const char *host,
const char *user,
const char *passwd,
const char *db,
unsigned int port,
const char *unix_socket,
unsigned long clientflag);
```

例子： 
```
#include <stdio.h>  
#include <mysql.h>  
    
int main(int argc, const char *argv[])  
{  
    MYSQL   mysql;  
    
    if (NULL == mysql_init(&mysql)) {    //分配和初始化MYSQL对象  
        printf("mysql_init(): %s\n", mysql_error(&mysql));  
        return -1;  
    }  
    
    //尝试与运行在主机上的MySQL数据库引擎建立连接  
    if (NULL == mysql_real_connect(&mysql,  
                "localhost",  
                "root",  
                "shallnet",  
                "db_users",  
                0,  
                NULL,  
                0)) {  
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));  
        return -1;  
    }  
    
    printf("Connected MySQL successful! \n");  
    
    mysql_close(&mysql);  
    return 0;  
}  
```

### 2 数据查询语句函数mysql_query

函数原型
```
int STDCALL mysql_query(MYSQL *mysql, const char *q);
```

查询的例子：
```
#include <stdio.h>
#include <mysql.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    MYSQL           mysql;
    MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    char            *query_str = NULL;
    int             rc, i, fields;
    int             rows;
    if (NULL == mysql_init(&mysql)) {
        printf("mysql_init(): %s\n", mysql_error(&mysql));
        return -1;
    }
    if (NULL == mysql_real_connect(&mysql,
                "localhost",
                "root",
                "shallnet",
                "db_users",
                0,
                NULL,
                0)) {
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    printf("1. Connected MySQL successful! \n");
    query_str = "select * from tb_users";
    rc = mysql_real_query(&mysql, query_str, strlen(query_str));
    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        return -1;
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {
         printf("mysql_restore_result(): %s\n", mysql_error(&mysql));
         return -1;
    }
    rows = mysql_num_rows(res);
    printf("The total rows is: %d\n", rows);
    fields = mysql_num_fields(res);
    printf("The total fields is: %d\n", fields);
    while ((row = mysql_fetch_row(res))) {
        for (i = 0; i < fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    mysql_close(&mysql);
    return 0;
}
```


插入删除的例子：
```
#include <stdio.h>
#include <mysql.h>
#include <string.h>
int main(int argc, const char *argv[])
{
    MYSQL           mysql;
    MYSQL_RES       *res = NULL;
    MYSQL_ROW       row;
    char            *query_str = NULL;
    int             rc, i, fields;
    int             rows;
    if (NULL == mysql_init(&mysql)) {
        printf("mysql_init(): %s\n", mysql_error(&mysql));
        return -1;
    }
    if (NULL == mysql_real_connect(&mysql,
                "localhost",
                "root",
                "shallnet",
                "db_users",
                0,
                NULL,
                0)) {
        printf("mysql_real_connect(): %s\n", mysql_error(&mysql));
        return -1;
    }
    printf("1. Connected MySQL successful! \n");
    query_str = "select * from tb_users";
    rc = mysql_real_query(&mysql, query_str, strlen(query_str));
    if (0 != rc) {
        printf("mysql_real_query(): %s\n", mysql_error(&mysql));
        return -1;
    }
    res = mysql_store_result(&mysql);
    if (NULL == res) {
         printf("mysql_restore_result(): %s\n", mysql_error(&mysql));
         return -1;
    }
    rows = mysql_num_rows(res);
    printf("The total rows is: %d\n", rows);
    fields = mysql_num_fields(res);
    printf("The total fields is: %d\n", fields);
    while ((row = mysql_fetch_row(res))) {
        for (i = 0; i < fields; i++) {
            printf("%s\t", row[i]);
        }
        printf("\n");
    }
    mysql_close(&mysql);
    return 0;
}
```

```
gcc具体的编译方法：gcc ***.c -o *** -lmysqlclient
```

## 参考

[linux下C语言编程操作MySQL数据库](http://blog.csdn.net/qq_21111579/article/details/52051913)