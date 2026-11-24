#include<iostream>


template<typename R,typename...Args>
struct ICallable{
    virtual R invoke(Args&&... args)=0;

    virtual ~ICallable() {}

};

template<typename T,typename R,typename...Args>
class ICallableImp :public ICallable<R,args ...>
{
    T callable;
public:
    ICallableImp(T&& c):callable(std::move(c)){}
    R invoke(Args... args) override{
       return callable(std::forword<Args>(args)...);
    }
};

template<typename Signature>
class Myfunction;
template<typename R,typename...Args>
class Myfunction<R(Args...)>{
    ICallablev *function
};





int main()
{

}
