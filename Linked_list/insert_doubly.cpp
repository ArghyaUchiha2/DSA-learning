#include<iostream>
using namespace std;
struct node{
    int data;
    node *prev,*next;
}*head=NULL;
void create(int A[],int n) 
{
    node *t,*last;
    head=new node;
    head->data=A[0];
    head->prev=head->next=NULL;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;   
    }
}
    void displaylist(node *p)
    {
        while(p)
        {
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<"NULL"<<endl;
    }
    void insert_doubly(node *p,int pos,int x)
    {
        node* t=new node;
            t->data=x;
        if(pos==0)
        {
            t->next=head;
            t->prev=head->prev;
            head->prev=t;
            head=t;
        }
        else{
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            t->next->prev=t;
            p->next=t;
        }
    }
    int main()
    {
        int A[]={32,26,67,2,6,68,23};
        int len=sizeof(A)/sizeof(A[0]);
        create(A,len);
        displaylist(head);
        insert_doubly(head,0,5);
        displaylist(head);
        insert_doubly(head,4,22);
        displaylist(head);
        return 0;
    }