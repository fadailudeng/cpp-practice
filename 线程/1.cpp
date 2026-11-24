#include <iostream>
#include <thread>
#include <string>
#include <memory>
using namespace std;
class P
{
    friend void thread_func();
public:
    void func()
    {
        std::cout<<"hello"<<std::endl;
    }
private:
    void Prinf()
    {
        std::cout<<"hello"<<std::endl;
    }
};
void Print(std::string a)
{
    std::cout<<a<<std::endl;
}
void foo(int &x)
{
    x+=1;
}
void test01(int *p)
{
    std::cout<<*p<<std::endl;
}
void thread_func()
{
    //std::shared_ptr<P> a=std::make_shared<P>();//智能指针，a为执行class P对象的指针
    auto a=std::make_shared<P>();//
    std::thread t1(&P::Prinf,a);
    t1.join();
    
}
int main()
{
//     std::thread thread1(Print,"hello world");
//    // thread1.join();等待子线程结束继续往下主线程等待
//    //thread1.detach();//分离子线程在后台运行
//    bool is=thread1.joinable();//检测是否能够调用join或detach，若强行system错误
//     if(is)
//     {
//         thread1.join();
//     }
    // int a=1; 
    // int *ptr=new int (2);
    // std::thread t1(test01,ptr);
    // delete ptr;
    // t1.join();
    // std::thread t1(foo,std::ref(a));//转换为引用类型变量，引用和指针指向局部变量会出出错
    // t1.join();
    // std::cout<<a<<endl;
    // std::shared_ptr<P> a=std::make_shared<P>();
    // std::thread t1(&P::func,a);
    // t1.join();
    thread_func();
    return 0;
}