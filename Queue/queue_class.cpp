#include<iostream>
#include "queue_class.h"
using namespace std;
class queue
{
    int size;
    int front;
    int rear;
    int *Q;
    public:
    queue()
    {
        front=rear=-1;
        Q=new int(size);
    }
    queue(int x)
    {
        front=rear=-1;
        Q=new int(x);
    }
    void enqueue(int x);
    void dequeue();
    void display();
};
void queue::enqueue(int x)
{
    if(rear==size-1)
    {
        cout<<"Stack is full"<<endl;
        return;
    }
    else{
        Q[++rear]=x;
    }
}
void queue::dequeue()
{
    if(front==rear)
    {
        cout<<"Queue is empty\n";
        return;
    }
    else
    {
        cout<<"Deleted element:"<<Q[++front];
    }
}
void queue::display()
{
    if(front==rear)
    {
        cout<<"Queue is empty\n";
    }
    else{
          for(int i=front+1;i<=rear;i++)
          {
            cout<<Q[i]<<" ";
          }
        cout<<"\n";
    }
}
int main()
{
    queue q(50);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    return 0;
}
    //problematic code