## 安装命令：

```
sudo apt install automake autoconfig
```

***
## 简单的例子
automake实例:

helloworld.c 
```
#include <stdio.h>  
#include <string.h>  
extern int output(char* data);  
int main()  
{  
    int n=15;  
    printf("hellow world %d \n",n);  
    output("from helloword.c");  
    return 0;  
}  
```

output.c
```
#include <stdio.h>  
#include <string.h>  
int output(char* data)  
{  
    printf("output data=%s\n",data);  
    return 0;  
}  
```

***
## auto使用流程
1. 执行命令：
    ```
    autoscan
    ```

    注意如果是第一次使用autoscan会报错如下
    ```
    Unescaped left brace in regex is deprecated, passed through in regex; marked by <-- HERE in m/\${ <-- HERE [^\}]*}/ at /usr/bin/autoscan line 361.
    ```
    这是因为现在的Perl不支持左大括号，我们根据提示把相应行文件对应行中的大括号(包括左右两个大括号)去掉
    
2. 修改configure.scan并改名为configure.ac
    ```
    sudo vi configure.scan
    ```

    ```
    # -*- Autoconf -*-

    # Process this file with autoconf to produce a configure script.

    AC_PREREQ([2.68])

    AC_INIT([helloworld], [2.0], [542335496@qq.com])# 修改此行

    AM_INIT_AUTOMAKE(helloworld,2.0) # 修改此行

    AC_CONFIG_SRCDIR([output.c])

    AC_CONFIG_HEADERS([config.h])

    # Checks for programs.

    AC_PROG_CC

    # Checks for libraries.

    # Checks for header files.

    AC_CHECK_HEADERS([string.h])

    # Checks for typedefs, structures, and compiler characteristics.

    # Checks for library functions.

    AC_OUTPUT(Makefile)# 修改此行
    ```

    修改文件名称：
    ```
    mv configure.scan configure.ac
    ```

3. 执行命令：
    ```
    aclocal  #产生aclocal.m4文件、即为配置成功
    ```

    ```
    autoconf #产生configure文件、即为配置成功
    ```

4. 执行命令：
    ```
    autoheader #生成config.h.in 
    ```

5. 创建和编辑Makefile.am文件:
    ```
    vi Makefile.am
    ```

    内容为：
    ```
    AUTOMAKE_OPTIONS= foreign 

    bin_PROGRAMS= helloworld 

    helloworld_SOURCES= helloworld.c output.c
    ```

    + 其中的AUTOMAKE_OPTIONS为设置automake的选项。automake提供了三种软件等级：foreign、gnu和gnits，让用 户选择采用，默认等级为gnu。在本例使用foreign等级，它只检测必须的文件。

    + bin_PROGRAMS定义要产生的执行文件名。如果要产生多个执行文件，每个文件名用空格隔开。

    + helloworld_SOURCES定义“helloworld”这个执行程序所需要的原始文件。如果”helloworld”这个程序是由多个原始文件所产生的，则必须把它所用到的所有原 始文件都列出来，并用空格隔开。例如：若目标体“helloworld”需要“helloworld.c”、“sunq.c”、“helloworld.h”三个依赖文件，则定义 helloworld_SOURCES=helloworld.c sunq.c helloworld.h。要注意的是，如果要定义多个执行文件，则对每个执行程序都要定义相应的file_SOURCES。

    + AM_CPPFLAGS 编译器的-I参数

    + SUBDIRS 在处理顶层目录之前，先递归处理子目录

    + $(top_srcdir) 源代码所在目录

    + $(top_builddir) 编译顶层目录

6. 执行命令
    ```
    automake --add-missing 生成Makefile.in文件,无输出信息即可成功
    ```

7. 执行命令
    ```
    sudo ./configure && sudo make && sudo make install
    ```

10. 运行：
    ```
    ./helloworld
    ```

11. 打包发布,生成helloworld-2.0.tar.gz：
    ```
    make dist
    ```

