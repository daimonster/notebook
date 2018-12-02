## 简介
top命令是Linux下常用的性能分析工具，能够实时显示系统中各个进程的资源占用状况，类似于Windows的任务管理器。  

## 示例
```
top - 01:06:48 up  1:22,  1 user,  load average: 0.06, 0.60, 0.48
Tasks:  29 total,   1 running,  28 sleeping,   0 stopped,   0 zombie
Cpu(s):  0.3% us,  1.0% sy,  0.0% ni, 98.7% id,  0.0% wa,  0.0% hi,  0.0% si
Mem:    191272k total,   173656k used,    17616k free,    22052k buffers
Swap:   192772k total,        0k used,   192772k free,   123988k cached

PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND
root      16   0  7976 2456 1980 S  0.7  1.3   0:11.03 sshd
root      16   0  2128  980  796 R  0.7  0.5   0:02.72 top
root      16   0  1992  632  544 S  0.0  0.3   0:00.90 init
root      34  19     0    0    0 S  0.0  0.0   0:00.00 ksoftirqd/0
root      RT   0     0    0    0 S  0.0  0.0   0:00.00 watchdog/0
```

## 参数说明
统计信息区前五行是系统整体的统计信息。第一行是任务队列信息，同 uptime 命令的执行结果。其内容如下：  
```
01:06:48    当前时间
up 1:22    系统运行时间，格式为时:分
1 user    当前登录用户数
load average: 0.06, 0.60, 0.48    系统负载，即任务队列的平均长度。三个数值分别为 1分钟、5分钟、15分钟前到现在的平均值。
```
第二、三行为进程和CPU的信息。当有多个CPU时，这些内容可能会超过两行。内容如下：  
```
total 进程总数
running 正在运行的进程数
sleeping 睡眠的进程数
stopped 停止的进程数
zombie 僵尸进程数
Cpu(s): 
0.3% us 用户空间占用CPU百分比
1.0% sy 内核空间占用CPU百分比
0.0% ni 用户进程空间内改变过优先级的进程占用CPU百分比
98.7% id 空闲CPU百分比
0.0% wa 等待输入输出的CPU时间百分比
0.0%hi：硬件CPU中断占用百分比
0.0%si：软中断占用百分比
0.0%st：虚拟机占用百分比
```

最后两行为内存信息。内容如下：
```
Mem:
191272k total    物理内存总量
173656k used    使用的物理内存总量
17616k free    空闲内存总量
22052k buffers    用作内核缓存的内存量
Swap: 
192772k total    交换区总量
0k used    使用的交换区总量
192772k free    空闲交换区总量
123988k cached    缓冲的交换区总量,内存中的内容被换出到交换区，而后又被换入到内存，但使用过的交换区尚未被覆盖，该数值即为这些内容已存在于内存中的交换区的大小,相应的内存再次被换出时可不必再对交换区写入。
```