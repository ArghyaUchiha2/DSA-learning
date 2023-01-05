#include<iostream>
using namespace std;
int ncr(int n,int r)
{
    if(r==0 || r==n)
    {
        return 1;
    }
    else
    {
        return ncr(n-1,r-1)+ncr(n-1,r);
    }
}
int main()
{
    int n,r,v;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<"Enter the value of r:";
    cin>>r;
    if(r>n)
    {
        cout<<"Wrong input!!";
        return 0;
    }
    v=ncr(n,r);
    printf("%dC%d=%d",n,r,v);
    return 0;
}