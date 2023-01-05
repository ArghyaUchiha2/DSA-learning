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
    void reverse_doubly(node *p)
    {
        node *temp;
        while(p)
        {
            temp=p->next;
            p->next=p->prev;
            p->prev=temp;
            p=p->prev;
            if(p!=0 && p->next==0)
            {
                head=p;
            }
        }
        // head=p->next;
    }
    int main()
    {
        int A[]={32,26,67,2,6,68,23};
        int len=sizeof(A)/sizeof(A[0]);
        create(A,len);
        displaylist(head);
        reverse_doubly(head);
        displaylist(head);
        return 0;
    }