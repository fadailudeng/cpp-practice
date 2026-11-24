#include <iostream>
using namespace std;
class Drinking
{
public:
    virtual void one()=0;
    virtual void second()=0;
    virtual void third()=0;
    virtual void fouth()=0;
    void dowork()
    {
        one();
        second();
        third(); 
        fouth();
    }
};
class coffee:public Drinking
{
public:
    void one()
    {
        cout<<"煮开水"<<endl;
    }
    void second()
    {
        cout<<"加咖啡"<<endl;
    }
    void third()
    {
        cout<<"冲泡"<<endl;
    }
    void fouth()
    {
        cout<<"加牛奶"<<endl;
    }
};
class tea:public Drinking
{
public:
    void one()
    {
        cout<<"煮开水"<<endl;
    }
    void second()
    {
        cout<<"加茶叶"<<endl;
    }
    void third()
    {
        cout<<"冲泡"<<endl;
    }
    void fouth()
    {
        cout<<"加枸杞"<<endl;
    }
};

void goWork(Drinking *abs)
{
    abs->dowork();
    delete abs;
}

void test01()
{
    goWork(new coffee);
    cout<<"------------------------------------"<<endl;
    goWork(new tea);
}


int main()
{
   test01();
    return 0;
}