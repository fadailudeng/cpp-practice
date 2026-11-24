#include <iostream>
#include <string>
using namespace std;
class Person
{
    friend class goodGay;
public:
    Person()
    {
        sittingroom="客厅";
        bedroom="卧室";
    }
    void showAge() const
    {
           age=100;
    }
    mutable int age;
 
    void showName()
    {

    }
    int id;
public:
    string sittingroom;
private:
    string bedroom;
};
class goodGay
{
public:
    Person p1;
    void visit()
    {
        cout<<"好朋友正在访问"<<p1.sittingroom<<endl;
        cout<<"好朋友正在访问"<<p1.bedroom<<endl;
    }
};
void test01(goodGay g)
{
   g.visit();
}
int main()
{
    goodGay gg;      
    test01(gg);      
    return 0;
}