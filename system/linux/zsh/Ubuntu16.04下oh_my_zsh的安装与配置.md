## 参考文章
[Ubuntu上使终端显示Git分支(oh-my-zsh) ](http://blog.csdn.net/fengbingchun/article/details/77803322)

[oh-my-zsh的安装与基本配置](http://www.linuxidc.com/Linux/2017-10/147755.htm)

[Ubuntu 下安装oh-my-zsh](https://www.jianshu.com/p/9a5c4cb0452d)
## 前言
之前学习Laravel的时候，经常要切换git分支，然而现有的shell里面不显示分支状态总是要用`git st`，`git br -a`显得很是麻烦，于是到网上查找方案：

一开始找到是修改~/.bashrc文件，可是修改完之后总是shell显示总是会出现这样那样的小错误，无奈之下寻找其他方案，这下让我找到大神器：

> oh-my-zsh

废话不多说，进入正题

## 安装
首先交代下我的系统是ubuntu16.04LTS

### 安装zsh
```
sudo apt install zsh
```
### 安装oh-my-zsh
```
sh -c "$(wget https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh -O -)"  
```

## 配置
上述已经实现了基本的要求，但如果需要更多的功能，还要对~/.zshrc文件进行配置

### 主题设置
主题修改如图  
将robbyrussell修改为ys  

插件修改如图   
在插件栏里面添加 `zsh-syntax-highlighting zsh-autosuggestions sudo`

常用插件推荐：

插件介绍：https://github.com/robbyrussell/oh-my-zsh/wiki/Plugins

* zsh-syntax-highlighting
    语法高亮  
    ```
    git clone https://github.com/zsh-users/zsh-syntax-highlighting.git $ZSH_CUSTOM/plugins/zsh-syntax-highlighting
    ```    

* zsh-autosuggestions

    它可以记录输入过的命令并给予建议
    安装方法：
    ```
    git clone git://github.com/zsh-users/zsh-autosuggestions $ZSH_CUSTOM/plugins/zsh-autosuggestions
    ```
* sudo

    连按两次Esc添加或去掉sudo

* extract
    功能强大的解压插件
    例如：需要解压demo.tar.gz
    执行x demo.tar.gz

## autojump安装与配置
最近发现了autojump，配合zsh使用起来简直是神器的存在，所以放在最后：

**强烈推荐**
### 安装autojump
```
mac下安装
brew install autojump
ubuntu下安装
sudo apt install autojump
```
### 编辑.zshrc文件
在plugins里面添加autojump
```
plugins=(git autojump)
```
然后在文件最后一行添加
```
[[ -s ~/.autojump/etc/profile.d/autojump.sh ]] && . ~/.autojump/etc/profile.d/autojump.sh
```
最后返回命令行输入
```
source ~/.zshrc
```
大功告成，以后要到哪个目录直接
```
j + 目录名（支持智能补全，模糊查询）
```