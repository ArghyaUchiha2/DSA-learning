#include<bits/stdc++.h>
using namespace std; 
class Node
{
    public:
    int data;
    Node* lchild;
    Node* rchild;
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
class BST
{
    private:
    Node* root;
    public:
    BST()
    {
        root=NULL;
    }
    BST(int arr[],int n)
    {
        root=NULL;
        root=recursive_insert(root,arr[0]);
        // iterative_insert(arr[0]);
        for(int i=1;i<n;i++)
        {
            recursive_insert(root,arr[i]);
            // iterative_insert(arr[i]);
        }
    }
    Node* getroot(){return root;}
    void iterative_insert(int key);
    Node* recursive_insert(Node* p,int key);
    Node* search(int key);
    void preorder(Node* p);
    void inorder(Node* p);
    Node* inPre(Node* p);
    Node* inSucc(Node* p);
    int height(Node* p);
    Node* Delete(Node* p,int key);
};
void BST::iterative_insert(int key)
{
    Node* t,*r;
    t=r=root;
    if(root==NULL)
    {
        root=new Node(key);
        return;
    }
    while(t)
    {
        r=t;
        if(t->data==key)
        {
            return;
        }
        if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    t=new Node(key);
    if(key<r->data)
    {
        r->lchild=t;
    }
    else
    {
        r->rchild=t;
    }
}
Node* BST:: recursive_insert(Node*p, int key)
{
    Node* t;
    if(p==NULL)
    {
        t=new Node(key);
        return t;
    }
    else
    {
        if(key < p->data)
        {
            p->lchild=recursive_insert(p->lchild,key);
        }
        else if(key > p->data)
        {
            p->rchild=recursive_insert(p->rchild,key);
        }
        else
        {
            cout<<"Duplicate."<<endl;
        }
        return p;
    }
}
Node* BST::search(int key)
{
    Node* t=root;
    while(t)
    {
        if(key==t->data)
        {
            cout<<key<<" is present"<<endl;
            return t;
        }
        if(key<t->data)
        {
            t=t->lchild;
        }
        else
        {
            t=t->rchild;
        }
    }
    cout<<key<<" is not present."<<endl;
    return NULL;
}
void BST:: preorder(Node *p)
{
    if(p)
    {
    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
    }
    else
    return;
}
void BST:: inorder(Node *p)
{
    if(!p)
    {
        return;
    }
    inorder(p->lchild);
    cout<<p->data<<" ";
    inorder(p->rchild);
}
Node* BST::inPre(Node* p)
{
    while(p && p->rchild)
    {
        p=p->rchild;
    }
    return p;
}
Node* BST::inSucc(Node* p)
{
    while(p && p->lchild)
    {
        p=p->lchild;
    }
    return p;
}
int BST::height(Node* p)
{
    int x,y;
    if(p==NULL)
    {
        return 0;
    }
    x=height(p->lchild);
    y=height(p->rchild);
    return x>y? x+1:y+1;
}
Node* BST::Delete(Node *p,int key)
{
    if(p=NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root=NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p->data)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key > p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        Node *q;
        if(height(p->lchild) > height(p->rchild))
        {
            q=inPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=inSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    int arr[]={25,6,2,72,100,27,43,8,3,7,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    BST bst(arr,n);

    bst.search(56);
    bst.search(75);

    cout<<"Preorder: ";
    bst.preorder(bst.getroot());
    cout<<endl;

    cout<<"Inorder: ";
    bst.inorder(bst.getroot());
    cout<<endl;

    cout<<"height: "<<bst.height(bst.getroot())<<endl;
    // bst.iterative_insert(75);
    bst.recursive_insert(bst.getroot(),1); 

     bst.search(56);
     bst.search(75);
    
    bst.Delete(bst.getroot(),72);

    cout<<"Preorder: ";
    bst.preorder(bst.getroot());
    cout<<endl;

    cout<<"Inorder: ";
    bst.inorder(bst.getroot());
    cout<<endl;

    return 0;
}