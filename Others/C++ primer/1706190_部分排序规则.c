#include<iostream>
template<typename T>
void ShowArray <typename T>

template<typename T>
void ShowArray <typename T>
using namespace std;

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    int things[6]={13,31,103,301,310,130};
    struct debts mr_E[3]=
    {
        {"Ima WOlfe",2400.00},
        {"Ura Foxe",1300.00},
        {"Iby Stout",1800.00}
    };
    double * pd[3];
    
    for(int i=0;i<3;i++)
        pd[i]=&mr_E[i].amount;
        
    cout<<"Listing Mr.E's counts of things:\n";
    ShowArray(things,6);
}
