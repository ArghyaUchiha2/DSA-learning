#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
}*top=NULL;
void push(int x)
{
    node *t=new node;
    if(t==NULL)
    {
        cout<<"Stack is full."<<endl;
    }
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
void pop()
{
    if(top==NULL)
    {
        cout<<"Stack underflow."<<endl;
    }
    else{
        node *t=top;
        int x=t->data;
        cout<<"Deleted:"<<t->data<<endl;
        top=top->next;
        delete t;
    }
}
void display_stack(node *p)
{
    if(p==0)
    {
        cout<<"Stack is empty."<<endl;
        return;
    }
    cout<<"Stack:"<<endl;
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    // node *top=NULL;
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    display_stack(top);
    pop();
    display_stack(top);
    return 0;
}