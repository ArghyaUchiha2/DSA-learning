#include<iostream>
using namespace std;
struct rectangle{
    int length;
    int breadth;
};
void initialize(struct rectangle *p,int l,int b)
{
    p->length=l;
    p->breadth=b;
}
int area(struct rectangle r)
{
    return r.length*r.breadth;
}
void changelength(rectangle *r1,int l)
{
    r1->length=l;
}
int main()
{
    rectangle r1;
    initialize(&r1,10,5);
    cout<<"Area: "<<area(r1)<<endl;
    changelength(&r1,20);
    cout<<"After change area: "<<area(r1);
    return 0;
}//this code is showing error for some reason idk