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
void display_circular_recursive(node *p)
{
    static int flag=0;
    if(flag==0 || p!=head)
    {
        flag=1;
        cout<<p->data<<"->";
        display_circular_recursive(p->next);
        return;
    }
        cout<<"NULL"<<endl;
}
int main()
{
    int A[]={32,61,43,76,34,8};
    int len=sizeof(A)/sizeof(A[0]);
    create_circular(A,len);
    display_circular(head);
    cout<<"using recursive:"<<endl;
    display_circular_recursive(head);
    return 0;
} 