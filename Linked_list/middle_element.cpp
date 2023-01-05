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
void middle_element(node *p)
{
    node *a,*b;
    a=b=p;
    while(a && b)
    {
        if(b->next==NULL || b->next->next==NULL)
        {
               cout<<"middle element:"<<a->data<<endl;
        }
        a=a->next;
        b=b->next->next;
    }
}
int main()
{
    int A[]={3,32,1,7,9};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    middle_element(first);
    
    return 0;
}