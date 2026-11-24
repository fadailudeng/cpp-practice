#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>


std::atomic<int> num=0;
void func()
{
    for(int i=0;i<100000;i++)
    {
        num++;
    }
}
 int main()
 {
    auto last=std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::thread t1(func);
    std::thread t2(func);
    t1.join();
    t2.join();
    //std::cout<<num<<std::endl;
    auto cur=std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout<<cur-last<<std::endl;

 }