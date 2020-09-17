#include "point.h"
#include <iostream>

int main()
{
    Wander::Point<int, 3> p;
    std::cout<<p.GetPoint<3>()<<"\n";
    return 0;
}
