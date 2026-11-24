#include <iostream>
#include <thread>
#include <mutex>
#include <string>
#include <condition_variable>
#include <queue>

using namespace std;
queue<int> q;
condition_variable q_cv;
mutex m1;
void producer()
{
    for(int i=0;i<10;i++)
    {
        {
            unique_lock<std::mutex>lock(m1);
            q.push(i);
            cout<<"task :"<<i<<endl;
        }
        q_cv.notify_one();
        this_thread::sleep_for(chrono::microseconds(100));
    }
    
}

void Consumer()
{
    while(1)
    {
        unique_lock<std::mutex>lock(m1);
        q_cv.wait(lock,[]{
            return !q.empty();
        });
        int value=q.front();
        cout<<"Consumer: "<<value<<endl;
        q.pop();
    }
}

int main()
{
    thread t1(producer);
    thread t2(Consumer);
    t1.join();
    t2.join();

    return 0;
}