## 参考文章
[git 排错 fatal: 'git status --porcelain' failed in submodule abi/cpp](http://blog.csdn.net/u013377887/article/details/64124197)

## fatal: 'git status --porcelain' failed in submodule abi/cpp

这个问题的出现的原因是子目录中的代码是使用git进行管理的，这与我们现在使用的文件夹里面git配置有冲突

解决方案:  
递归删除子目录中的.git和.gitignore文件
```
find -name '.git*' |xargs rm -rf
```
***

## 本地有已经不存在远程分支
### 解决方案
```
git fetch -p #清除远程已经不存在的分支的跟踪分支
```
***  

## git add 显示中文乱码
输入：
```
git config --global core.quotepath false
```
core.quotepath设为false的话，就不会对0x80以上的字符进行quote。中文显示正常。
***  

## git log 中文乱码
输入：
```
git config --global i18n.commitencoding utf-8
git config --global i18n.logoutputencoding utf-8
export LESSCHARSET=utf-8
```
上面export方法可能再linux系统中有效，但是win10之中，必须在电脑->属性->高级环境设置->环境变量中添加`LESSCHARSET`,`utf-8`

## refusing to merge unrelated histories
```
git pull origin master --allow-unrelated-histories
```
