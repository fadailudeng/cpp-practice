#include <iostream>
using namespace std;
#include <stack>
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
int main()
{
    text01();
    return 0;
}