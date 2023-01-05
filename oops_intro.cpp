#include<iostream>
using namespace std;
class rectangle {
    private:
    int length;
    int breadth;
    public:
    rectangle(int l,int b)//constructor
    {
        length=l;
        breadth=b;
    }
    int area()
    {
        return length*breadth;
    }
    void changelength(int l)
    {
        length=l;
    }
};
int main()
{
    rectangle r(10,5);
    cout<<"Area: "<<r.area()<<endl;
    r.changelength(20);
    cout<<"After changelength Area: "<<r.area()<<endl;
    return 0;
}