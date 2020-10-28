#include <point.h>
#include <iostream>
#include <random>
#include <status.h>
//#include <new_features.h> 
#include <template/toy.hpp>
#include <vector>
#include <template/traits.hpp>
#include <threads/thread_pool.hpp>
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
    return 0;
}
