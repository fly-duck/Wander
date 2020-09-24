#include <iostream>


namespace Wander{
    template<typename T>
    class Human{
    
        public:

            static constexpr bool copyable = false;
            T* a; 
    
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
}
