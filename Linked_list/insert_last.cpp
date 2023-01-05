#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL,*last;
void insert_last(int x)
{
    struct node *t=new node;
    // node *last=new node; 
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    {
        first=last=t;
        return;
    }
    // cout<<"check1";
    else{
    last->next=t;
    last=t;}
}
void displaylist(struct node *p)
{
    while(p!=0)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    insert_last(4);
    insert_last(3);
    insert_last(8);
    insert_last(2);
    insert_last(5);
    insert_last(7);
    displaylist(first);
    return 0;
}