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
    void delete_doubly(node *p,int pos)
    {
        if(pos==1)
        {
            cout<<"Deleted node:"<<head->data<<endl;
            head=head->next;
            head->prev=NULL;
        }
        else
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            cout<<"Deleted node:"<<p->data<<endl;
            p->prev->next=p->next;
            p->next->prev=p->prev;

        }
    }
    int main()
    {
        int A[]={32,26,67,2,6,68,23};
        int len=sizeof(A)/sizeof(A[0]);
        create(A,len);
        displaylist(head);
        delete_doubly(head,1);
        displaylist(head);
        delete_doubly(head,3);
        displaylist(head);
        return 0;
    }