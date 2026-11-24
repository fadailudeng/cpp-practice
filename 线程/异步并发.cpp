#include<iostream>
#include <future>
// int func()
// {
//     int i=0;
//     for(i=0;i<1000;i++)
//     {
//        i++;
//     }
//     return i;
// }
void func(std::promise<int> &f){
    f.set_value(1000);
}
int main()
{
    //std::thread t1(func);
    //std::thread t2(func);
   // std::future<int> future_result = std::async(std::launch::async,func);//后台运行不阻塞
    // std::packaged_task<int()> task(func);
    // auto future_result=task.get_future();

    // std::thread t1(std::move(task));

    // std::cout<<func()<<std::endl;
    // t1.join();
    // std::cout<<future_result.get()<<std::endl;
    std::promise<int> f;
    auto future_result=f.get_future();
    std::thread t1(func,ref(f));
    t1.join();
    std::cout<<future_result.get()<<std::endl;
}