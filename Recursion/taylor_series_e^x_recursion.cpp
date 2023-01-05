#include<bits/stdc++.h>
using namespace std;
// int power(int m,int n)
// {
//     if(n==0)
//     {
//         return 1;
//     }
//     else if(n%2==0)
//     {
//         return power(m*m,n/2);
//     }
//     else
//     return m*power(m*m,n/2);
// }
// int factorial(int n)
// {
//     if(n>0)
//     {
//         return n*factorial(n-1);
//     }
//     return 1;
// }
float taylor(int x,int n)
{
    // float p=power(x,n),f=factorial(n);
    static float p=1,f=1;
    float r;
    
    if(n==0)
    return 1;
    if(n>0)
    {
        r=taylor(x,n-1);
    p=p*x;
    f=f*n;
        return r+(p/f);
    }
    return 0;
}
int main()
{
    int x,n;
    float r;
    cout<<"Enter the value of x:";
    cin>>x;
    cout<<"Enter the no of terms of the taylor series:";
    cin>>n;
    r=taylor(x,n);
    cout<<"The sum of the taylor series of e^"<<x<<" for "<<n<<" terms is:"<<r;
    return 0; 
}