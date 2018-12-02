/*智能指针是行为类似于指针的类对象，但这种对象还有其他功能。本节介绍三个可帮助管理动态内存的只能指针模板。
当remodel()这样的函数终止(不管是正常终止，还是出现了异常终止)，本地变量都将从栈内存中删除——因此指针ps占据的内存将被释放。如果ps指向的内存也被释放，那该由多好。如果ps有一个析构函数，该析构函数将在ps国企时释放它指向的内存。因此ps的问题在于,它只是一个常规指针，不是由析构函数的类对象。如果它是对象，则可以在对象过期时，让它的析构函数删除指向的内存。这正是auto_ptr\unique_ptr和shared_ptr背后的思想
使用只能指针
这三个智能指针模板都定义了类似指针的对象，可以将new获得(直接或间接)的地址赋给这种对象。当只能指针过期时，其析构函数将使用delete来释放内存.因此，如果将new返回的地址赋给这些对象，将无序记住稍后释放这些内存：在只能指针过期时，这些内存将自动被释放。
要创建智能指针对象，必须包含头文件memory，该文件模板定义。然后使用通常的模板语法来实例化所需类型的指针
因此，请求X类型的auto_ptr将获得一个指向X类型的auto_ptr:
auto_ptr<double> pd(new double);
auto_ptr<string> ps(new string);
new double是呢我返回的指针，指向新分配的内存块。它是狗仔auto_ptr<double>的cachi，即对应与原型中形参p的实参。同样new string也是构造函数的实参，其他两种智能指针使用同样的语法
因此要转换remodel()函数，鹰按下面3个步骤进行：
1包含头文件momorey;
2将指向string的指针替换为指向string的只能指针的对象;
3删除delete语句
下面是使用suto_ptr修改函数的结果：
#cinlude<memory>
void remodel(std::string & str)
{ 
    std::auto_ptr<std::string>ps (new std::string(str));
    ...
    if(wired_thing())
        throw except();
    str=*ps;
    return
}
注意到只能指针模板位于名称空间std中。程序清单16.5是一个简单的程序，要是了如何使用全部三种只能指针。要编译该程序，您的编译器必须支持C++11新增的类share_ptr和unique_ptr.每个指针能指针都放在一个代码块内，这样离开代码块时，指针将过期。*/
#include <iostream>
#include <string>
#include <memory>
using namespace std;
class Report
{
private:
    string str;
public:
    Report(const string s):str(s)
        {cout<<"Object created!\n";}
    ~Report(){cout<<"Object deleted!\n";}
    void comment() const {cout<<str<<"\n";}
};
int main()
{{
    auto_ptr<Report> ps (new Report("using auto_ptr"));
    ps->comment();
}
{
    shared_ptr<Report> ps (new Report("using share_ptr"));
    ps->comment();
}
{
    unique_ptr<Report> ps (new Report("using unique_ptr"));
    ps->comment();
}
    return 0;
}


