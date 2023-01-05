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
void delete_duplicate(void)
{
    node *p=first,*q=first->next;
    while (q!=0)
    {
        if(p->data==q->data)
        {
            p->next=q->next;
            q=p->next;
        }
        else
        {
            p=q;
            q=q->next;
        }
    }
    
}
int main()
{
    int A[]={3,5,5,8,8,8};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first); 
    delete_duplicate();
    display(first);
    return 0;
}