#pragma once 
#include <iostream>
namespace Wander{
    
    template<typename T>
    struct PrintTraits;

    template<>
    struct PrintTraits<double>{
        using P_Traits= float;
    };



    // printtraits change float value behaviour to be unsigned int vlaue behaviour 
    // which equal to cast float to an unsigned int 
    template<>
    struct PrintTraits<long>{
        using P_Traits = float;
        static P_Traits constexpr somevalue= 2.5f;
    };


    
    template<typename T>
    auto Print_Traits(const T& val){
        using P_Traits= typename PrintTraits<T>::P_Traits;
        P_Traits total = val;
        std::cout << total << "\n";
        //return total;
    }
}
