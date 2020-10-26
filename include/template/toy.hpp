#include <iostream>
#include <type_traits>

namespace Wander{
    template<typename T>
    class Human{
    
        public:

            static constexpr bool copyable = false;
            T* a; 
            int b= 88; 

        friend std::ostream& operator<<(std::ostream& os, Human<T> human){
        return os<< human.b << "\n";
        }
    };


    template<typename T>
    class Robot{
        
        public:
            static constexpr bool copyable =true;
    };


    template<typename HumanType, typename ... AliensType>
    void PrintHumansize(HumanType ordinary_human, AliensType ...aliens)
    {
        std::cout<< sizeof(ordinary_human) <<"\n";
        std::cout<< sizeof...(aliens) <<"\n";
        std::cout<< sizeof...(AliensType)<<"\n"; 
    }


    template<typename Copyable>
    bool copyable = Robot<Copyable>::copyable;

    template<typename T1, typename ...Tn>
    constexpr bool IsSame(T1,Tn...)
    {
        return (std::is_same<T1,Tn>::value && ...);
    };


    template<typename... Types>
    void print (Types const&... args)
    {
      (std::cout << ... << args) << "\n";
    }
    template<std::size_t... Idx,typename Container >
    void PrintContainer( const Container& c)
    {
        print(c[Idx]...);
    }

    template <typename T> 
    void Perfect_ForWarding(T && val){
        std::cout<< *val <<"\n";
    }
    template<typename T>
    void Perfect_ForWarding(T & val) {
        std::cout<< "const & val" << val <<"\n";
    }


    template<typename T>
    struct PrintTraits;

    template<>
    struct PrintTraits<float>{
        using P_Traits= unsigned int;
    };



    // printtraits change float value behaviour to be unsigned int vlaue behaviour 
    // which equal to cast float to an unsigned int 
    template<typename T>
    auto Print_Traits(const T& val){
        using P_Traits= typename PrintTraits<T>::P_Traits;
        P_Traits total = val;
        std::cout << total << "\n";
        //return total;
    }
}
