//下面更深入第探讨以下tring输入函数。正如前面指出的，这两个函数都自动调整目标string的大小，使之与输入匹配。但也存在一些限制。第一个限制因素是string对象的最大允许长度，第二个限制因素是程序可以使用的内存量。
/*string版本的getline()函数从输入中读取,并将存储到目标string中，直到发生下列三种情况之一
1到达文件尾，在这种情况下，输入列eofbit将被设置，这一位这方法fai()和eof()都将返回true;
2遇到分界字符（默认为\n），在这种情况下，将把分界字符从输入流中删除，但不存储它
3读取的字符数达到最大允许值(string::npos和可供分配的内存字节数中较小的一个)，在这种情况下，将设值输入流的failbit，这一位这方法fail()将返回true.
输入流对象由一个统计系统，用于跟踪流的错误状态，在这个系统中，检测到文件尾后将设置eofbit寄存器,检测到输入错误时将设置failbit寄存器，出现无法识别的故障（如硬盘故障）时将设置badbit寄存器,一切顺利时将设置goodbit寄存器。
sstring版本的operator>>()函数的行为与此类似，只是它不断读取，直到遇到空白字符并将其留在输入队列中，而不是不断读取，直到遇到分节字符并将其丢弃。空白字符指的是空格、换行符和制表符，更普遍地说，是任何将其作为参数来调用isspacc()时，该函数返回true的字符
本书前面由多个控制台string输入示例，由于用于string对象的输入函数使用输入流，嫩够识别文件尾，因此也可以使用它们来从文件中读取输入。程序是从一个文件中读取字符串的简短示例，它假设文件中包含用冒号字符分隔的字符串，并使用指定分界符getling()方法。然后，显示字符串给它们编号，每个字符占一行。*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
int main()
{
    using namespace std;
    ifstream fin;
    fin.open("tobuy.txt");
    if(fin.is_open()==false)
    {
        cerr<<"Can't open file. Bye.\n";
        exit(EXIT_FAILURE);
    }
    string item;
    int count=0;
    getline(fin,item,':');
    while(fin)
    {
        ++count;
        cout<<count<<": "<<item<<endl;
        getline(fin,item,':');
     }
     cout<<"Done\n";
     fin.close();
     return 0;
}
