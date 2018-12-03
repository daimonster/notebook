/*该程序使用find()来检查玩家以前是否才过某个字符。如果是，则它要么位于badchars字符串(猜错)中，要们位于attempt字符串中：
if(badchars.find(letter)!=string::npos||attempt.find(letter)!=string::npos)
npos变量是string类的静态成员，它的值是string对象能存储的最大字符串。由于索引从0开始，所以它比最大的索引值大1,因此可以使用它来表示没有查找到字符或者字符串。
该程序利用了这样一个事实+=运算符的某个重载版本能够将一个字符附加到字符串中：
badchars+=letter;
该程序的核心是吃哦逆检查玩家选择字符是否位于被猜测的单词中开始的：
如果loc是一个有效的值，则可以将该字母放置在答案字符串的相应位置：
attempt[loc]=letter;
然而，由于字母在被猜测的单词中可能出现多次，所以程序必须一直进行检查。该程序使用了find()的第二个可选参数，该函数可以指定从字符串什么位置开始搜索。因为字母是在位置loc找到的，所以下一次搜索应该从loc+1开始.while循环是搜索一直进行下去，直到找不到该字符位置.如果loc位于字符串尾，则标明find()没有找到该字符。
loc=target.find(letter,loc+1);
while(loc!=string::npos)
{
    sttempt[loc]=letter;
    loc=target.find(lettwe,loc+1);
}
string还提供了哪些功能
string库提供了很多其他的工具，包括完成下述功能的函数：删除字符串的部分或全部内容，用一个字符串的部分或全部内容替换另一个字符串的部分或全部内容、将数据插入到字符串中或删除字符串中的数据、将一个字符串的部分或全部内容与另一个字符串的部分或全部内容进行比较、从字符串中提取子字符串、将一个字符串中的内容复制到另一个字符串中、交换两个字符串的内容。这些函数中的大多数都被重载，以便能够处理C-风格字符产和string对象。
首先看自动调整大小的功能，每当程序将一个字母附加到字符串末尾时将发生什么呢？不能仅仅将已有的字符串加大，因为相邻的内存可能被占用了。因此，可能需要非陪一个新的内存块，并将原来的内容复制到新的内存单元中，如果执行大量这样的操作，效率将非常低，因此很多C++实现分配一个比实际字符串大的内存块，为字符串提供了增大空间。然而， 很多在哦富川不断增大，超过了内存块的大小，程序将分配一个大小为原来两倍的新内存块，以提高足够的增大空间，避免不断地分配新的内存块，方法capacity()返回当前分配给字符串的内存块大小，而reserve()方法让您能够请求内存块的最小长度。*/
#include<iostream>
#include<string>
int main()
{
    using namespace std;
    string empty;
    string small="bit";
    string larger="Elephants are a girl's best friend";
    cout<<"Sizes:\n";
    cout<<"\tempty: "<<empty.size()<<endl;
    cout<<"\tsmall: "<<small.size()<<endl;
    cout<<"\tlarger: "<<larger.size()<<endl;
    cout<<"Capacities:\n";
    cout<<"\tempty: "<<empty.capacity()<<endl;
    cout<<"\tsmall: "<<small.capacity()<<endl;
    cout<<"\tlarger: "<<larger.capacity()<<endl;
    empty.reserve(50);
    cout<<"Capacity after empty.reserve(50): "
        <<empty.capacity()<<endl;
    return 0;
}
/*注意，该实现使用的最小容量为15个字符，这比标准容量选择（16的倍数）小1.其他实现可能作出不同的选择
如果您由string对象，但需要C-风格字符串，该如何办呢？例如您可能想打开一个其名称存储在string对象中的文件：
string filename;
cout<<"Enter file name: ";
cin>>filename;
ostream fout;
不幸的是，open()方法使用一个C-风格的字符串作为参数：幸运的是，c_str()方法返回一个C风格字符串的指针，该C风格字符串的内容与用于调用c_str()方法的string对象相同。因此可以这样做fout.open(filename.c_str());
