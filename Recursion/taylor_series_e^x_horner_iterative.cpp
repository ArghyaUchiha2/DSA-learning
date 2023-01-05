#include<iostream>
using namespace std;
int main()
{
    int x,n;
    float r=1,num=1,den=1;
    cout<<"ENter the value of x:";
    cin>>x;
    cout<<"ENter the value of n:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        num=num*x;
        den=den*i;
        r=r+(num/den);
    }
    cout<<"value:"<<r;
}