#include<iostream>
#include "queue.h"
#include<stack>
using namespace std;
class tree
{
    Node* root;
    public:
    tree()
    {
        root=NULL;
    }
    void create_tree();
    void preorder(Node* p);
    void postorder(Node* p);
    void inorder(Node* p);
    void levelorder(Node* p);
    int height(Node* p);
    Node* getroot(){return root;}
    void iterativePreorder(Node *p);
    void iterativeInorder(Node *p);
    void iterativePostorder(Node *p);
    int count_nodes(Node *p);
    int count_leaf_nodes(Node *p);
    int count_nodes_deg2(Node *P);
    int count_nodes_deg1(Node *P);
};
void tree::create_tree()
{
    Node* t=NULL,*p;
    int x;
    queue q(100);
    cout<<"Enter the value of root:";
    cin>>x;
    root=new Node(x);
    q.enqueue(root);
    while(!q.isEmpty(q))
    {
        p=q.dequeue();
        cout<<"Enter the left child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            p->lchild=t;
            q.enqueue(t);
        }
        cout<<"Enter the right child of "<<p->data<<":";
        cin>>x;
        if(x!=-1)
        {
            t=new Node(x);
            p->rchild=t;
            q.enqueue(t);
        }
    }
}
void tree::preorder(Node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void tree::postorder(Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}
void tree::inorder(Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        cout<<p->data<<" ";
        inorder(p->rchild);
    }
}
void tree::levelorder(Node*p)
{
    queue q(100);
    cout<<root->data<<" ";
    q.enqueue(root);
    {
        while(!q.isEmpty(q))
        {
            p=q.dequeue();
            if(p->lchild)
            {
                cout<<p->lchild->data<<" ";
                q.enqueue(p->lchild);
            }
            if(p->rchild)
            {
                cout<<p->rchild->data<<" ";
                q.enqueue(p->rchild);
            }
        }
    }
}
int tree::height(Node *p)
{
    int l=0,r=0;
    if(p==NULL)
    {
        return 0;
    }
    l=height(p->lchild);
    r=height(p->rchild);
    if(l>r)
    {
        return l+1;
    }
    else
    {
        return r+1;
    }
}
void tree:: iterativePreorder(Node *p)
{
    stack<Node*> stk;
    while(p!=NULL || !stk.empty())
    {
        if(p!=NULL)
        {
            cout<<p->data<<" ";
            stk.emplace(p);
            p=p->lchild;
        }
        else
        {
            p=stk.top();
            stk.pop();
            p=p->rchild;
        }
    }
    cout<<endl;
}
void tree:: iterativeInorder(Node *p)
{
    stack<Node*> stk;
    while(p!=NULL||!stk.empty())
    {
        if(p!=NULL)
        {
            stk.emplace(p);
            p=p->lchild;
        }
        else
        {
            p=stk.top();
            stk.pop();
            cout<<p->data<<" ";
            p=p->rchild;
        }
    }
    cout<<endl;
}
// void tree::iterativePostorder(Node *p)
// {
//     stack<long int> stk;
//     long int temp;
//     while (p!=NULL || !stk.empty())
//     {
//         if(p!=NULL)
//         {
//             stk.emplace((long int)p);
//             p=p->lchild;
//         }
//         else
//         {
//             temp=stk.top();
//             stk.pop();
//             if(temp>0)
//             {
//                 stk.emplace(-temp);
//                 p=((Node*)temp)->rchild;
//             }
//             else
//             {
//                 cout<<((Node*)(-1*temp))->data<<" ";
//                 p=NULL;
//             }
//         }
//     }
//     cout<<endl;
    
// }
int tree::count_nodes(Node *p)
{
    if(p)
    {
        return count_nodes(p->lchild)+count_nodes(p->rchild)+1;
    }
    else
    {
        return 0;
    }
}
int tree::count_leaf_nodes(Node *p)
{
    if(p)
    {
        if(p->lchild==NULL && p->rchild==NULL)
        return count_leaf_nodes(p->lchild)+count_leaf_nodes(p->rchild)+1;
        else
        return count_leaf_nodes(p->lchild)+count_leaf_nodes(p->rchild);
    }
    else
    return 0;
}
int tree::count_nodes_deg2(Node* p)
{
    if(p)
    {
        if(p->lchild && p->rchild)
        {
            return count_nodes_deg2(p->lchild)+count_nodes_deg2(p->rchild)+1;
        }
        else
        {
            return count_nodes_deg2(p->lchild)+count_nodes_deg2(p->rchild);
        }
    }
    return 0;
}
int tree::count_nodes_deg1(Node* p)
{
    if(p)
    {
        if(p->lchild!=NULL ^ p->rchild!=NULL)
        {
            return count_nodes_deg1(p->lchild)+count_nodes_deg1(p->rchild)+1;
        }
        else
        {
            return count_nodes_deg1(p->lchild)+count_nodes_deg1(p->rchild);
        }
    }
    return 0;
}
int main()
{
    tree t;
    t.create_tree();
    
    cout<<"Preorder:"<<endl;
    t.preorder(t.getroot());
    cout<<endl;
    
    cout<<"INorder:"<<endl;
    t.inorder(t.getroot());
    cout<<endl;
    
    cout<<"Postorder:"<<endl;
    t.postorder(t.getroot());
    cout<<endl;
    
    cout<<"Levelorder:"<<endl;
    t.levelorder(t.getroot());
    cout<<endl;

    cout<<"Height: "<<t.height(t.getroot())<<endl;

    cout << "Iterative Preorder: ";
    t.iterativePreorder(t.getroot());
 
    cout << "Iterative Inorder: ";
    t.iterativeInorder(t.getroot());
 
    // cout << "Iterative Postorder: " << flush;
    // t.iterativePostorder(t.getroot());

    cout<<"No of nodes in the given tree are: "<<t.count_nodes(t.getroot())<<endl;
    cout<<"No of leaf nodes in the given tree are: "<<t.count_leaf_nodes(t.getroot())<<endl;
    cout<<"No of nodes with degree 1 in the given tree are: "<<t.count_nodes_deg1(t.getroot())<<endl;
    cout<<"No of nodes with degree 2 in the given tree are: "<<t.count_nodes_deg2(t.getroot())<<endl;


    return 0;
}