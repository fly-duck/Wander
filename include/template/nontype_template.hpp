#pragma once 

namespace Wander{
   
    class UserDefined{
    };


    // basic 
    template <typename T, int val>
    T add( T a){
        return a+val;
    }

    template<auto val, typename T = decltype(val)>
    T general_add( T a){
        return val+a;
    }

    template<decltype(auto) N>
    class C{
    };

    template<int* p>
    int* foo(){
        return p;  
    }

    template<typename T , T val= T{}> 
    T add3( T a ){
        return a+val;
    }

    //https://stackoverflow.com/questions/2183087/why-cant-i-use-float-value-as-a-template-parameter
    //template<typename T , float val>
    //T addfloat( T a ){
    //    return a + val;
    //}
}
