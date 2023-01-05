#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;
void insert(struct node *p,int pos,int x)
{
    struct node *t=new node;
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
void display(struct node *p)
{
    while(p)
    {
        cout<<p->data<<"->";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    insert(first,0,3);
    display(first);
    insert(first,1,42);
    display(first);
    insert(first,2,84);
    display(first);
    insert(first,0,5);
    display(first);
    return 0;
}