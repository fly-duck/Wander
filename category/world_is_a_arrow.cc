
#include <iostream> 
#include <random> 
#include <map>
#include <cmath>
#include <iomanip> 
template<typename Fun1, typename Fun2>
bool Identity(Fun1 f1,  Fun2 f2){
    return f1*f2;
}

auto lambda1=[](bool b1){return !b1;};
auto lambda2=[](bool b2){return !b2;};


int main() 
{
    std::random_device rd;
        std::mt19937 gen{rd()};
 
    // values near the mean are the most likely
    // standard deviation affects the dispersion of generated values from the mean
    std::normal_distribution<> d{5,2};
 
    std::map<int, int> hist{};
    for(int n=0; n<10000; ++n) {
        ++hist[std::round(d(gen))];
    }
    for(auto p : hist) {
        std::cout << std::setw(2)
                  << p.first << ' ' << std::string(p.second/200, '*') << '\n';
    }
    std::cout<< Identity(lambda1(false),lambda2(false))<<"\n"; 
}
