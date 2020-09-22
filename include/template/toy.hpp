
namespace Wander{
    template<typename T>
    class Human{
    
        public:

            static constexpr bool copyable = false;
    
    
    };


    template<typename T>
    class Robot{
        
        public:
            static constexpr bool copyable =true;
    };


    template<typename Copyable>
    bool copyable = Robot<Copyable>::copyable;
}
