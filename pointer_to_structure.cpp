#include<bits/stdc++.h>
using namespace std;
struct rectangle{
    int length;
    int breadth;
};
int main()
{
    rectangle r;//this is created in stack
    r.length=5;
    r.breadth=10;
    cout<<"length:"<<r.length<<endl;
    cout<<"breadth:"<<r.breadth<<endl;
    rectangle *p=&r;
    cout<<"change of length using pointer:"<<endl;
    p->length=8;//for pointer we use arrow
    cout<<p->length<<endl; 
    //object in heap
    rectangle *q;
    q=new rectangle;//this is created in heap
    q->length=78;
    q->breadth=56;
    cout<<"Length of r2:"<<q->length<<endl;
    cout<<"Breadth of r2:"<<q->breadth<<endl;
    return 0;
}