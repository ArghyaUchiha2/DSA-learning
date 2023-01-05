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
void isloop(node *a)
{
    cout<<"check1"<<endl;
    node *p,*q;
    p=q=a;
    while(p->next!=0 || q->next->next!=0)
    {
    cout<<"check2"<<endl;
        p=p->next;
        q=q->next->next;
        if(p==q)
        {
            cout<<"This list contains a LOOP."<<endl;
            return;
        }
        
    }
    cout<<"check3"<<endl;
    cout<<"This list is linear."<<endl;
}
int main()
{
    int A[]={3,32,76,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    // node *t1=new node(0),*t2=new node(0);
    // t1=first->next->next->next;
    // t2=first->next->next->next->next->next;
    // t2->next=t1;
    cout<<"check0"<<endl;
    isloop(first);
    return 0;
}