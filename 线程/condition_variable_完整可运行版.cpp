// 生产者-消费者模型：mutex + condition_variable
// 由 condition_varibal.cpp 补全而来（原稿保留未动，可对照看差在哪）
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

mutex mtx;                 // 保护 q 的互斥量
condition_variable q_cv;   // 广播"队列状态变了"
queue<int> q;

const int kItemCount = 10;  // 生产多少个数据
const int kPill      = -1;  // 结束标记（毒丸）

void producer()
{
    for (int i = 0; i < kItemCount; ++i)
    {
        this_thread::sleep_for(chrono::milliseconds(50));  // 模拟生产耗时
        {
            lock_guard<mutex> lock(mtx);   // 有名字的锁：作用域结束才释放
            q.push(i);
            cout << "生产 " << i << "\t队列大小 " << q.size() << endl;
        }
        q_cv.notify_one();                 // 通知消费者：有货了
    }

    {
        lock_guard<mutex> lock(mtx);
        q.push(kPill);                     // 毒丸：告诉消费者别再等了
    }
    q_cv.notify_one();
    cout << "生产者结束" << endl;
}

void consumer()
{
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        // 队列空就睡在这里；被唤醒后先重新检查条件，防虚假唤醒
        q_cv.wait(lock, [] { return !q.empty(); });

        int value = q.front();
        q.pop();
        lock.unlock();                     // 取完就放手，别占着锁去打印

        if (value == kPill)
        {
            cout << "消费者收到结束标记，退出" << endl;
            break;
        }
        cout << "消费 " << value << endl;
    }
}

int main()
{
    thread t_producer(producer);
    thread t_consumer(consumer);

    t_producer.join();
    t_consumer.join();

    cout << "全部线程结束，主线程收工" << endl;
    return 0;
}
