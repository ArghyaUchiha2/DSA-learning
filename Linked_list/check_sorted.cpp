#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
} *first(NULL);
void createlist(int A[], int n)
{
    node *t, *last;
    first = new node(A[0]);
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new node(A[i]);
        last->next = t;
        last = t;
    }
}
void displaylist(node *p)
{
    while (p != 0)
    {
        cout << p->data << "->";
        p = p->next;
    }
    cout << "NULL" << endl;
}
void checksort(node *p)
{
    int x = INT_MIN;
    while (p->next != 0)
    {
        if (p->data < x)
        {
            cout << "List is not sorted." << endl;
            return;
        }
        x = p->data;
        p = p->next;
    }
    cout << "List is sorted." << endl;
}
int main()
{
    // int A[]={2,5,3,14,27,42,12,9};
    int A[] = {1, 2, 3, 4};
    int len = sizeof(A) / sizeof(A[0]);
    createlist(A, len);
    displaylist(first);
    checksort(first);
    return 0;
}