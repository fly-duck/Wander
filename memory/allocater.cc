#include <bits/stdc++.h>
#include "allocator_03.hpp"
//#include <test/test.h>
//#include <test/notype_template_test.hpp>

template<typename T> 
void mmlloc(size_t i, T** p){
    *p= (T*) malloc(i);
    *p=new float(2.9);
}

template<typename T> 
void Print(T t){
    std::cout<< t<< "\n";
}

template<typename T, typename U>
void DiffPointer(T t, U u){
   //these two are same  
   //only pointer to the same array may be subtracted 
   std::cout<<std::ptrdiff_t(t - u) << "\n";
   std::cout<<t - u << "\n";
   //std::cout<<std::ptrdiff_t(*t - *u) << "\n";
}


int main(int foo,  char** bbar)
{
   float* a =new float(1.0);
   mmlloc<float>(1,&a);    
   std::allocator<int> all;
   std::allocator<float> all_float;
   int*  k = (all.allocate(1));
   int*  k1 =(all.allocate(1));
   Print(*a);
   Print(k);
   Print(k1);
   int *  k2 = (all.allocate(1));
   float * k3 = all_float.allocate(1.0f);

   int * arr = new int[5];
   Print(arr);
   Print(arr+1);
   DiffPointer(arr+1,arr);
   // -8 means 32 bytes offset  
   DiffPointer(k,k1);
   Print(k2);
   Print(k3);

   char default_char[128] ={0};
   alignas(128) char  align_char[128] ={0};
   std::cout << "alignment of default char : "<< alignof(default_char) <<"\n"; 
   std::cout << "alignment of non-default char : "<< alignof(align_char) <<"\n"; 

   std::cout<<std::hex << std::showbase << align_char[0] <<"\n";
   //https://www.usenix.org/legacy/publications/library/proceedings/als00/2000papers/papers/full_papers/sears/sears_html/index.html
   //https://tylerayoung.com/2019/01/29/benchmarks-of-cache-friendly-data-structures-in-c/
   //http://web.cecs.pdx.edu/~jrb/cs201/lectures/cache.friendly.code.pdf
   printf("%p\n",&default_char[128]);
   printf("%p\n",align_char);
   printf("%p\n",&align_char[29]);
   //std::cout<<std::hex << std::showbase << align_char[0] <<"\n";
   //std::cout<<std::hex << std::showbase << default_char[0] <<"\n";
   //std::cout<<std::hex << std::showbase << default_char[1] <<"\n";
   //DiffPointer(k3,k2);
  // Wander::Test test;
  // test.run_test();


}
