#include <iostream>
using namespace std;
#include <thread>
#include<mutex>
class Log 
{
public:
static  Log *log=nullptr;
static  once_flag once;
static  mutex m1;
    Log(){};
    Log(const Log& log)= delete;
    Log& operator =(const Log& log)=delete;
    static Log& GetInstance(){
        //if(!log) log=new Log;
        call_once(once,init);
        return *log;
    }
    void PrintLog(string msg)
    {
        lock_guard<mutex> lock(m1);
        cout<<__TIME__<<" "<<msg<<endl;
    }
    static void init()
    {

        if(!log) log=new Log;
    }  
};
void Print_error()
{
    Log::GetInstance().PrintLog("Error");
}
int main()
{
    thread t1(Print_error);
    thread t2(Print_error);
    t1.join();
    t2.join();
    return 0;
}