#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Person
{
public:
    Person(string name,int age)
    {
        this->age=age;
        this->name=name;
    }
    string name;
    int age;
};
void myprint(int val)
{
    cout<<val<<endl;
}
void myprint2(Person &p)
{
    cout<<p.name<<"年龄为"<<p.age<<endl;
}
void printVector(vector<int>v)
{
    for(auto &a:v)
    {
        cout<<a<<" ";
    }
    cout<<endl;
}
void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    vector<int>::iterator itBegin =v.begin ();
    vector<int>::iterator itEnd=v.end();
    // while(itBegin!=itEnd)
    // {
    //     cout<<*itBegin<<endl;
    //     itBegin++;
    // }
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    } 
    cout<<"-----------------------"<<endl;
    for(auto &a:v)
    {
        if(a==20)
        {
            a=100;
        }
        cout<<a<<endl;
    }
    cout<<"-----------------------"<<endl;
    for_each(v.begin(),v.end(),myprint);
    
}
void test02()
{
    vector<Person>v;
    Person p("A",10);
    v.push_back(p);
    Person p2("B",15);
    v.push_back(p2);
    Person p3("C",10);
    v.push_back(p3);
    for(auto &a :v)
    {
        cout<<a.name<<"年龄为"<<a.age<<endl;
    }
    cout<<"----------------------"<<endl;
    for_each(v.begin(),v.end(),myprint2);
    cout<<"--------------------"<<endl;
    for(vector<Person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<it->name<<"年龄为"<<it->age<<endl;
    }
}
void test03()
{
    vector<Person*>v;
    Person p("A",10);
    v.push_back(&p);
    Person p2("B",15);
    v.push_back(&p2);
    Person p3("C",10);
    v.push_back(&p3);
    for(auto &a :v)
    {
        cout<<a->name<<"年龄为"<<a->age<<endl;
    }
    cout<<"----------------------"<<endl;
    for(vector<Person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)->name<<"年龄为"<<(*it)->age<<endl;
    }
}
void test04()
{
    vector<vector<int>>v;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
    for(int i=0;i<4;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for(auto &a:v)
    {
        for(auto &b:a)
        {
            cout<<b<<" ";
        }
        cout<<endl;
    }
    cout<<"----------------------------"<<endl;
    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        for(vector<int>::iterator it2=(*it).begin();it2!=(*it).end();it2++)
        {
            cout<<*it2<<" ";
        }
        cout<<endl;
    }
}
void test05()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    printVector(v);
    vector<int>v2(v.begin(),v.end());
    printVector(v2);
    vector<int>v3(10,100);
    printVector(v3);
    vector<int>v4(v3);
    printVector(v4);
}
void test06()
{
    vector<int>v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if(v1.empty())
    {
        cout<<"v1为空"<<endl;
    }
    else{
        cout<<"v1不为空"<<endl;
    }
    cout<<v1.capacity()<<endl;//容量
    cout<<v1.size()<<endl;
    v1.resize(15,100);//指定大小，并用什么填充
    printVector(v1);
    v1.resize(5);
    printVector(v1);
}
//删除插入
void test07()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    v.insert(v.begin(),100);


    v.insert(v.begin(),2,1000);
    v.erase(v.begin());
    v.erase(v.begin(),v.end());
    printVector(v);
}

//数据存取
void test08()
{
    vector<int> v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    // for(int i=0;i<10;i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<v.size();i++)
    // {
    //     cout<<v.at(i)<<" ";
    // }
    // cout<<endl;
    // cout<<"第一个元素为"<<v.front()<<endl;
    // cout<<"最后一个元素为"<<v.back()<<endl;
    printVector(v);
    vector<int>v2;
    for(int i=10;i>0;i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"----------------------------"<<endl;
    v.swap(v2);//交换
    printVector(v);
    printVector(v2);
}
//swap交换两个容器数据
void test09()
{
    vector<int>v;
    for(int i=0;i<10000;i++)
    {
        v.push_back(i);
    }
    cout<<"容量为"<<v.capacity()<<endl;
    cout<<"大小为"<<v.size()<<endl;
    cout<<"-----------------------"<<endl;
    v.resize(3);
    cout<<"容量为"<<v.capacity()<<endl;
    cout<<"大小为"<<v.size()<<endl;
    cout<<"-----------------------"<<endl;
    vector<int>(v).swap(v);
     cout<<"容量为"<<v.capacity()<<endl;
    cout<<"大小为"<<v.size()<<endl;
}
int *p=NULL;
void test10()
{
    vector<int>v;
    int num=0;
    v.reserve(100000);
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
        if(p!=&v[0])
        {
            p=&v[0];
            num++;
        }

    }
    cout<<num<<endl;
}
int main() 
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    //test09();
    test10();

    return 0;
}