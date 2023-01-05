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

}
node* search(node *p,int key)
{
    if(p==0)
    {
        return NULL;
    }
    if(p->data==key)
    {
        return p;
    }
    return search(p->next,key);
}
node* m2f(node *p,int key)
{
    node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
int main()
{
    int A[]={3,32,76,1,7,9,35,72,85};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    display(first);
    // node *k=search(first,4);
    node* k1=m2f(first,35);
    cout<<"\n35 is present at:"<<k1<<endl;
    display(first);
    return 0;
}