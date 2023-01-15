
#include "all.hpp"
#include "rebind.hpp"

void    test_rebind()
{
    rebind<std::allocator<char> >::to<int>::other rebinded_int_allocator;

    int *big_number = rebinded_int_allocator.allocate(1);

    rebinded_int_allocator.construct(big_number, 2000000);
    std::cout << "Expecting no leaks on this conversion " << *big_number << "\n";

    rebinded_int_allocator.deallocate(big_number, 1);
}