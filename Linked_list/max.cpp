#include<bits/stdc++.h>
using namespace std;
// class node
// {
//     public:
//     int data;
//     node* next;

//     node* head=NULL;
//     node(int x)
//     {
//         data=x;
//         next=NULL;
//     }
//     node* insertbegin(int x)
//     {
//         node* temp=new node(x);
//         if(head==NULL)
//         {
//             return temp;
//         }
//         temp->next=head;
//         return temp;
//     }
// };
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
int Rmax(struct node *p)
{
    int x=0;
    if(p==0)
    {
        return INT_MIN;
    }
    x=Rmax(p->next);
    if(x>p->data)
    return x;
    else
    return p->data;
}
int main()
{
    int A[]={25,7,4,8,23,7,2,34};
    int len=sizeof(A)/sizeof(A[0]);
    createlist(A,len);
    int max=Rmax(first);
    cout<<"Maximum element of the list is:"<<max;
    return 0;
}
