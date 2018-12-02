## 简介
Tmux 是一个终端复用软件,记录一下我对Tmux的一些设置

## 下载安装插件

这是我觉得tmux下非常好用的一个插件,因为有一些快捷键需要在安装完这个插件之后才能使用
```
cd
git clone https://github.com/gpakosz/.tmux.git
ln -s -f .tmux/.tmux.conf
cp .tmux/.tmux.conf.local .
```

***
## Tmux命令行操作
```
tmux new -s foo # 新建名称为 foo 的会话
tmux ls # 列出所有 tmux 会话
tmux a # 恢复至上一次的会话
tmux a -t foo # 恢复名称为 foo 的会话，会话默认名称为数字
tmux kill-session -t foo # 删除名称为 foo 的会话
tmux kill-server # 删除所有的会话 
```
---

## Tmux session快捷键
```
<prefix> $重命名当前session
<prefix> s选择session列表
<prefix> d退出当前session
```

---
## Tmux window快捷键
```
<prefix> ,重名当前window
<prefix> c新建window
<prefix> n、p分别对应切换到上、下个window
<prefix> &关闭当前window
<prefix> 1-9切换对应数字的window
```
---

## Tmux pane快捷键
```
<prefix> 上下左右选择pane  
<prefix> < and <prefix> > let you swap panes
<prefix> x关闭当前pane
<prefix> -横向分割pane
<prefix> `_`竖向分割pane
<prefix> p显示每个pane对应的数字,按下数字就能选择对应的pane
```
***

## 插件的一些快键键
```
<prefix> e编辑tmux设置文件
<prefix> r重载tmux设置文件
<prefix> b显示复制缓冲区的内容
<prefix> P选择粘贴复制缓冲区的所选内容
```

## 复制模式
首先要修改一下设置,这样就能是你在vi里面同样使用复制模式
```
vi ~/.tmux.conf.local
```
然后在257行的注释取消,也就是使
```
set -g mode-keys vi
```
生效

然后按下
```
<prefix> r #使得设置生效
```

接下来是进入复制模式的操作

+ `<prefix> Enter` 或 `<prefix> [`
+ 进入复制模式,这个时右上角会出现黄色的方框
+ 将光标移动到你想复制的行,按下行空格键
+ 选择完之后,按下y完成复制
+ 在应该粘贴的地方,按`<prefix> p`进行粘贴

这里复制粘贴的操作相同与vim里面的操作
Bindings for copy-mode-vi:
* v begins selection / visual mode
* C-v toggles between blockwise visual mode and visual mode
* H jumps to the start of line
* L jumps to the end of line
* y copies the selection to the top paste-buffer
* Escape cancels the current operation
