#include<bits/stdc++.h>
using namespace std;
struct mystack
{
    int size,top;
    int *S;
};
void create_stack(mystack *st)
{
    cout<<"Enter the size of stack:";
    cin>>st->size;
    st->top=-1;
    st->S=new int [st->size];
}
void display_stack(mystack st)
{
    if(st.top==-1)
    {
        cout<<"Stack is empty."<<endl;
    }
    else
    {
        cout<<"MYstack:"<<endl;
        for(int i=st.top;i>-1;i--)
        {
            cout<<st.S[i]<<" ";
        }
        cout<<endl;
    }
}
void push(mystack *st,int x)
{
    if(st->top==st->size-1)
    {
        cout<<"Stack Overflow."<<endl;
    }
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}
void pop(mystack *st)
{
    if(st->top==-1)
    {
        cout<<"Stack underflow."<<endl;
    }
    else
    {
        int x=INT_MIN;
        x=st->S[st->top--];
        if(x==INT_MIN)
        {
            cout<<"Stack is empty."<<endl;
        }
        else
        {
            cout<<"Deleted:"<<x<<endl;
        }
    }
}
void peek(mystack st,int index)
{
    int x=INT16_MIN;
    if(st.top-index+1<0)
    {
        cout<<"Invalid index"<<endl;
    }
    else{
    x=st.S[st.top-index+1];
    if(x==INT16_MIN)
    {
        cout<<"EMPTY"<<endl;
    }
    else
    {
        cout<<"peek("<<index<<"):"<<x<<endl;
    }
    }
}
bool isempty(mystack st)
{
    if(st.top==-1)
    {
        return 1;   
    }
    return 0;
}
bool isfull(mystack st)
{
    if(st.top==st.size-1)
    {
        return 1;
    }
    return 0;
}
int main()
{
    struct mystack st;
    create_stack(&st);
    push(&st,21);
    display_stack(st);
    push(&st,25);
    display_stack(st);
    push(&st,67);
    display_stack(st);
    push(&st,3);
    display_stack(st);
    push(&st,11);
    display_stack(st);
    pop(&st);
    display_stack(st);
    pop(&st);
    peek(st,4);
    if(isempty(st))
    {
        cout<<"stack is empty."<<endl;
    }
    else
        cout<<"stack is not empty."<<endl;
    if(isfull(st))
    {
        cout<<"Stack is full."<<endl;
    }
    else
        cout<<"Stack is not full."<<endl;
    return 0;
}