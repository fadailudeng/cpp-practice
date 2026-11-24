#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
void myPrit(int val)
{
    cout<<val<<endl;
}
class Person
{
     public:
     Person(string name,int age)
     {
        this->name=name;
        this->age=age;
     }
    string name;
    int age;
};
void text01()
{
    vector<int>v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    vector<int>::iterator pBign=v.begin();
    vector<int>::iterator pEnd=v.end();
  /*  for(pBign;pBign!=pEnd;pBign++)
    {
        cout<<*pBign<<endl;
    }*/
    for_each(v.begin(),v.end(),myPrit);
}
void text02()
{
    Person p1("aaa",10);
    Person p2("bbb",20);
    Person p3("ccc",30);
    Person p4("ddd",40);
    vector<Person> v;
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for(vector<Person>::iterator it=v.begin();it<v.end();it++)
    {
        cout<<"ÐÕÃû:"<<it->name<<"ÄêÁä:"<<it->age<<endl;
    }
}
void text03()
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
    for(vector<vector<int>>::iterator it=v.begin();it<v.end();it++)
    {
        for(vector<int>::iterator vit=(*it).begin();vit<(*it).end();vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    text03();
    return 0;
}