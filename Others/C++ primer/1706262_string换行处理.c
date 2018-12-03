#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
   char charr[20];
   string str;
   cout<<"Enter a line of text:\n";
   cin.getline(charr,20);
   cout<<"You entered: "<<charr<<endl;
   getline(cin,str);//这里没有使用据点表示发，这表明这个getline()不是类方法。它将cin作为参数，指出到哪里去查找参数。
   cout<<"Enter another line of text:\n";
   cout<<"You entered: "<<str<<endl;
   cout<<"Length of string in charr after input: "
       <<strlen(charr)<<endl;
   cout<<"Length of string in str after input: "
       <<str.size()<<endl;
   return 0;
   }
