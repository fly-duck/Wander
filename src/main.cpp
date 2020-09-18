#include <point.h>
#include <iostream>
#include <random>
#include <status.h>

int main()
{
    Wander::Point<int, 3> p;
    std::cout<<p.GetPoint<1>()<<"\n";

    p.SetPoint<1>(2);
    std::cout<<p.GetPoint<1>()<<"\n";
    

    Wander::Status<int> i;

    return 0;
}
