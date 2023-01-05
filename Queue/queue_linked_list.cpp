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
    queue()
    {
        front=rear=NULL;
    }
};
void enqueue(queue *q,int x)
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
        else{
        q->rear->next=t;
        q->rear=t;
        // delete t; //This line will throw an error as we are deleting the rear node
        }
    }
}
int dequeue(queue *q)
{
    int x=-1;
    if(q->front==NULL)
    {
        cout<<"Queue is empty"<<endl;
    }
    else
    {
        node* p=q->front;
        x=q->front->data;
        q->front=q->front->next;
        delete p;
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
    enqueue(&q1,10);
    enqueue(&q1,20);
    enqueue(&q1,30);
    enqueue(&q1,40);
    display(q1);
    cout<<"Deleted node: "<<dequeue(&q1)<<endl;
    cout<<"Deleted node: "<<dequeue(&q1)<<endl;
    display(q1);
    return 0;
}