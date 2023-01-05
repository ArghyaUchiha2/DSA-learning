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
void insert_circular(node *p,int pos,int x)
{
    node *t=new node;
    t->data=x;
    if(pos==0)
    {
        if(!head)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            p=p->next;
        }
            t->next=p->next;
            p->next=t;
    }
}
int main()
{
    int A[]={4,75,34,9,2,52,65};
    int len=sizeof(A)/sizeof(A[0]);
    create_circular(A,len);
    display_circular(head);
    insert_circular(head,0,3);
    display_circular(head);
    insert_circular(head,4,69);
    display_circular(head);
    return 0;
}