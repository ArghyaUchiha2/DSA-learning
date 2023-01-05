#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    
    if(n==0)
    return 1;
        return n*fact(n-1);
}
int C(int n,int r)
{
    int num=fact(n);
    int den=fact(r)*fact(n-r);
    return num/den;
}
int main()
{
    int n,r,v;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Enter the value of r:";
    cin>>r;
    v=C(n,r);
    cout<<"value:"<<v;
    return 0;
}