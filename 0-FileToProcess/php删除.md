一、删除php的相关包及配置

sudo apt-get autoremove php7*
二、删除关联

sudo find /etc -name "*php*" |xargs  rm -rf 
三、清除dept列表

sudo apt purge `dpkg -l | grep php| awk '{print $2}' |tr "\n" " "`
四、检查是否卸载干净（无返回就是卸载完成）

 dpkg -l | grep php7.0
