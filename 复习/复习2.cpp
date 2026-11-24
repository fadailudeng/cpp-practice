#include <iostream>
#include <string>
using namespace std;
class Animal{
public:
     virtual void ShowName()
    {
        cout<<"动物在说话"<<endl;
    }
    string name="animal";
};
class cat:public Animal
{
public:
    void ShowName()
    {
        cout<<"猫在说话"<<endl;
    }
};
class dog:public Animal
{
public:
    void ShowName()
    {
        cout<<"小狗在说话"<<endl;
    }
};

void test01(Animal &animal)
{
    animal.ShowName();
}
int main()
{
    cat c1;
    test01(c1);
    dog d1;
    test01(d1);
    return 0;
}