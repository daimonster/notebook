## 正常的输入

C++:
```
cin>>
```
python:
```
input() 如果用list(input())可以将输入的字符或者数字一个一个分成一个列表
```
##按行输入

C++:
```
getline(cin,a)
```
python:
```
import sys

sys.stdin.readlines():
```

## C++中想要删掉一个string中的空格号
```
if(!s.empty())
{
       while( (index = s.find(' ',index)) != string::npos)
       {
            s.erase(index,1);
        }

}
```

## C++
```
#include <iomanip>
cout << setprecision(1) << fixed << (sum/TIMES) << endl;
```