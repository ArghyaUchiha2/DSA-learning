#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void create_circular(int A[],int n)
{
    node *t,*last;
    head=new node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}
void display_circular(node *p)
{
    do
    {
        cout<<p->data<<"->";
        p=p->next;
    }while(p!=head);
    cout<<"NULL"<<endl;
}
void delete_circular(node*p,int pos)
{
    node *t=new node;
    if(pos==0)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        t=head;
        head=head->next;
        p->next=head;
        delete t;
    }
    else{
        for(int i=0;i<pos-2;i<i++)
        {
            p=p->next;
        }
        t=p->next;
        cout<<"deleted node:"<<p->next->data<<endl;
        p->next=p->next->next;
        delete t;
    }
}
int main()
{
    int A[]={4,75,34,9,2,52,65};
    int len=sizeof(A)/sizeof(A[0]);
    create_circular(A,len);
    display_circular(head);
    delete_circular(head,0);
    display_circular(head);
    delete_circular(head,3);
    display_circular(head);
    return 0;
}