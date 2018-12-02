## windows
### windows下javac乱码问题
```
将这句 
alias javac=’javac -J-Dfile.encoding=UTF-8’ 
alias java=’java -Dfile.encoding=UTF-8’ 
复制到文件C:\Program Files\Git\etc\bash.bashrc最后一行，保存 
重启gitbash，问题即刻解决~
```