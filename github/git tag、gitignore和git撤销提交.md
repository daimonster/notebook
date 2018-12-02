[TOC]
## 前言
最近在git的使用过程中遇到了一些新的问题，所以写下来方便自己回忆。

## git tag

### 打标签
```
git tag -a v1.00 -m "注释"
```
git tag 打标签命令 -a 添加标签 -m 添加注释

### 切换标签
    git checkout v1.00

就像切换分支一样

但你可以在这个标签上修改代码，但是不会影响其它分支的代码，如果保存在tag代码上修改，就要创建分支，如下：

    git checkout -b branch_name

### 提交标签
```
git push origin -tags
```
等同于git push 只不过将master改成了-tags，说明是提交标签

### 删除标签
    git tag -d v1.00

-d delete删除标签

### 查看标签
    git tag

***

## .gitignore用法
### 简介
通常如果在git文件夹里面如果有你不想到git仓库的文件，这就需要.gitignore文件了

### 使用方法
.gitignore使用起来很简单,就是把你不想提交的文件名字写到.gitignore里面就行
而且支持通配符,例如:
```
# 忽略指定文件
HelloWrold.class

# 忽略指定文件夹
bin/
bin/gen/

# 忽略.class的所有文件
*.class

# 忽略名称中末尾为ignore的文件夹
*ignore/

# 忽略名称中间包含ignore的文件夹
*ignore*/
```

### 加入已经忽略的文件
如果需要加入某些已经被忽略掉的文件.需要
```
git add -f filename 
```
如果某些文件意外加入到缓存中去了,需要
```
git rm HelloWorld.class --cached
rm 'HelloWorld.class'
```
***

## git add、git commit已经添加的文件撤销
文件撤销的情况分下面三种
1. git add文件，但是没有commit
    ```
    `git status`查看已经添加的文件

    `git reset HEAD`撤销所有已经add的文件

    `git reset HEAD filename`撤销已经add中的某个文件
    ```
1. 即add又commit但是没有push的时候
    ```
    `git log`查看commit ID

    `git reset commit_id`返回提交的的节点(不加--hard是保留修改后的代码,加上--hard直接回到上次提交的状态,代码也改变)
    ```
1. 对于已经push上去的代码
    ```
    `git revert HEAD` 撤销前一次 commit

    `git revert HEAD^`撤销前前一次 commit

    `git revert`与`git reset`不同的地方在于,reset是回到前面的版本 ,revert是提交一个新的版本，将需要revert的版本的内容再反向修改回去，版本会递增，不影响之前提交的内容。
    ```
## 参考文章
[Git中tag的用法](http://blog.csdn.net/jeffasd/article/details/49863335)
[git add ， git commit 添加错文件 撤销](http://blog.csdn.net/kongbaidepao/article/details/52253774)