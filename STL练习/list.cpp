#include <iostream>
using namespace std;
#include <list>
void printList(list<int>&l)
{
    for(list<int>::iterator it=l.begin();it!=l.end();it++)
    {
        cout<<*it<<" " ;
    }
    cout<<endl;
}
void text01()
{
    list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    list<int>l2=l1;
    list<int>l3(l1.begin(),l1.end());
    printList(l2);
    printList(l3);
    list<int>l4(10,100);
    printList(l4);
    l3.swap(l4);
    printList(l3);
    printList(l4);
}
void text02()
{
     list<int>l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);
    printList(l1);
    if(l1.empty())
    {
        cout<<"l1为空┖"<<endl;
    }
    else
    cout<<"l1不为空"<<endl;
    cout<<"l1的大小为 "<<l1.size()<<endl;
    l1.resize(10,100);
    printList(l1);
    l1.resize(5);
    printList(l1);
    l1.remove(100);
    printList(l1);
}
int main()
{
    //text01();
    text02();

    return 0;
}