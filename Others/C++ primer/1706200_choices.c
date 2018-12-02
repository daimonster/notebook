#include<iosream>
template<typename T>
T lesser(T a,T b)
{
    return a<b?a:b
}
int lesser(int a, int b)
{
    a=a<0?-a:a;
    b=b<0?-b:b;
    return a<b?a:b;
}
int main()
{
    using namespace std;
    int m=20;
    int n=30;
    double x=15.5;
    double y=25.9;
    cout<<lesser(m,n)<<endl;
    cout<<lesser<>(m,n)<<endl;
    cout<<lesser<int>(m,n)<<endl;
    return 0;
}
