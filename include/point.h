

#include <algorithm> 


namespace Wander{

template<typename DataType , std::size_t Dimension>
class Point
{

public: 

    Point()
    {
    
        std::fill_n(point_ , Dimension , 0);        

    }

    template<std::size_t D>   
    const DataType& GetPoint() const 
    {
        return point_[D];
    }
   
    template<std::size_t D>
    const DataType& SetPoint(const DataType& data) 
    {
       point_[D]= data;
    }

private:
    
   DataType point_[Dimension];



};


}
