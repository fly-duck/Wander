#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <atomic>
#include <threads/threadsafe_datastructure.hpp>
#include <iostream>
#include <future>
//#include <boost/asio/detail/config.hpp>
//#include <boost/asio/detail/noncopyable.hpp>
//#include <boost/asio.hpp>
namespace Wander {
    
    class ThreadPool {
        public:
            ThreadPool(): done(false){
            const unsigned int thread_count = std::thread::hardware_concurrency();
            try {
                for(unsigned int i = 0; i< thread_count ; ++i)
                {
                    threads.push_back(
                           // Worker_Thread() on this thread
                            std::thread(&ThreadPool::Worker_Thread,this));
                }
            }

            catch(...)
            { 
                done = true;     
                throw; 
            }
           
            }
           
            void Worker_Thread() {
                while(!done)
                {
                    std::function<void()> task;
                    if(work_queue.try_pop(task))
                    {
                        task();
                    } else 
                    {
                        // take a small break
                        std::this_thread::yield();
                    }
                }
                }
            
            ~ThreadPool(){
                done = true;
            }

            template<typename FunctionType>
            void summit(FunctionType f)
            {
                work_queue.push(std::function<void()>(f));
            }


            void accumulate(){
                value_++;
                std::cout<< "thread pool : " << value_ << "\n";
            }
        private:
            unsigned int value_;
            std::atomic_bool done;
            std::vector<std::thread> threads;
            Queue< std::function<void()>> work_queue; 
    };

    template<typename FunctionType>
    void PackingTask(FunctionType f)
    {
        using result_type = typename std::result_of<FunctionType()>::type;
        std::packaged_task<FunctionType> task(std::move(f));
        //std::packaged_task<result_type()> task(std::move(f)); 
    }

    namespace boost {
        namespace asio {
           

        }}}

