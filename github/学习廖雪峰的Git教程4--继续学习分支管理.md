
## 查看分支 
```
git branch -a 查看远程分支
git branch 查看本地分支
```
## 创建分支
```
git checkout -b branch-name 
```
在远程创建一个属于自己的分支

## 删除分支
```
git checkout -d branch-name 
```
## 与远程分析相关联
```
git checkout -b branch-name origin/branch-name 
```
在本地创建一个跟远程对应的分支
```
git branch --set-upstream branch-name origin/branch-name 
```
建立本地分支与远程分支的关联

## 推送分支
```
git config --global push.default simple
```
此设置是 Git 命令 push 的默认模式为 simple，当我们执行 git push 没有指定分支时，自动使用当前分支，而不是报错。
```
git push origin branch-name 	
```
推送本地内容到远程分支
