#include<bits/stdc++.h>
#define SIZE 10
using namespace std;
class LinearProbing
{
    private:
    int H[SIZE]={0}; // the idea im thinking of is to incoporate this H[] array so that we dont have to pass this as a parameter everytime
    public:
    int hash(int key);
    int probe(int key);
    void insert(int key);
    int search(int key);
    void print_table();
};
int LinearProbing::hash(int key)
{
    return key%SIZE;
}
int LinearProbing::probe(int key)
{
    int index=hash(key);
    int i=0;
    while(H[index+i]%SIZE!=0)
    {
        i++;
    }
    return (index+i)%SIZE;
}
void LinearProbing::insert(int key)
{
    int index=probe(key);
    H[index]=key;
}
int LinearProbing::search(int key)
{
    int index=hash(key);
    int i=0;
    while(H[(index+i)%SIZE]!=key)
    {
        i++;
    }
    return (index+i)%SIZE;
}
void LinearProbing::print_table()
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
 LinearProbing LP;

 LP.insert(26);
 LP.insert(30);
 LP.insert(45);
 LP.insert(23);
 LP.insert(25);
 LP.insert(43);
 LP.insert(74);
 LP.insert(19);
 LP.insert(29);
 LP.print_table();
 printf("\nKey found at %d\n",LP.search(74));
 printf("\nKey not found %d\n",LP.search(54));

 return 0;
}