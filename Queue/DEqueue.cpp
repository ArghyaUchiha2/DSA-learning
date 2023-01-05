#include<iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct queue
{
    node *front;
    node *rear;
    queue(){front=rear=NULL;}
};
void insert_first(queue *q,int x)
{
    node *t=new node;
    if(t==NULL)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    t->data=x;
    t->next=q->front;
    q->front=t;
    if(q->rear==NULL)
    {
        q->rear=q->front;
    }
}
int delete_first(queue *q)
{
    int x=-1;
    if(q->front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        node *p=q->front;
        x=q->front->data;
        q->front=q->front->next;
        delete p;
    }
    return x;
}
void insert_last(queue *q,int x)
{
    node *t=new node;
    if(t==NULL)
    {
        cout<<"Queue is full"<<endl;
    return;
    }
    else
    {
        t->data=x;
        t->next=NULL;
        if(q->front==NULL)
        {
            q->front=q->rear=t;
        }
        else
        {
            q->rear->next=t;
            q->rear=t;
        }
    }
}
int delete_last(queue *q)
{
    int x=-1;
    node *p=q->front;
    if(q->front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    x=q->rear->data;
    free(q->rear);
    q->rear=p;
    q->rear->next=NULL;
    }
    return x;
}
void display(queue q)
{
    if(q.front==NULL)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        while(q.front!=NULL)
        {
            cout<<q.front->data<<"->";
            q.front=q.front->next;
        }
        cout<<"NULL\n";
    }
}
int main()
{
    queue q1;
    insert_first(&q1,10);
    display(q1);
    insert_first(&q1,20);
    insert_last(&q1,30);
    display(q1);
    delete_last(&q1);
    display(q1);
    delete_first(&q1);
    display(q1);
    return 0;
}