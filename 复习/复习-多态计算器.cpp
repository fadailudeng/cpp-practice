#include <iostream>
using namespace std;
class jasj
{
public:
    virtual int result()
    {
        return 0;
    }
    int num1;
    int num2;
};
class add:public jasj{
public:
    int result()
    {
        return num1+num2;
    }
};
class jian:public jasj{
public:
    int result()
    {
        return num1-num2;
    }

};
class cheng:public jasj{
public:
    int result()
    {
        return num1*num2;
    }
};
void show()
{
    jasj *s1=new add;
    s1->num1=100;
    s1->num2=100;
    delete s1;
    cout<<s1->num1<<"+"<<s1->num2<<"="<<s1->result()<<endl;
    s1=new jian;
    s1->num1=100;
    s1->num2=100;
    delete s1;
    cout<<s1->num1<<"-"<<s1->num2<<"="<<s1->result()<<endl;
    s1=new cheng;
    s1->num1=100;
    s1->num2=100;
    cout<<s1->num1<<"*"<<s1->num2<<"="<<s1->result()<<endl;
}


int main()
{
    show();
    return 0;
}