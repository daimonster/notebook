## all_of
***
### 功能描述
如果在[first,last)范围内的数组进行判断，
如果pred返回`true`返回`true` 
否则返回`false`
等同于
```
template<class InputIterator, class UnaryPredicate>
  bool all_of (InputIterator first, InputIterator last, UnaryPredicate pred)
{
  while (first!=last) {
    if (!pred(*first)) return false;
    ++first;
  }
  return true;
}
```
***
### 参数
* first last 数组的范围[first,last)
* pred 单个参数的函数，接受前面数组给的每个元素，判断并给出返回值

***
### 范例
```
#include <iostream>
#include <algorithm>
#include <array>

int main(){
    std::array<int,8> foo = {3,5,7,12,13,17,19,23};
    if(std :: all_of(foo.begin(),foo.begin() + 3,[](int i){return i%2;}))
        std::cout << "All the elements are odd numbers.\n";
    else 
        std::cout << "Not all the elements are odd numbers.\n";
    return 0;
}
```
输出:
```
Not all the elements are odd numbers.
```