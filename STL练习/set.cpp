#include <iostream>
using namespace std;
#include <set>
#include <string>
/*
empty 判断是否为空
size 大小
s1.swap(s2)交换
insert 插入 也可迭代器插入 it
erase 删除 可传迭代器，区间或者指定数据 ereas(30)
find() 查找，找到返回迭代器位置，没找到返回。.end()
count() 统计指定元素个数，对于set而言只有0,1不允许重复
*/
void printSet(set<int>&s)
{
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void text02()
{
    //对组pair
    pair<string,int>p("啥",20);//第二种构造方法，pair<string,int>p=make_pair("",int)
    cout<<p.first<<p.second<<endl;//first第一个值，second获取第二个值
}
void text01()
{
    set<int>s1;
    s1.insert(19);
     s1.insert(39);
    s1.insert(29);
    s1.insert(49);
    printSet(s1);
    set<int>::iterator pos=s1.find(39);
    multiset<int>s2;//multiset 允许重复
}
class Comper{
    public:
    bool operator()(int v1,int v2) const
    {
        return v1>v2;
    }
};
void text03()
{
    //r如何修改排序顺序，需要仿函数用class创建类
    set<int,Comper>s1;
    s1.insert(19);
    s1.insert(39);
    s1.insert(29);
    s1.insert(49);
    for(set<int,Comper>::iterator it=s1.begin();it!=s1.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
int main()
{
    //text01();
    //text02();
    text03();
    return 0;
}