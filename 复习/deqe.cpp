#include <iostream>
using namespace std;
#include <deque>
#include <string>
void printDeque(deque<int>q)
{
    for(auto &a:q)
    {
        cout<<a<<" ";
    }
    cout<<endl;
}
void printDeque2(deque<int>q)
{
    for(deque<int>::iterator it=q.begin();it!=q.end();it++)
    {
        cout<<*it;
    }
    cout<<endl;
}
void test01()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
    deque<int>d2(d1.begin(),d1.end());
    printDeque(d2);
    deque<int>d3(d2);
    printDeque(d3);
    deque<int>d4(10,100);
    printDeque(d4);
    deque<int>d5=d4;
    printDeque(d5);
    deque<int>d6;
    d6.assign(d5.begin(),d5.end());
    printDeque(d6);
}
int main()
{

    test01();



    return 0;
}