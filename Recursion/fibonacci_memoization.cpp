#include<iostream>
using namespace std;
int F[50];
int fib(int n)
{
    if(n<=1)
    {
        F[n]=n;
        return F[n];
    }
    else{
        if(F[n-2]==-1)
        {
            F[n-2]=fib(n-2);
        }
        if(F[n-1]==-1)
        {
            F[n-1]=fib(n-1);
        }
        return F[n-2]+F[n-1];
    }
}
int main()
{
    int n,r;
    cout<<"Enter the term of the fibonacci sequence:";
    cin>>n;
    fill(F,F+50,-1);
    r=fib(n);
    cout<<"value:"<<r;
    return 0;
}