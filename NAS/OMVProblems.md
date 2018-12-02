## apt install安装遇到的python3的问题
解决方案如下：  
> In short open /usr/lib/python3.5/weakref.py and change line 109 to:
```
def remove(wr, selfref=ref(self), _atomic_removal=_remove_dead_weakref):
```
> And line 117 to:
```
_atomic_removal(d, wr.key)
```
> Note you need to do this with spaces, not tabs as this will cause other errors.  
***  

## 错误删除硬件之后在文件系统中留下missing entry
需要修改两个地方:  
1. /etc/openmdiavault/config.xml 文件中 hdparm标签和fstab标签中的错误硬件内容
1. /etc/fstab中错误硬件内容
1. 重启电脑,大功告成! 