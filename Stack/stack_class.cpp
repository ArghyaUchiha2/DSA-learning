#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
};
class stack
{
    private:
    node *top;
    public:
    void display();
    void push(int x);
    void pop();
};
void stack::display()
{
    cout<<"Stack:"<<endl;
    node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void stack::pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow."<<endl;
    }
    else{
        node *t=top;
        cout<<"Deleted:"<<top->data<<endl;
        top=top->next;
        delete t;
    }
}
void stack::push(int x)
{
    node *t=new node;
    if(t==NULL)
    {
        cout<<"Stack is full."<<endl;
    }
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
int main()
{
    stack s;
    s.push(25);
    s.push(37);
    s.push(12);
    s.push(21);
    s.push(90);
    s.display();
    s.pop();//causing problems
    s.display();
    return 0;
}