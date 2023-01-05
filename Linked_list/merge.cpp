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
}*first=NULL,*second=NULL,*third=NULL;
void createlist1(int A[],int n)
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
void createlist2(int A[],int n)
{
    int i;
    struct node *t,*last;
    second=new node(A[0]);
    last=second;
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
void merge(node *f,node *s)
{
    node *last;
    if(f->data<s->data)
    {
        third=last=f;
        f=f->next;
        third->next=NULL;
    }
    else{
        third=last=s;
        s=s->next;
        third->next=NULL;
    }
    while(f!=0 && s!=0)
    {
        if(f->data<s->data)
    {
        last->next=f;
        last=f;
        f=f->next;
        last->next=NULL;
    }
    else{
        last->next=s;
        last=s;
        s=s->next;
        last->next=NULL;
    }
    }
    if(f!=0)
    {
        last->next=f;
        // last=f;
        // f=f->next;
        // last->next=NULL;
    }
    if(s!=0)
    {
         last->next=s;
        // last=s;
        // s=s->next;
        // last->next=NULL;
    }

}
int main()
{
    int A[]={2,8,10,15,17,19};
    int len1=sizeof(A)/sizeof(A[0]);
    createlist1(A,len1);
    cout<<"First list:"<<endl;
    display(first);
    int B[]={4,6,12,14};
    int len2=sizeof(B)/sizeof(B[0]);
    createlist2(B,len2);
    cout<<"Second list:"<<endl;
    display(second);
    merge(first,second);
    cout<<"Merged linked list:"<<endl; 
    display(third);
    return 0;
}