#include<iostream>
using namespace std;
int main()
{
    int *p;
    p= new int[5];
    p[0]=67,p[1]=26,p[2]=784,p[3]=5,p[4]=1;
    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }
    delete [] p;
    cout<<"After deletion:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<p[i]<<endl;
    }
    //size of a pointer is always fixed irrespective of the data type
    return 0;
}