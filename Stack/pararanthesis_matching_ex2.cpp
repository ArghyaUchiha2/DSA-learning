#include<iostream>
#include<string.h>
using namespace std;
class node
{
    public:
    char data;
    node *next;
};
class stack
{
    public:
    node *top=NULL;
    void display();
    void push(char x);
    void pop();
    int isempty();
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
        // cout<<"Deleted:"<<top->data<<endl;
        top=top->next;
        delete t;
    }
}
void stack::push(char x)
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
int stack::isempty()
{
    if(top==NULL)
    return 1;
    else 
    return 0;
}
int isbalance(char *exp)
{
    stack s;
    for(int i=0;i!=strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            s.push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(s.isempty()==0 && s.top->data=='(')
            {
                s.pop(); 
            }
            else if(!s.isempty() && s.top->data!='(')
            {
                cout<<"INVALID FORMAT";
                return 0;
            }
            else
            return 0;
        }
         else if(exp[i]=='}')
        {
            if(s.isempty()==0 && s.top->data=='{')
            {
                s.pop(); 
            }
            else if(!s.isempty() && s.top->data!='{')
            {
                cout<<"INVALID FORMAT";
                return 0;
            }
            else
            return 0;
        }
         else if(exp[i]==']')
        {
            if(s.isempty()==0 && s.top->data=='[')
            {
                s.pop(); 
            }
            else if(!s.isempty() && s.top->data!='[')
            {
                cout<<"INVALID FORMAT";
                return 0;
            }
            else
            return 0;
        }
    }
    if(s.isempty()==1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char exp1[]="[{(a*b)+(c*d)}-(d/e)]";
    cout<<"Exp1: "<<exp1<<" "<<isbalance(exp1)<<endl;
    char exp2[]="{(a*b)+(c*d))";
    cout<<"Exp2: "<<exp2<<" "<<isbalance(exp2)<<endl;
    char exp3[]="([a*b))+(c*d)]";
    cout<<"Exp3: "<<exp3<<" "<<isbalance(exp3)<<endl;

    return 0;
}