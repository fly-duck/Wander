#include <point.h>
#include <iostream>
#include <random>
#include <status.h>
//#include <new_features.h> 
#include <template/toy.hpp>

int main()
{
    Wander::Point<int, 3> p;
    std::cout<<p.GetPoint<1>()<<"\n";

    p.SetPoint<1>(2);
    std::cout<<p.GetPoint<1>()<<"\n";
   

    std::cout<< Wander::copyable<Wander::Robot<int>>  <<"\n";
    Wander::Status<int> i;

    return 0;
}
