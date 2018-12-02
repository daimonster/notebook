## string的操作
### String类的参考网址
[C++string参考](http://www.cplusplus.com/reference/string/)

### 搜索自己字符串
```
string longer("This is a funny hat.");
```
找找字符串里面的数据,可以这么做
```
string shorter("hat");
int loc1 = longer.find(shorter);
int loc2 = longer.find(shorter,3);
int loc3 = longer.find("hat");
```

### 变成子串
```
std::string str="We think in generalities, but we live in details."; // (quoting Alfred N. Whitehead)
std::string str2 = str.substr (3,5);     // "think",从3之后的5个字符
std::size_t pos = str.find("live");      // position of "live" in str
std::string str3 = str.substr (pos);     // get from "live" to the end
std::cout << str2 << ' ' << str3 << '\n';
```
### copy操作
```
char buffer[20];
std::string str ("Test string...");
std::size_t length = str.copy(buffer,6,5);
buffer[length]='\0';
std::cout << "buffer contains: " << buffer << '\n';
```