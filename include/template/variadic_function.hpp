
// parameter pack ... must be deduced through template argument duduction
#pragma once

template<typename ...A>
void example(A... args){}

// basically B identifier of parameter pack
template<typename ...B> 
void wrapper(B... args){
    example(&args...);
   // &args is a pattern then expand like int& double& char&
   // example(const&args...);
    example(args... );
}

template<class ...Args>
    void g(Args... args) {
        f(const_cast<const Args*>(&args)...); 
 // const_cast<const Args*>(&args) is the pattern, it expands two packs
 // (Args and args) simultaneously
 
        f(h(args...) + args...); // Nested pack expansion:
   // inner pack expansion is "args...", it is expanded first
   // outer pack expansion is h(E1, E2, E3) + args..., it is expanded
   // second (as h(E1,E2,E3) + E1, h(E1,E2,E3) + E2, h(E1,E2,E3) + E3)
}

//Class c1(&args...);             // calls Class::Class(&E1, &E2, &E3)
//Class c2 = Class(n, ++args...); // calls Class::Class(n, ++E1, ++E2, ++E3);
//::new((void *)p) U(std::forward<Args>(args)...) // std::allocator::allocate
#include <iostream>
 
void tprintf(const char* format) // base function
{
    std::cout << format;
}
 
template<typename T, typename... Targs>
//Targs is the template parameter pack and Fargs is the function parameter pack
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
//    std::cout << value;
    for ( ; *format != '\0'; format++ ) {
        if ( *format == '%' ) {
           //std::cout << value;
           tprintf(format+1, Fargs...); // recursive call
           return;
        }
        std::cout << *format;
    }
}
 
