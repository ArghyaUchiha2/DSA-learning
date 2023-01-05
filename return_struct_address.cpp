#include<iostream>
using namespace std;
struct rectangle{
    int length;
    int breadth;
};
rectangle *func()
{
    rectangle *p;
    p=new rectangle;
    p->length=25;
    p->breadth=30;
    return p;
}
int main()
{
    rectangle *ptr=func();//func is returning a pointer to a structure rectangle
    cout<<"Length: "<<ptr->length<<endl<<"Breadth: "<<ptr->breadth<<endl;
    return 0;
}