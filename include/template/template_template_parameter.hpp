#include <deque>


namespace Wander{
    
    template<typename T,
        template<class Elem> class Cont = std::deque>
    class TTemplate{
        Cont<T> elems;
    };
   
    template<typename T , template<typename Elem> typename Cond = std::deque>
    class T17Template{};

    // But does matter when you have to use the second typename e.g. type2 container
    template<typename T , template<typename> typename cond = std::deque>
    class TypeName_Argument_Dont_Matter{};

    //before cpp17 
    template<typename T , template<typename Elem, typename Alloc = std::allocator<Elem>> typename Cont = std::deque>
        class Before17Template{};


    // Disable template parameter 
    

    // if T > 4  == void foo() 
    template<typename T>
    typename std::enable_if< (sizeof(T) > 4) >::type foo() { return T();}
    
    template<typename T, typename = std::enable_if_t< (sizeof(T)>5) >>
    void foo2() {}

    template<typename T, typename std::enable_if_t< (sizeof(T) > 4) >>
    void foo3() {}
    
    template<typename T, std::enable_if_t< (sizeof(T) > 4) >>
    void foo4() {}
    

    // SpecialType is alias template 
    template<typename T>
    using SpecialType = typename std::enable_if_t< (sizeof(T) > 4) > ;

    template<typename T , SpecialType<T>> 
    void foo5 () {}
   

}
