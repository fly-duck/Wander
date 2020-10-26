#include <bits/stdc++.h>

template<typename T> 
void mmlloc(size_t i, T** p){
    *p= (T*) malloc(i);
    *p=new float(2.9);
}

template<typename T> 
void Print(T t){
    std::cout<< t<< "\n";
}

int main(int foo,  char** bbar)
{
   float* a =new float(1.0);
   mmlloc<float>(1,&a);    
   Print(*a);
}
