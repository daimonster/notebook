## 前言

如果你的入口文件main.c和依赖的文件不是在同一个目录中的，使用Autotools来管理项目的时候会稍微复杂一下。

在不同的目录下，项目会生成*.a文件的静态连接（静态连接相当于将多个.o目标文件合成一个）。main.c会通过静态连接方式来实现连接。

## 执行过程

1. 源代码例子

    这个例子中会加入libevent和pthread，让例子稍显复杂，这样可以详细的介绍不同目录下的Autotools的使用。

    我们创建两个目录：

    demo/  ：放置helloworld.c主文件

    src/ ：放置output.c output.h 函数文件

    demo中文件main.c：
    ```
    #include "../src/output.h"
    #include <stdio.h>
    #include <string.h>

    int main(int argc,char * argv[])
    {
        int n=15;
        printf("hello world %d \n",n);
        int test = output("from helloword.c");
        return 0;
    }
    ```

    output.h文件： 
    ```
    #ifndef _OUTPUT_H
    #define _OUTPUT_H
    int output(char* data);
    #endif
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

2. 创建Makefile.am文件

    在项目根目录下先创建Makefile.am文件
    ```
    AUTOMAKE_OPTIONS=foreign  
    SUBDIRS = src demo
    ```

    在demo/目录下创建Makefile.am文件
    ```
    AUTOMAKE_OPTIONS = foreign
    # AM_CPPFLAGS = -g -I$(top_srcdir)/src/ 

    bin_PROGRAMS = helloworld
    helloworld_SOURCES = helloworld.c
    helloworld_LDADD = ../src/libsrc.a  
    ```

    在src/目录下创建Makefile.am文件
    ```
    noinst_LIBRARIES = libsrc.a
    libsrc_a_SOURCES = output.c
    include_HEADERS = output.h
    ```
    说明：src/目录下面不加include_HEADERS也是可以运行的，但是在使用make dist打包命令后，并不会将include/文件夹打包进去，所以还是需要加上include_HEADERS。

3. 执行Autoscan命令
    第一步，我们需要在我们的项目目录下执行autoscan命令。这个命令主要用于扫描工作目录，并且生成configure.scan文件。并且configure.scan需要重命令成configure.ac，然后编辑这个配置，我们才能继续执行后面的命令。<br>修改configure.ac文件，主要添加AC_PROG_RANLIB（生成静态库）；AC_PROG_LIBTOOL （用来生成动态库）

    ```
    #                                               -*- Autoconf -*-
    # Process this file with autoconf to produce a configure script.

    AC_PREREQ([2.69])
    AC_INIT(helloworld, 2.0, ggao@micron.com)
    AM_INIT_AUTOMAKE(helloworld, 2.0)
    AC_CONFIG_SRCDIR(demo/helloworld.c)
    AC_CONFIG_HEADERS([config.h])

    # Generate static lib
    AC_PROG_RANLIB ##注意添加

    # Checks for programs.
    AC_PROG_CC

    # Checks for libraries.

    # Checks for header files.
    AC_CHECK_HEADERS([string.h])

    # Checks for typedefs, structures, and compiler characteristics.

    # Checks for library functions.

    AC_CONFIG_FILES([Makefile
                    demo/Makefile
                    src/Makefile])
    AC_OUTPUT
    ```

4. 执行 aclocal

5. 运行 autoconf

6. 运行 autoheader

7. 手动添加必要的文件 NEWS，README，AUTHORS，ChangeLog

8. 执行 automake --add-missing

9. 执行 ./configure 生存 Makefile

====>>> 至此 Makefile 生成完毕。
如果要继续安装，

10. $ make

11. $ sudo make install  即可将可执行文件安装在 /usr/local/bin/ 目录下，以后就可以直接使用啦

12.  $ sudo make uninstall 即可将安装的可执行文件从 /usr/local/bin 目录下移除

如果要发布你的软件，

13. $ make dist  即可打包生成 xxx-version.tar.gz 文件

如果要清理中间文件，

14. make clean

15. make distclean

***
## Autotools运行流程
流程总结：

1. 执行autoscan命令。这个命令主要用于扫描工作目录，并且生成configure.scan文件。

2. 修改configure.scan为configure.ac文件，并且修改配置内容。

3. 执行aclocal命令。扫描 configure.ac 文件生成 aclocal.m4文件。

4. 执行autoconf命令。这个命令将 configure.ac 文件中的宏展开，生成 configure 脚本。

5. 执行autoheader命令。该命令生成 config.h.in 文件。

6. 新增Makefile.am文件，修改配置内容

7. 执行automake --add-missing命令。该命令生成 Makefile.in 文件。

8. 执行 ./congigure命令。将Makefile.in命令生成Makefile文件。

9. 执行make命令。生成可执行文件。