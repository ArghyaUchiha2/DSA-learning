#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;//self-referential function
    node(int x)
    {
        data=x;
        next=NULL;
    }
}*first=NULL;
void createlist(int A[],int n)
{
    int i;
    struct node *t,*last;
    first=new node(A[0]);
    last=first;
    for(i=1;i<n;i++)
    {
        t=new node(A[i]);
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
void reverse_element(node*p,int n)
{
    cout<<"Reversing elements:"<<endl;
    int A[n];
    int i=0;
    while(p!=0)
    {
        A[i++]=p->data;
        p=p->next;
    }
    p=first;
    while (p!=NULL)
    {
        p->data=A[--i];
        p=p->next;
    }
    
}
void revese_link(node *p)
{
    cout<<"Reversing link:"<<endl;
    node *q=NULL,*r=NULL;
    while(p!=0)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void reverse_recursive(node *p,node *q)
{
    if(p!=0)
    {
        reverse_recursive(p->next,p);
        p->next=q;
    }
    else
    {
        first=q;
    }
}
int main()
{
    int A[]={3,32,76,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    reverse_element(first,len);
    display(first);
    revese_link(first);
    display(first);
    node *q=NULL;
    cout<<"Reverse recursive:"<<endl;
    reverse_recursive(first,q);
    display(first);
    return 0;
}