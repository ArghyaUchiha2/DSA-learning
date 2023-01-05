#include<bits/stdc++.h>
using namespace std;
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
    cout<<endl;
}
void insert(struct node *p,int pos,int x)
{
    node *t=new node;
        t->data=x;
    if(pos==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=1;i<pos;i++)
        {
                p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}
int main()
{
    int A[]={3,32,76,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    insert(first,3,21);
    display(first);
    insert(first,0,69);
    display(first);
    return 0;
}