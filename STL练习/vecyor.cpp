#include <iostream>
using namespace std;
#include <vector>
#include <string>
void printvector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it<v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void text01()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    if(v1.empty())
    {
        cout<<"v1不为空"<<endl;
    }
    else
    {
        cout<<"v1为空"<<endl;
    }
    cout<<v1.size()<<endl;
    cout<<v1.capacity()<<endl;
    v1.resize(15,10);
    printvector(v1);
    v1.pop_back();//尾删
    printvector(v1);
    v1.insert(v1.begin(),2,100);//插入指定元素指定个数
     printvector(v1);
    v1.erase(v1.begin());//删除指定
     printvector(v1);
    v1.erase(v1.begin(),v1.end());//删除区间
     printvector(v1);
}
int main()
{
    text01();
    return 0;
}