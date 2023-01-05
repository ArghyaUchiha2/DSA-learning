#include<bits/stdc++.h>
using namespace std;
float tayhor(int x,int n)
{
    static float f=1;
    if(n==0)
    {
        return f;
    }
    else if(n>0)
    {
        f=1+x*f/n;
        return tayhor(x,n-1);
    }
    return 0;
}
int main()
{
    int x,n;
    float r;
    cout<<"ENter the value of x:";
    cin>>x;
    cout<<"ENter the value of n:";
    cin>>n;
    r=tayhor(x,n);
    cout<<"value:"<<r;
    return 0;
}