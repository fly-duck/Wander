#pragma once
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <atomic>
#include <threads/threadsafe_datastructure.hpp>
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
                done = true;
                }
            
            ~ThreadPool(){
                done = true;
            }

            template<typename FunctionType>
            void summit(FunctionType f)
            {
                work_queue.push(std::function<void()>(f));
            }
        private:
            std::atomic_bool done;
            std::vector<std::thread> threads;
            Queue< std::function<void()>> work_queue; 
    };

    

    namespace boost {
        namespace asio {
           

        }}}

