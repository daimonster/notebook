/*关联容器是对容器概念的一个改进。关联容器将值与键关联在一起，并使用键来查找值。例如，值可以是表示柜员信息（如姓名、地址、办公号码、家庭号码和工作电话、健康计划等），而键可以是唯一的员工编号。为获取雇员信息，程序将使用键找雇员结构。前面说过，对于容器X，表达式X::value_type通常指出了存储在容器中的值类型。对于关联容器来说，表达式X::key_type指出了键的类型。
关联容器的有点在于，它提供了对元素的快速访问。与序列类似，关联容器也允许插入新元素，但不能制定元素的插入位置。原因是关联容器通常右用于确定数据放置位置的算法，以便能够快速检索信息。
关联容器通常是使用某种树来实现的。树是一种数据结构，其根节点链接到一个或两个节点，二这些节点右链接到一个或两个节点，从而形成分支结构。像链表一样，节点使得添加或删除数据项比较简单;但相对于链表，树的查找速度更快。
STL提供了4中关联容器：set,multiset、map和multimap.前两种是头文件set中定义的，而后两种是在头文件map中定义的
最简单的关联容器是set，其值类型与键相同，键是唯一的，这意味着集合中不会有多个相同的键，确实，对于set来说，值就是键。multiset类似与srt，知识可能有多个值的键相同。例如，如果键和值的类型为int，则multiset对象包含的内容可以是1、2、2、2、3、5、7、7.
在map中，值与键的类型不同，键是万恶以的，每个键只对应一个值。multimap与map相似，知识一个键可以与多个值相关联
1set示例
STL set模拟了多个概念，它是关联集合，可反转，可排序，且键是唯一的，所以不能存储多个相同的值。与vector和list相似，set也是用模板参数来制定要存储的类型:
set<string> A;
第二个模板参数是可选的，可用于指示用来对键进行排序的比较函数或对象。默认情况下，将使用模板less<>.老式C++实现可能没有提供默认值，因此必须显示制定模板参数
set<string,less<string>>A;
const int N=6;
string S1[N]={"buffoon","thinkers","for","heavey","can","for"};
set<string> A{s1,s1+N};
ostream_iterator<string,char> out(cout," ");
copy(A.begin(),A.end(),out);
与其他容器类似,set也有一个将迭代器区间作为参数的构造函数。这提供了一种将集合初始化为数组内容的简单方法。请记住，区间的最后一个元素是 
STL set模拟了多个概念，它是关联集合，可反转，可排序，且键是唯一的，所以不能存储多个相同的值。与vector和list相似，set也是用模板参数来制定要存储的类型
与其他容器类似，set也有一个将迭代器区间作为参数的构造函数。这提供了一种将集合初始化为数组内容的简单方法。请记住，区间的最后一个元素是超尾，s1+N指向数组s1尾部后面的一个位置。上述代码片段的输出表明，键是唯一的（字符串"for"在数组中出现了2次，但在集合中指出间了1次）且集合被排序
buffoon can for heavy thinekers
数学为集合定义了一些标准操作，例如，并集包含两个集合合并后的内容。如果两个集合包含相同的值，则这个值将在并集中值出现一次，这是因为键是唯一的。交集包含两个元素都有的元素。
STL提供了支持这些操作的算法。它们是通用函数，而不是方法，因此并非只能用于set对象。然而，所有set对象都自动满足使用这些算法的先决条件，即容器是经过排序的。set_union()函数接收5个迭代器参数。前来嗯个迭代器定义了第一个集合的区间，接下来的两个定义了第二个集合区间，最后一个迭代器树输出迭代器，指出将结果复制到什么位置。例如，要显示集合A和B的并集，可以这样做：
set_union(A.begin(),A.end(),B.begin(),B.end()),
    ostream_itreator<string,char> out(cout," ");
假设要将结果放到集合C中，而不是显示它，则最后一个参数应该是一个指向C的迭代器。显而易见的选择是C.begin(),但它不管用，原因由两个。首先，关联集合将键看作常量，所以C.begin()返回的迭代器是常量迭代器，不用做输出迭代器。不直接使用C.begin()的第二个原因是，与copy()相似,set_union()将覆盖容器中已有的数据，并要求容器由足够的空间容纳新信息。C是空的，不能满足这种要求。但前面讨论的模板insert_iterator可以解决这两个问题。前面说过，它可以将复制转换为插入。另外，它可以将复制转换为插入。另外，它还模拟了输出迭代器概念，可以用它将信息写入容器。因此，可以创建一个匿名insert_iteratot,将信息复制给C。前面说过，其构造函数将容器名称和迭代器作为参数：
set_union(A.begin(),A.end(),B.begin(),b.end(),insert_iterator<set<string>>(c,c.begin()));
函数set_intersection()和set_difference()分别查找交际和获得两个集合的差，它们的接口与set_union()相同
因为排序决定了插入的位置，所以这种类只指定要插入的信息，而不指定位置的插入方法如：
string s("tennis");
A.insert(s);
B.insert(A.begin(),A.end());*/
#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
int main()
{
    using namespace std;
    const int N=6;
    string s1[N]={"buffoon","thinkers","for","can","for"};
    string s2[N]={"metal","any","food","elegant","diliver","for"};
    set<string> A(s1,s1+N);
    set<string> B(s2,s2+N);
    ostream_iterator<string,char> out(cout," ");
    cout<<"Set A:";
    copy(A.begin(),A.end(),out);
    cout<<endl;
    cout<<"Set B: ";
    copy(B.begin(),B.end(),out);
    cout<<endl;
    cout<<"Union of A and B:\n";
    set_union(A.begin(),A.end(),B.begin(),B.end(),out);
    cout<<endl;
    cout<<"Intersection of A and B:\n";
    set_intersection(A.begin(),A.end(),B.begin(),B.end(),out);
    cout<<endl;
    cout<<"Differrnce of A and B:\n";
    set_difference(A.begin(),A.end(),B.begin(),B.end(),out);
    cout<<endl;
    set<string> C;
    cout<<"Set C:\n";
    set_union(A.begin(),A.end(),B.begin(),B.end(),insert_iterator<set<string> >(C,C.begin()));
    copy(C.begin(),C.end(),out);
    cout<<endl;
    
    string s3("grungy");
    C.insert(s3);
    cout<<"Set C after insertion:\n";
    copy(C.begin(),C.end(),out);
    cout<<endl;
    
    cout<<"Showing a range:\n";
    copy(C.lower_bound("ghost"),C.upper_bound("spool"),out);
    cout<<endl;
    return 0;
}

