//现在您知道可以使用不同方式来创建string对象，显示string对象的内容、将数据读取和附加到string对象、给string对象赋值以及将两个string兑现连接起来。除此之外，还能做些什么呢？
//可以比较字符串。string类对全部6个关系运算符都进行了重载。如果在机器排列序列中，一个对象位于另一个对象前面，则前者被视为小于后者。如果机器排列序列为ASCII码，则数字将小于大写字符，则大写字符小于消息字符。对于每个关系运算符，都已三种方式被重载，一边能够将string对象与另一个string对象、C-风格字符串进行比较，并能够将C-风格字符串与string对象进行比较：
/*可以确定字符串的长度。size()和length()成员函数都返回字符串中的字符数：
为什么这两个函数能完成相同的任务呢？length()成员来自较早版本的string类，而size()则是为提供STL兼容性而添加的
可以以多种不同的方式在字符串中搜索给定的子字符串或字符。
rfind()方法查找子字符串或字符最后一次出现的位置;find_first_of()方法在字符串中查找参数中任何一个字符首次出现的位置。例如，现面的语句返回r在"cobra"中的位置，因为这是“hark”中各个字母在"cobra"首次出现的位置。find_last_of的方法于此相同，知识它查找的是最后一次出现的位置。
Hangman拼字游戏。该游戏将一系列的单词存储在一个string对象数组中，然后随机选择一个单词，让人猜测单词的字母。如果才做6次，玩家就输了。该程序使用find()函数来检查玩家的猜测，使用+=运算符创建一个string对象来记录玩家的错误猜测。为记录玩家猜对的情况，程序创建了一个单词，其长度与被猜的单词相同，但包含的是连字符。玩家猜对字符时，将用该字符替换相应的连字符。
find从字符串的pos位置开始，查找子字符串str。如果找到，则返回该子字符串首次出现的首字符的索引*/
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<cctype>
using std::string;
const int NUM=26;
const string wordlist[NUM]={"apiary","beetle","cereal","danger","ensign","fllrid","garge","health","insult",
 "jackal","keeper","loaner","manage","nonce","onset","plaid","quilt","remote",
 "stolid","train","useful","valid","whence","xenon","yearn","aippy"};
 using namespace std;
 int main()
 {
     srand(std::time(0));
     char play;
     cout<<"Wil you play a word game?<y/n>";
     cin>>play;
     play=tolower(play);
     while(play=='y')
     {
         string target=wordlist[rand()%NUM];
         int length=target.length();
         string attempt(length,'-');//字符长度的连字符
         string badchars;
         int guesses=6;
         cout<<"Guess my secret word. It has "<<length
             <<" letters,and you guess\n"<<"one letter at a time.You get "<<guesses<<" wrong guesses.\n";
         cout<<"Your word: "<<attempt<<endl;
         while(guesses>0&&attempt!=target)
         {
             char letter;
             cout<<"Guess a letter: ";
             cin>>letter;
             if(badchars.find(letter)!=string::npos||attempt.find(letter)!=string::npos)
             {
                 cout<<"You already guessed that.Try again.\n";
                 continue;
             }
             int loc=target.find(letter);
             if(loc==string::npos)
             {
                 cout<<"Oh,bad guess!\n";
                 --guesses;
                 badchars+=letter;
              }
              else
              {
                 cout<<"Good guess!\n";
                 attempt[loc]=letter;
                 while(loc!=string::npos)
                 {
                     attempt[loc]=letter;
                     loc=target.find(letter,loc+1);
                 }
              }
              if(attempt!=target)
              {
                  if(badchars.length()>0)
                      cout<<"Bad choices: "<<badchars<<endl;
                  cout<<guesses<<" bad guesses left\n";
              }
          }
              if(guesses>0)
                  cout<<"That's right:"<<target<<endl;
              else
                  cout<<"Sorry.,the word is "<<target<<".\n";
              cout<<"Will you play another?<y/n>";
              cin>>play;
              play=tolower(play);
          
          
      }
      cout<<"Bye";
      return 0;
}

