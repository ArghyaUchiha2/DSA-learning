#include<iostream>
using namespace std;
int fun(int n)
{
    if(n>100)
    {
        return n-10;
    }
    else
    {
        return fun(fun(n+11));
    }
}
int main()
{
    int n,r;
    cout<<"Enter the value of n:";
    cin>>n;
    r=fun(n);
    cout<<r;
    return 0;
}