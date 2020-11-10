#pragma once 
#include <iostream>
#include <threads/threadsafe_datastructure.hpp>
#include <stack>
#include <chrono>
namespace Wander {



//https://stackoverflow.com/questions/4484982/how-to-convert-typename-t-to-string-in-c
template <typename T>
struct TypeName
{
    static const char* Get()
    {
        return typeid(T).name();
    }
};

// a specialization for each type of those you want to support
// and don't like the string returned by typeid
template <>
struct TypeName<std::stack<int>>
{
    static const char* Get()
    {
        return "std::stack<int>";
    }
};


template <>
struct TypeName<Wander::Stack<int,false>>
{
    static const char* Get()
    {
        return "Wander::Stack<int,false>";
    }
};
// usage:
//const char* name = TypeName<MyType>::Get();

    class Concurent_Printer{
    public:
    

    //need to implement type traits or concepts 
    template<typename StackType>
    void Print_Stack(StackType & tmp){
        const std::lock_guard<std::mutex> lock(mutex_);
        int val=tmp.top();
        tmp.pop();
        std::cout<<TypeName<StackType>::Get()<<" "<<val<<"\n";
        if (tmp.empty())
            return;
    }

    private:

    std::mutex mutex_;


    };
}
