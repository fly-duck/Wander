
#include <cstddef>
template<class T>
struct allocator3
{
   typedef size_t size_type;
   typedef ptrdiff_t difference_type;
   typedef T* Pointer;
   typedef T const*  const_pointer; 
   //using const_pointer = const T*;
   template<class U> struct rebind{typedef allocator3<U> other;};


   Pointer allocate(size_type n, const void* pointer=0 ); 

};
