#include<iostream>
using namespace std;
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void enqueue(queue *q,int x)
{
    if(q->rear==q->size-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    else
    q->Q[++q->rear]=x;//First taking rear to the next position then inserting
}
void dequeue(queue *q)
{
    if(q->front==q->rear)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    ++q->front;
}
void display_queue(queue q)
{
    if(q.front==q.rear)
    cout<<"\nNULL"<<endl;
    else{
    while(q.front!=q.rear)
    {
        cout<<q.Q[++q.front]<<" ";
    }
    }
}
int main()
{
    queue q1;
    cout<<"Enter the size of the queue:";
    cin>>q1.size;
    q1.Q=new int(q1.size);
    q1.front=q1.rear=-1;
    enqueue(&q1,5);
    enqueue(&q1,7);
    enqueue(&q1,4);
    enqueue(&q1,4);
    enqueue(&q1,1);

    display_queue(q1);

    dequeue(&q1);
    dequeue(&q1);
    display_queue(q1);
    return 0;
}