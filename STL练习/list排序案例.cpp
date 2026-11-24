#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <list>
class Person
{
    public:

    Person(string name,int age,int high)
    {
        this->name=name;
        this->age=age;
        this->high=high;
    }
    string name;
    int age;
    int high;
};
bool comperPerson(Person &p1,Person &p2)
{
    if(p1.age==p2.age)
    return p1.high>p2.high;
    else
    return p1.age<p2.age;
}
void printPerson(list<Person>&p)
{
    for(list<Person>::iterator it=p.begin();it!=p.end();it++)
    {
        cout<<"姓名为："<<(*it).name<<"年龄为："<<(*it).age<<"身高为："<<(*it).high<<endl;
    }
}
void creatPerson()
{
    list<Person>p;
    string name;
    int age,high;
    list<Person>::iterator it=p.begin();
    for(int i=0;i<6;i++)
    {
        cin>>name>>age>>high;
        Person p1(name,age,high);
        p.push_back(p1);
    }
    cout<<"排序前："<<endl;
    printPerson(p);
    cout<<"____________________________"<<endl;
    cout<<"排序后："<<endl;
    p.sort(comperPerson);
    printPerson(p);
}
int main()
{
    creatPerson();
    return 0;
}