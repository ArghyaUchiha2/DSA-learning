#include<iostream>
using namespace std;
class Node
{
    public:
    Node *lchild;
    int data;
    Node *rchild;
    Node()
    {
        data=-1;
        lchild=rchild=NULL;
    }
    Node(int x)
    {
        data=x;
        lchild=rchild=NULL;
    }
};
class queue
{
    int size;
    int front;
    int rear;
    Node **Q;
    public:
    queue()
    {
        front=rear=-1;
        Q=new Node*[size];
    }
    queue(int size)
    {
        front=rear=-1;
        this->size=size;
        Q=new Node*[this->size];
    }
    void enqueue(Node *x);
    Node* dequeue();
    void display();
    int isEmpty(queue q);
};
void queue::enqueue(Node *x)
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
Node* queue::dequeue()
{
    Node* t=nullptr;
    if(front==rear)
    {
        cout<<"Queue is empty\n";
        return NULL;
    }
    else
    {
        t=Q[++front];
        // cout<<"Deleted element:"<<Q[++front];
    }
    return t;
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
int queue::isEmpty(queue q)
{
    if(front==rear)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}