#pragma once 

#include <stack>
#include <queue>
#include <exception>
#include <string>
#include <mutex>
#include <condition_variable>
#include <memory>
#include <thread>


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

        Stack& operator= (const Stack& other) =delete;

        Stack(const std::stack<T>& other){
            std::lock_guard<std::mutex> lock(stack_mutex_);
            stack_=other;
        }
        Stack(const Stack& other) {
            std::lock_guard<std::mutex> lock(stack_mutex_);
            stack_=other.stack_;
        }

        std::shared_ptr<T> pop(){
            std::lock_guard<std::mutex> lock(stack_mutex_);
            if(stack_.empty()) return nullptr; //throw StackException();
            auto res(std::make_shared<T>(std::move(stack_.top())));
            stack_.pop();
            return res;
        };
        
        void push(const T& value ){
            std::lock_guard<std::mutex> lock(stack_mutex_);
            stack_.push(value);
        }

        T top(){
            std::lock_guard<std::mutex> lock(stack_mutex_);
            return  stack_.top();
        }
        
        bool empty(){
            std::lock_guard<std::mutex> lock(stack_mutex_);
            return stack_.empty();
        }

    
     };
    

    template<typename T>
    class Queue {
        public:
            Queue(){};

            Queue& operator = (const Queue& other) = delete;

            Queue(const Queue& other){
                std::lock_guard<std::mutex> lock(mutex_);
                queue_ = other.queue_;
            }

            bool try_pop( T& value){
                std::lock_guard<std::mutex> lock(mutex_);
                if (queue_.empty())
                    return false;
                value = queue_.front();
                queue_.pop();
                return true;
            }

            std::shared_ptr<T>& try_pop () {
                std::lock_guard<std::mutex> lock(mutex_);
                if(queue_.empty())
                    return std::make_shared<T>();
                auto result = std::make_shared<T>(queue_.front());
                queue_.pop();
                return result;
            }

            void wait_pop( T& value){
                std::lock_guard<std::mutex> lock(mutex_);
                cv_.wait(lock, [this]{return !queue_.empty();});
                value = queue_.front();
                queue_.pop();
            } 
                
            void push( const T& value){
                std::lock_guard<std::mutex> lock(mutex_);
                queue_.push(value);
                cv_.notify_one();
            }

            bool empty(){
                std::lock_guard<std::mutex> lock(mutex_);
                return queue_.empty();
            }
        private:
            std::condition_variable cv_; 
            std::mutex mutex_;
            std::queue<T> queue_;
    };


    std::stack<int> StackFill(const int& nums){
        std::stack<int> results;
        for(size_t i=0; i<nums; ++i)
        {
            results.push(i);
        };
        return results;
    }
        

}
