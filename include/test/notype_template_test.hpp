#pragma once
#include <template/nontype_template.hpp>
#include <template/perfect_forwarding.hpp>
#include <template/template_template_parameter.hpp>
#include <iostream>
#include <template/variadic_function.hpp>

namespace Wander {
    class Test{
        public:
        Test(){};
    
        void run_test(){
     

            //int i;
            //C<(i)> c;
            tprintf("% world% %\n","Hello",'!',123);
            wrapper(1,2.0,'a');
            AutoTemplate<'a'> template_a;
            OptionalName<int> kkk;
            int *p = new int(2);
            //std::cout<< foo<p>()<< "\n";
            std::cout<< general_add<30, int>(20)<<"\n";
            std::cout<< add3<int,22>(20) <<"\n";
            std::cout << general_add<20>(float(20.f))<<"\n";
            //std::cout<< general_add<float(30.f),float>(float(20.f))<<"\n"; 
            // std::cout << general_add<"sdfsd">(20);
           int a =2 ; 
              Wrapper<int>(int(2));
           // Wrapper<int>(std::move(int(2)));
           Wrapper<int>(std::move(a));
           std::cout << a << "\n";
        } 

        ~Test() {};
     };
}
