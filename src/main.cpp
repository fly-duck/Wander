#include <point.h>
#include <iostream>
#include <random>
#include <status.h>
//#include <new_features.h> 
#include <template/toy.hpp>


using namespace Wander;
using EarthMan = Human<int>;
using MarsMan  = Human<double> ;
using MoonMan  = Human<long double>;

int main()
{
    Wander::Point<int, 3> p;
    std::cout<<p.GetPoint<1>()<<"\n";

    p.SetPoint<1>(2);
    std::cout<<p.GetPoint<1>()<<"\n";
   

    std::cout<< Wander::copyable<Wander::Robot<int>>  <<"\n";
    Wander::Status<int> i;

    std::cout<< "Template :" << "==<<\n";

    EarthMan em;
    MarsMan  mm;
    MoonMan  mom;
    PrintHumansize<EarthMan,MarsMan, MoonMan>(em,mm,mom);

    return 0;
}
