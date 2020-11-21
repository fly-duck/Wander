#include <point.h>
#include <iostream>
#include <random>
#include <status.h>
//#include <new_features.h> 
#include <template/toy.hpp>
#include <vector>
#include <template/traits.hpp>
#include <threads/thread_pool.hpp>
#include <test/test.h>
#include <threads/threadsafe_datastructure.hpp>
#include <test/notype_template_test.hpp>


using namespace Wander;
using EarthMan = Human<int>;
using MarsMan  = Human<double> ;
using MoonMan  = Human<long double>;
using V_EHuman = std::vector<EarthMan>;
int main()
{
    Wander::Point<int, 3> p;
    std::cout<<p.GetPoint<1>()<<"\n";

    p.SetPoint<1>(2);
    std::cout<<p.GetPoint<1>()<<"\n";
   

    std::cout<< Wander::copyable<Wander::Robot<int>>  <<"\n";
    Wander::Status<int> i;

    std::cout<< "Template :" << "==<<\n";

    EarthMan em,em2;
    MarsMan  mm;
    MoonMan  mom;
//  PrintHumansize<EarthMan,MarsMan, MoonMan>(em,mm,mom);
    
    std::vector<EarthMan> v_Ehuman;
    v_Ehuman.push_back(em);
    v_Ehuman.push_back(em2);


    std::vector<int> ___ints{1,2,3};
    PrintContainer<1,0>(v_Ehuman);
    PrintContainer<1,2>(___ints);

    std::cout<< IsSame(em,mm)<<"\n";
    std::cout<< IsSame(em,em2)<<"\n";
    
    int* fw_obj= new int(122);
    Perfect_ForWarding(fw_obj);
    std::cout<< *fw_obj<<"\n";
   
    Print_Traits( long(12312312312.23f));
    

    Stack<int,false> stack_a(Wander::StackFill(100));
   
    std::stack<int> no_threadsafe_stack=Wander::StackFill(100);
    Concurent_Printer printer;


   std::promise<bool> b1,b2;
   auto future1 = b1.get_future();
   auto future2 = b2.get_future();

   std::thread thread1([&stack_a,&printer,&b1]{ 
   for(int i=0; i<100; ++i){
       printer.Print_Stack<Wander::Stack<int,false>>(stack_a);} 
       b1.set_value(true);
       });

   std::thread thread2([&stack_a,&printer,&b2]{ 
   for(int i=0; i<100; ++i){
       printer.Print_Stack<Wander::Stack<int,false>>(stack_a);}
       b2.set_value(true);
       });
   
   thread1.join();
   thread2.join();
   
    
    std::cout<< " thread safe complete " << "\n";
    

    //std::thread thread3([&no_threadsafe_stack]{ 
    //for(int i=0; i<100; ++i){
    //    Wander::Print_Stack<d::stack<int>>(no_threadsafe_stack);}});
 
    //std::thread thread4([&no_threadsafe_stack]{ 
    //for(int i=0; i<100; ++i){
    //    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //    Wander::Print_Stack<std::stack<int>>(no_threadsafe_stack);}});
   using namespace std::chrono_literals; 
    if(0&&future1.wait_for(0ms)==std::future_status::ready && future2.wait_for(0ms) == std::future_status::ready)
    {
    std::thread thread3([&no_threadsafe_stack,&printer]{ 
    for(int i=0; i<100; ++i){
        printer.Print_Stack<std::stack<int>>(no_threadsafe_stack);}});
 
    std::thread thread4([&no_threadsafe_stack,&printer]{ 
    for(int i=0; i<100; ++i){
        //std::this_thread::sleep_for(std::chrono::seconds(1));
        printer.Print_Stack<std::stack<int>>(no_threadsafe_stack);}});
  
    
    thread3.join();
    thread4.join();
    }

    Test test; 

    test.run_test();
    // need to complete in main thread
    std::cout<< "done!" <<"\n"; 


        

    return 0;
}
