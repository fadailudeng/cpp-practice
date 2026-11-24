#include <iostream>
using namespace std;
#include <stack>
#include <queue>
void text01()
{
    stack<int>p;
    p.push(10);
    p.push(20);
    p.push(30);
    p.push(40);
    cout<<"栈的大小为："<<p.size()<<endl;
    while(!p.empty())
    {
        cout<<"栈顶元素为: "<<p.top()<<endl;
        p.pop();
    }
    cout<<"栈的大小为："<<p.size()<<endl;
}
void text02()
{
    queue<int>q;
    {
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);
    }
    cout<<"队列的大小为："<<q.size()<<endl;
    while(!q.empty())
    {
        cout<<"队列头元素为："<<q.front()<<endl;
        q.pop();
    }
    cout<<"队列的大小为："<<q.size()<<endl;
}
int main()
{
    text02();
    text01();
    return 0;
}