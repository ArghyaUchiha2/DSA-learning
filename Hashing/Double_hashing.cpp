#include<bits/stdc++.h>
#define SIZE 10
#define PRIME 7
using namespace std;
class DoubleHashing
{
    private:
    int H[SIZE]={0}; // the idea im thinking of is to incoporate this H[] array so that we dont have to pass this as a parameter everytime
    public:
    int h1(int key);
    int h2(int key);
    int h_dash(int key);
    void insert(int key);
    int search(int key);
    void print_table();
};
int DoubleHashing::h1(int key)
{
    return key%SIZE;
}
int DoubleHashing::h2(int key)
{
    return PRIME-(key%PRIME);
}
int DoubleHashing::h_dash(int key)
{
    int i=0;
    while(H[(h1(key)+i*h2(key))%SIZE]!=0)
    {
        i++;
    }
    return (h1(key)+i*h2(key))%SIZE;
}
void DoubleHashing::insert(int key)
{
    int index=h_dash(key);
    H[index]=key;
}
int DoubleHashing::search(int key)
{
    int i=0;
    while(H[(h1(key)+i*h2(key))%SIZE]!=key)
    {
        i++;
    }
    return (h1(key)+i*h2(key))%SIZE;
}
void DoubleHashing::print_table()
{
    cout<<"Hash Table:"<<endl;
    for(int i=0;i<SIZE;i++)
    {
        cout<<H[i]<<endl;
    }
    cout<<endl;
}
int main()
{
 DoubleHashing LP;

 LP.insert(5);
 LP.insert(15);
 LP.insert(25);
 LP.insert(35);
 LP.insert(95);
 LP.print_table();
 printf("\nKey found at %d\n",LP.search(35));
 printf("\nKey not found %d\n",LP.search(54));

 return 0;
}