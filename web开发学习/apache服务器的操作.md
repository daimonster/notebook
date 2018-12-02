## 删除apache服务器
```
sudo service apache2 stop
update-rc.d -f apache2 remove
sudo apt remove --purge apache2
sudo apt autoremove
```