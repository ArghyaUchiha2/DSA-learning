#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int height;
    Node()
    {
        data = -1;
        lchild = rchild = NULL;
        height = 1;
    }
    Node(int x)
    {
        data = x;
        lchild = rchild = NULL;
        height = 1;
    }
};
class AVL
{
private:
public:
    Node *root;
    AVL()
    {
        root = NULL;
    }
    AVL(int arr[], int n)
    {
        root=NULL;
        // root=rInsert(root,arr[0]);
        cout<<"check!"<<endl;
        for (int i = 0; i < n; i++)
        {
            rInsert(root,arr[i]);
        }
    }
    Node *getroot() { return root; }

    // Helper functions for inserting
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLrotation(Node *p);
    Node *LRrotation(Node *p);
    Node *RRrotation(Node *p);
    Node *RLrotation(Node *p);

    // Insert
    Node *rInsert(Node *p, int key);

    // Traversal
    void Inorder(Node *p);
    void Preorder(Node *p);

    //delete
    Node* Delete();//to be done
};
int AVL::NodeHeight(Node *p) // here can be a problem
{
    int hl, hr;
    hl = (p && p->lchild != 0) ? p->lchild->height : 0;
    hr = (p && p->rchild != 0) ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}
int AVL:: BalanceFactor(Node* p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return hl - hr;
}
Node *AVL::LLrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->lchild = plr;
    pl->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
    {
        root = pl;
    }
    return pl;
}
Node *AVL::LRrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    p->lchild = plr->lchild;
    pl->rchild = plr->lchild;

    plr->rchild = p;
    plr->lchild = pl;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (root == p)
    {
        root = plr;
    }
    return plr;
}
Node *AVL::RRrotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl;
    pr->lchild = p;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);

    if (root == p)
    {
        root = pr;
    }
    return pr;
}
Node *AVL::RLrotation(Node *p)
{
    Node *pr = p->rchild;
    Node *prl = pr->lchild;

    p->rchild = prl->lchild;
    pr->lchild = prl->rchild;

    prl->lchild = p;
    prl->rchild = pr;

    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
    prl->height = NodeHeight(prl);

    if (root = p)
    {
        root = prl;
    }
    return prl;
}
Node *AVL::rInsert(Node *p, int key)
{
    Node *t;
    if (root == NULL)
    {
        root = new Node(key);
        return root;
    }
    if (p == NULL)
    {
        t = new Node(key);
        return t;
    }
    if (key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }

    // Update height
    p->height = NodeHeight(p);

    // Balancefactor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1)
    {
        return RRrotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        return RLrotation(p);
    }
    return p;
}

void AVL::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
void AVL::Preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

int main()
{

    // LR Rotation
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);

    cout << "Inorder: ";
    tlr.Inorder(tlr.getroot());
    cout << endl;
    cout << tlr.root->data << endl;

    cout << "Preorder: ";
    tlr.Preorder(tlr.getroot());
    cout << endl;
    cout << tlr.root->data << endl;

    // RL Rotation
    AVL trl;
    trl.root = trl.rInsert(trl.root, 20);
    trl.root = trl.rInsert(trl.root, 50);
    trl.root = trl.rInsert(trl.root, 30);

    cout << "Inorder: ";
    trl.Inorder(trl.getroot());
    cout << endl;
    cout << trl.root->data << endl;

    cout << "Preorder: ";
    trl.Preorder(trl.getroot());
    cout << endl;
    cout << trl.root->data << endl;

    int arr[]={2,6,72,3,43,8,9,7};
    int n=sizeof(arr)/sizeof(arr[0]);

    AVL mytree(arr,n);
    
    cout << "Inorder: ";
    mytree.Inorder(mytree.getroot());
    cout << endl;
    cout <<"Root: "<< mytree.root->data << endl;

    cout << "Preorder: ";
    mytree.Preorder(mytree.getroot());
    cout << endl;
    cout<<"Root: " << mytree.root->data << endl;

    return 0;
}