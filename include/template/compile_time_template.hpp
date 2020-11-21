namespace Wander {
    
    template<unsigned a , unsigned b> 
    struct DoIsPrime {
        constexpr static bool value = ((a % b) != 0) && DoIsPrime<a,b-1>::value;
    };

    // partial specialization 
    template<unsigned a>
    struct DoIsPrime<a,2> {
        constexpr static bool value = ( (a%2) != 0);
    }; 


    template<unsigned a>
    struct IsPrime{
        constexpr static bool value = DoIsPrime<a,a/2>::value;
    };


    // specialization for IsPrime 
    template<>
    struct IsPrime<0>{
        constexpr static bool value =false;
    };
    
    template<>
    struct IsPrime<1>{
        constexpr static bool value =false;
    };

    template<>
    struct IsPrime<2>{
        constexpr static bool value =true;
    };

    template<>
    struct IsPrime<3>{
        constexpr static bool value =true;
    };
}
