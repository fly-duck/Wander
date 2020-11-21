#include <iostream>
#include <string>
#include <utility>

namespace Wander{
 
void Forward( int& value){
    std::cout<< "forward reference type" << "\n";
}

void Forward( const int & value) {
    std::cout << "forward const reference type " << "\n"; 
}

void Forward( int && value ) {
    std::cout << "forward moveable type " << "\n";
}



//template< typename T> 
//void Wrapper( T value){
//    Forward( value);    
//}


template< typename T> 
void Wrapper( T&& value) {
    Forward(std::forward<T>(value));
    // T x  x is reference when we pass lvalue to this func
}



class Person{

    public: 
        template<typename T>
        Person( T && name): name_(std::forward<T>(name)){
        } 
        

        Person(const Person& p): name_(p.name_){}
        
    
        Person(Person && p ): name_(std::move(p.name_)){}
    private:
        std::string name_;
};
}
// Person p;
//avoid using nonconst construtor like Person(p ), but use move contructorPerson(std::move(p)); 

//std::string returnString()
//std::string s = "hi";
//printV(s);
// copy constructor
//printV(std::string("hi")); // copying usually optimized away (if not, move constructor)
//printV(returnString());
// copying usually optimized away (if not, move constructor)
//printV(std::move(s));
// move constructor
