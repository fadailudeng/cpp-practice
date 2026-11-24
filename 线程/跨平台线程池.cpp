#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
class Thread
{
public:
    Thread(int numThreads):stop(false)
    {
        for(int i=0;i<numThreads;i++)
        {
            threads.emplace_back([this]{ 
                while(1)
                {
                    unique_lock<std::mutex>lock(m1);
                    cv.wait(lock,[this]{
                        return !q.empty() || stop;
                    });
                    if(stop&&q.empty()){
                        return;
                    }
                    function<void()> task(move(q.front()));
                    q.pop();
                    lock.unlock();
                    task();
                }
            });
        }
    }
    ~Thread(){
        {
            unique_lock<std::mutex>lock(m1);
            stop=true;
        }
        cv.notify_all();
        for(auto &t:threads)
        {
            t.join();
        }
    }
    template<class F,class... Args>
    void enqueue(F &&f,Args&&... args){
    function<void()>task=bind(forward<F>(f),forward<Args>(args)...);
    {
        unique_lock<std::mutex>lock(m1);
        q.emplace(move(task));
    }
    cv.notify_one();
    }
    vector<thread> threads;
    queue<function<void()>> q;
    mutex m1;
    condition_variable cv;
    bool stop;
};
int main()
{
    Thread pool(4);
    for(int i=0;i<10;i++)
    {
        pool.enqueue([i]{
            cout<<"task "<<i<<"is running"<<endl;
            this_thread::sleep_for(chrono::seconds(1));
            cout<<"task: "<<i<<"is done"<<endl;
        });
    }
    return 0;
}