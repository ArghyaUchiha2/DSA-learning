#include<iostream>
#include<string.h>
using namespace std;
class node
{
    public:
    char data;
    node *next;
    node()
    {
        data=0;
        next=NULL;
    }
}*top=NULL;
class stack
{
    public:
    // node *top=NULL;
    void display();
    void push(char x);
    char pop();
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
char stack::pop()
{
        node *t=top;
        char x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow."<<endl;
    }
    else{
        // cout<<"Deleted:"<<top->data<<endl;
        top=top->next;
        char x=t->data; 
        delete t;
    }
        return x;
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
int isoperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    {
        return 0;
    }
    else
    return 1;
}
int prescribe(char x)
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x=='*' || x=='/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *intopostfix(char *infix)
{
    stack st;
    char *postfix=new char[strlen(infix)+1];
    int i=0,j=0;
    while(infix[j]!='\0')
    {
        if(isoperand(infix[j]))
        {
            postfix[i++]=infix[j++];
            // i++;
            // j++;
            cout<<"Check1"<<endl;
        }
        else
        {
            if(prescribe(infix[j])>prescribe(top->data))
            {
                st.push(infix[j++]);
            cout<<"Check2"<<endl;
            }
            else
            {
                postfix[i++]=st.pop();
                if(st.isempty()==1)
                {
                    cout<<"yes"<<endl;
                }
            cout<<"Check3"<<endl;
            }
        }
    }
    while (!st.isempty())
    {
            cout<<"Check4"<<endl;
        postfix[i++]=st.pop();
    cout<<"Postfix: "<<postfix<<endl;
    }
            cout<<"Check5"<<endl;
    postfix[i]='\0';
    return postfix;
}
int main()
{
    char *infix="a+b*c-d/e";
    char *postfix=intopostfix(infix);
    cout<<"Infix: "<<infix<<endl;
    cout<<"Postfix: "<<postfix<<endl;
    return 0;
}