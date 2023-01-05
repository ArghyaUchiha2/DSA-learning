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
void deletion(int pos)
{
    node *p=first, *q=NULL;
    int x;
    if(pos==1)
    {
        first=first->next;
        x=p->data;
        delete p;
    }
    else if(pos>1)
    {
        for(int i=0;i<pos-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    cout<<"Deleted data:"<<x<<endl;
}
int main()
{
    int A[]={3,32,76,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    deletion(1);
    display(first);
    deletion(3);
    display(first);

    return 0;
}