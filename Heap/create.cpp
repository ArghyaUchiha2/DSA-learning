#include <bits/stdc++.h>
using namespace std;
void insert(int arr[], int n)
{
    int i = n;
    while (i > 1 && arr[i] > arr[i / 2])
    {
        swap(arr[i], arr[i / 2]);
        i = i / 2;
    }
}
void create_heap(int arr[], int n)
{
    for (int i = 2; i < n; i++)
    {
        insert(arr, i);
    }
}
void printarray(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void Delete(int arr[],int n)
{
    int x,i,j;
    i=1;
    j=2*i;
    x=arr[1];
    arr[1]=arr[n-1];
    while(j<n-1)
    {
        if(arr[j+1]>arr[j])
        {
            j=j+1;
        }
        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
            j=2*j;
        }
        else
        {
            break;
        }
    }
    arr[n-1]=x;
}
void heap_sort(int arr[],int n)
{
    for(int i=n;i>1;i--)
    {
        Delete(arr,i);
    }
}
void heapify(int arr[],int n,int i)
{
    int largest=i,larger_child;
    int l=2*i;
    int r=2*i+1;


    if(arr[l]>arr[r])
    {
        larger_child=l;
    }
    else
    {
        larger_child=r;
    }
    if(arr[largest]<arr[larger_child])
    {
        swap(arr[largest],arr[larger_child]);
        largest=larger_child;
    }
    if(largest!=i)
    {
        heapify(arr,n,largest);
    }
    
}
void heapify(int arr[],int n)
{
    //leaf elements start from (n/2)+1, so we need to start heapify from its parents,i.e. n/2
    for(int i=(n/2);i>0;i--)
    {
        int j=2*i;
        while(j<n-1)
        {
        if(arr[j]<arr[j+1])
        {
            j=j+1;
        }
        if(arr[i]<arr[j])
        {
            swap(arr[i],arr[j]);
            i=j;
            j=2*i;
            heapify(arr,n,j);
        }
        else
        {
            break;
        }
        }
    }
}
int main()
{
    int arr[] = {0,5,10,25,35,30,40,15}; // arr[0] is given 0 as our indexing starts from 1
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array:" << endl;
    printarray(arr, n);
    create_heap(arr, n);
    cout << "Heap:" << endl;
    printarray(arr, n);

    cout <<"Heap sort:"<<endl;
    heap_sort(arr,n);
    printarray(arr,n);
    
    create_heap(arr,n);//making max heap once again
    cout<<"After delete:"<<endl;
    Delete(arr,n);
    printarray(arr, n);

    cout<<"After delete:"<<endl;
    Delete(arr,n-1);
    printarray(arr, n);

    heapify(arr,n);
    cout<<"After heapify:"<<endl;
    printarray(arr,n);
    return 0;
}