#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n>0)
    return n+sum(n-1);
    return 0;
}
int main()
{
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    int r=sum(n);
    cout<<"sum: "<<r;
    return 0;
}