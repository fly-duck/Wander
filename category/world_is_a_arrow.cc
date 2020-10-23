
#include <iostream> 

template<typename Fun1, typename Fun2>
bool Identity(Fun1 f1,  Fun2 f2){
    return f1*f2;
}

auto lambda1=[](bool b1){return !b1;};
auto lambda2=[](bool b2){return !b2;};


int main() 
{
    std::cout<< Identity(lambda1(false),lambda2(false))<<"\n"; 
}
