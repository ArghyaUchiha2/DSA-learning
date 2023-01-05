#include<bits/stdc++.h>
using namespace std;
int expo(int m,int n)
{
    if(n>0)
    {
        return m*expo(m,n-1);
    }
    return 1;
}
int main()
{
    int m,n;
    cout<<"Enter the value of base:";
    cin>>m;
    cout<<"Enter the value of index:";
    cin>>n;
    int r=expo(m,n);
    printf("%d^%d=%d",m,n,r);
}