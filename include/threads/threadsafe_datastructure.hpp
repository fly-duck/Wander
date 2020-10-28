#pragma once 

#include <stack>
#include <exception>
#include <string>
#include <mutex>

namespace Wander{
    struct StackException :public std::exception {
        const char* what() const throw();
       // std::string what() const throw();
    };
    
    template<typename T, bool lock_free>
    class Stack {
    private:
        mutable std::mutex stack_mutex_;
        std::stack<T> stack_;
    public:
        Stack(){};
        Stack(const Stack& other) {} 
    };
}
