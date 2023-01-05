#include<iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int *Q=new int[size];
    queue()
    {
        size=-1;
        front=rear=0;
    }
    queue(int x)
    {
        size=x;
        front=rear=0;
    }
};
void enqueue_circular(queue *q,int x)
{
    if((q->rear+1)%q->size == q->front)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
void dequeue(queue *q)
{
    if(q->rear==q->front)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    else
    {
        q->front=(q->front+1)%q->size;
        return;
    }
}
void display_circular(queue q)
{
    if(q.front%q.size==q.rear)
    {
        cout<<"NULL\n";
        return;
    }
    while((q.front%q.size)!=q.rear)
    {
    // cout<<"Check1\n";
        cout<<q.Q[(++q.front)%q.size]<<" ";
    }
    cout<<endl;
}
int main()
{
    queue q1;
    cout<<"Enter the size of queue:";
    cin>>q1.size;
    enqueue_circular(&q1,15);
    enqueue_circular(&q1,10);
    enqueue_circular(&q1,13);
    display_circular(q1);
    dequeue(&q1);
    dequeue(&q1);
    display_circular(q1);
    enqueue_circular(&q1,1);
    enqueue_circular(&q1,5);
    enqueue_circular(&q1,34);
    display_circular(q1);
    return 0;
}