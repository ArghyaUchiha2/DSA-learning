#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;
void createlist(int A[],int n)
{
    struct node *t,*last;
    first=new node;
    first->data=A[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
int count(struct node *p)
{
    int c=0;
    while(p!=0)
    {
        c++;
        p=p->next;
        //cout<<"check";
    }
    return c;
}
void display(struct node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<"->";
        p=p->next;
    }

}
int sum(struct node *p)
{
    if(p==0)
    {
        return 0;
    }
    return sum(p->next)+p->data;
}

int main()
{
    int A[]={32,75,28,5,7,39};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    int c=count(first);
    display(first);
    cout<<"The no of nodes in the given list is:"<<c;
    int s=sum(first);
    cout<<"The sum of all the data in the linked list is:"<<s;
    return 0;
}