## 读取文件
```
// 文件指针
ifstream fin(configfileplace.c_str());
// 按行读取文件
while(getline(fin,line)){
    cout << line << endl;
}
```
## 写入文件
```
ofstream fout("config",ios::out | ios::app);// ios::out | ios::app 的意思是只追加文件 C++ pri page775
fout << "filetest" << endl;
```

## 检查文件的打开状态
```
fin.is_open
```