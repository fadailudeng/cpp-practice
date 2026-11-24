#include <iostream>
#include <thread>
#include <memory>
#include <mutex>
using namespace::std;
timed_mutex m1,m2;
void func_1()
{
    m1.lock();
    m2.lock();
    m1.unlock();
    m2.unlock();
}
void func_2()
{
    m2.lock();
    m1.lock();
    m1.unlock();
    m2.unlock();
}
int a=0;
void Add()
{
    for(int i=0;i<=2;i++)
    {
        unique_lock<timed_mutex> lg(m1,defer_lock); 
        if(lg.try_lock_for(chrono::seconds(1)))
        {
            this_thread::sleep_for(chrono::seconds(2));
            a+=1; 
        }
        
         
    }
}
int main()
{
    thread t1(Add);
    thread t2(Add);
    t1.join();
    t2.join();
    cout<<a<<endl;
    return 0;
}