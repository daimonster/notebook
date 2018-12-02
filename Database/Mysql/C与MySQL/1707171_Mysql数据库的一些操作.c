//以下代码块是用来连接数据库的通讯过程，要连接MYSQL，必须建立MYSQL实例，通过mysql_init初始化方能开始进行连接.

typedef struct st_mysql {

 NET           net;            /* Communication parameters */

 gptr          connector_fd;   /* ConnectorFd for SSL */

 char          *host,*user,*passwd,*unix_socket,

                *server_version,*host_info,*info,*db;

 unsigned int port,client_flag,server_capabilities;

 unsigned int protocol_version;

 unsigned int field_count;

 unsigned int server_status;

 unsigned long thread_id;      /* Id for connection in server */

 my_ulonglong affected_rows;

 my_ulonglong insert_id;       /* id if insert on table with NEXTNR */

 my_ulonglong extra_info;              /* Used by mysqlshow */

 unsigned long packet_length;

 enum mysql_status status;

 MYSQL_FIELD   *fields;

 MEM_ROOT      field_alloc;

 my_bool       free_me;        /* If free in mysql_close */

 my_bool       reconnect;      /* set to 1 if automatic reconnect */

 struct st_mysql_options options;

 char          scramble_buff[9];

 struct charset_info_st *charset;

 unsigned int server_language;

} MYSQL;


/*这个结构代表返回行的一个查询的(SELECT, SHOW, DESCRIBE, EXPLAIN)的结果。返回的数据称为“数据集”，用过数据库的朋友应该对数据库中查询后得到的结果集不会陌生，在C的API里对应的就是MYSQL_RES了，从数据库读取数据，最后就是从MYSQL_RES中读取数据。*/

typedef struct st_mysql_res {

 my_ulonglong row_count;

 unsigned int field_count, current_field;

 MYSQL_FIELD   *fields;

 MYSQL_DATA    *data;

 MYSQL_ROWS    *data_cursor;

 MEM_ROOT      field_alloc;

 MYSQL_ROW     row;            /* If unbuffered read */

 MYSQL_ROW     current_row;    /* buffer to current row */

 unsigned long *lengths;       /* column lengths of current row */

 MYSQL         *handle;        /* for unbuffered reads */

 my_bool       eof;            /* Used my mysql_fetch_row */

} MYSQL_RES;

 

/*－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－

再看函数：

 

C语言操作mysql数据 常用函数

所需头文件： #include <mysql/mysql.h>
功能：  获得或初始化一个MYSQL结构
函数原型： MYSQL *mysql_init(MYSQL *mysql)
函数返回值： 一个被始化的MYSQL*句柄
备注：  在内存不足的情况下，返回NULL

所需头文件： #include <mysql/mysql.h>
函数功能： 关闭一个服务器连接，并释放与连接相关的内存
函数原型： void mysql_close(MYSQL *mysql);
函数传入值： MYSQL:类型的指针
函数返回值： 无

所需头文件： #include <mysql/mysql.h>
函数功能： 连接一个MySQL服务器
函数原型： MYSQL * mysql_connect(MYSQL *mysql,const char *host,const char *user,const char *passwd);
函数传入值： mysql表示一个现存mysql结构的地址
  host表示MYSQL服务器的主机名或IP
  user表示登录的用户名
  passwd表示登录的密码
函数返回值： 如果连接成功，一个MYSQL *连接句柄：如果连接失败，NULL
备注：  该函数不推荐，使用mysql_real_connect()代替

所需文件： #include <mysql/mysql.h>
函数功能： MYSQL *mysql_real_connect(MYSQL *mysql,const char *host,const char *user,const char *passwd,const char *db,unsigned int port,const char *unix_socket,unsigned int client_flag);
函数传入值： mysql表示一个现存mysql结构的地址
  host表示MYSQL服务器的主机名或IP
  user表示登录的用户名
  passwd表示登录的密码
  db表示要连接的数据库
  port表示MySQL服务器的TCP/IP端口
  unix_socket表示连接类型
  client_flag表示MySQL运行ODBC数据库的标记
函数返回值： 如果连接成功，一个MYSQL*连接句柄：如果连接失败，NULL

所需头文件： #include <mysql/mysql.h>
函数功能： 返回最新的UPDATE，DELETE或INSERT查询影响的行数
函数传入值： MYSQL:类型指针
函数返回值： 大于零的一个整数表示受到影响或检索出来的行数。零表示没有区配查序中WHERE子句的记录或目前还没有查询被执行;-1表示查询返回一个错误，或对于一个SELECT查询

所需头文件： #include <mysql/mysql.h>
函数功能： 对指定的连接执行查询
函数原型： int mysql_query(MYSQL *mysql,const char *query);
函数传入值： query表示执行的SQL语句
函数返回值： 如果查询成功，为零，出错为非零。
相关函数： mysql_real_query

所需头文件： #include <mysql/mysql.h>
函数功能： 为无缓冲的结果集获得结果标识符
函数原形： MYSQL_RES *mysql_use_result(MYSQL *mysql);
函数传入值： MYSQL:类型的指针
函数返回值： 一个MYSQL_RES结果结构，如果发生一个错误发NULL

#incluee <mysql/mysql.h>
检索一个结果集合的下一行
MYSQL_ROW mysql_fetch_row(MYSQL_RES *result);
MYSQL_RES:结构的指针
下一行的一个MYSQL_ROW结构。如果没有更多的行可检索或如果出现一个错误，NULL

#include <mysql/mysql.h>
返回指定结果集中列的数量
unsigned int mysql_num_fields(MYSQL_RES *res);
MYSQL_RES 结构的指针
结果集合中字段数量的一个无符号整数

#include <mysql/mysql.h>
创建一个数据库
int mysql_create_db(MYSQL *mysql,const char *db);
MYSQL：类型的指针
db:要创建的数据库名
如果数据库成功地被创建，返回零，如果发生错误，为非零。
#include <mysql/mysql.h>
选择一个数据库
int mysql_select_db(MYSQL *mysql,const char *db);
MYSQL：类型的指针
db:要创建的数据库名
如果数据库成功地被创建，返回零，如果发生错误，为非零。

 

－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－－

再看例子：

      很多人用到MySQL来开发一些项目，有时为了性能，我们会直接用C语言来开发相关的模块，尤其在我们的web应用中，虽然PHP、JSP等脚本均 提供了MySQL的接口，但是显然直接使用C语言具有更好的安全性和性能，Michael以前用PHP开发的多个项目中就使用了C语言编写的这类接口，然 后再编译到php里面，供php脚本直接使用,这方面的话题就不多说了，下面主要说一下在Linux下如何用C语言连接MySQL数据库，并且读取里面的 数据返回，同时如何进行编译。

　　这里的大部分代码参考了MySQL发行包里面的.c源文件，大家也可以去里面找找相关的代码，下面这段代码实现了连接到本地MySQL服务器上9tmd_bbs_utf8数据库，从数据表tbb_user中根据输入的userid取得该用户的用户名并打印输出到终端。*/
#if defined(_WIN32) || defined(_WIN64) //为了支持windows平台上的编译
#include <windows.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include "mysql.h"  //我的机器上该文件在/usr/local/include/mysql下
 
//定义数据库操作的宏，也可以不定义留着后面直接写进代码
#define SELECT_QUERY "select username from tbb_user where userid = %d"
 
int main(int argc, char **argv) //char **argv 相当于 char *argv[]
{
    MYSQL mysql,*sock;    //定义数据库连接的句柄，它被用于几乎所有的MySQL函数
    MYSQL_RES *res;       //查询结果集，结构类型
    MYSQL_FIELD *fd ;     //包含字段信息的结构
    MYSQL_ROW row ;       //存放一行查询结果的字符串数组
    char qbuf[160];      //存放查询sql语句字符串
    
    if (argc != 2) { //检查输入参数
        fprintf(stderr,"usage : mysql_select <userid>\n\n");
        exit(1);
    }
    
    mysql_init(&mysql);
    if (!(sock = mysql_real_connect(&mysql,"localhost","dbuser","dbpwd","9tmd_bbs_utf8",0,NULL,0))) {
        fprintf(stderr,"Couldn't connect to engine!\n%s\n\n",mysql_error(&mysql));
        perror("");
        exit(1);
    }
    
    sprintf(qbuf,SELECT_QUERY,atoi(argv[1]));
    if(mysql_query(sock,qbuf)) {
        fprintf(stderr,"Query failed (%s)\n",mysql_error(sock));
        exit(1);
    }
    
    if (!(res=mysql_store_result(sock))) {
        fprintf(stderr,"Couldn't get result from %s\n", mysql_error(sock));
        exit(1);
    }
    
    printf("number of fields returned: %d\n",mysql_num_fields(res));
        
    while (row = mysql_fetch_row(res)) {
        printf("Ther userid #%d 's username is: %s\n", atoi(argv[1]),(((row[0]==NULL)&&(!strlen(row[0]))) ? "NULL" : row[0])) ;
        puts( "query ok !\n" ) ;
    }
    
    mysql_free_result(res);
    mysql_close(sock);
    exit(0);
    return 0;   //. 为了兼容大部分的编译器加入此行
}

/*编译的时候，使用下面的命令
gcc -o mysql_select ./mysql_select.c -I/usr/local/include/mysql -L/usr/local/lib/mysql -lmysqlclient (-lz) (-lm) 后面两个选项可选，根据您的环境情况

运行的时候，执行下面的命令
./mysql_select 1

将返回如下结果：
number of fields returned: 1
Ther userid #1 's username is: Michael
query ok !

上面的代码我想大部分都能看明白，不明白的可以参考一下MySQL提供的有关C语言API部分文档，各个函数都有详细说明，有时间我整理一份常用的API说明出来。*/
