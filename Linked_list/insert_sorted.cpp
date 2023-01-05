#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;//self-referential function
}*first=NULL;
void createlist(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}
void insert_sorted(int x)
{
    node *p=new node,*q=new node,*t=new node; 
    p=first;
    q=NULL;
    if(x<first->data)
    {
        first=t;
    }
    while(p!=0 && p->data<x)
    {
        q=p;
        p=p->next;
    }
    q->next=t;
    t->data=x;
    t->next=p;
}
int main()
{
    int A[]={2,5,7,12,23,40,103};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    insert_sorted(8);
    display(first);

    return 0;
}