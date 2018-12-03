//我们先看一个完整的程序，它使用部分排序规则来确定要使用那个模板来定义。程序清单8.14由两个来显示数组内容的模板定义。第一个定义（模板A）假设作为参数传递的数组中包含了要显示的数据第二个定义（模板B）假设数组元素为指针，指向要显示的数据。
#include<iostream>
template<typename T>
void ShowArray(T arr[],int n);
template <typename T>
void ShowArray(T * arr[],int n);
struct debts
{
    char name[50];
    double amount;
};
using namespace std;
int main()
{
    int things[6]={13,31,103,301,310,130};
    struct debts mr_E[3]={
        {"Ima WOlfe",2400.0},
        {"Ura Foxe",1300.0},
        {"Iby Stout",1800.0}
    };
    double * pd[3];
for(int i=0;i<3;i++)
{
    pd[i]=&mr_E[i].amount;
}
    ShowArray(things,6);
    cout<<"Listing Mr.E's debt:\n";
    ShowArray(pd,3);
    return 0;
}
template <typename T>
void ShowArray(T arr[],int n)
{
    cout<<"templat A\n";
    for(int i=0;i<n;i++)cout<<arr[i]<<' ';
    cout<<endl;
    }
    template <typename T>
void ShowArray(T *arr[],int n)
{
    cout<<"templat B\n";
    for(int i=0;i<n;i++)cout<<*arr[i]<<' ';
    cout<<endl;
    }
    

