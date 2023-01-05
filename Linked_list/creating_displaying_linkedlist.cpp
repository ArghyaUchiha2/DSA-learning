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
    struct node *t,*last;
    first=new node(A[0]);
    last=first;
    for(int i=1;i<n;i++)
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

int main()
{
    int A[]={3,32,76,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    
    return 0;
}