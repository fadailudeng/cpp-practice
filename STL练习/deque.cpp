#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>
#include <vector>
void printDeque(deque<int>&d)
{
    for(deque<int>::iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void text01()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1);
    printDeque(d2);
    deque<int>d3(d1.begin(),d1.end());
    printDeque(d3);
    deque<int>d4(10,100);
    printDeque(d4);
}
void text02()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2;
    d2=d1;
    printDeque(d2);
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printDeque(d3);
    deque<int>d4;
    d4.assign(10,100);
    printDeque(d4);
    if(d1.empty())
    {
        cout<<"d1为空┖"<<endl;
    }
    else
    {
        cout<<"d1不为空"<<endl;
        cout<<"d1的大小为"<<d1.size()<<endl;
    }
    d1.resize(15,100);
    printDeque(d1);
    d1.resize(5);
    printDeque(d1);
}
void text03()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    printDeque(d1);
    d1.insert(d1.begin(),100);
    printDeque(d1);
    d1.insert(d1.begin(),2,100);
    printDeque(d1);
    d1.erase(d1.begin());
    printDeque(d1);
    d1.clear();
    printDeque(d1);
}
void text04()
{
    deque<int>d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    printDeque(d1);
    sort(d1.begin(),d1.end());
    printDeque(d1);
}
int main()
{
//    text01();
    //text02();
    //text03();
    text04();
    return 0;;
}