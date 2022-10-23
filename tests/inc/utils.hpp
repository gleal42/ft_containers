#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>

template<typename T>
void	print_container( const T & container)
{
	for (typename T::const_iterator it = container.begin();
		it != (container.begin() + container.capacity());
		it++)
	{
		// it != container.end();
		std::cout << *it << std::endl;
	}	
}

#endif // __UTILS_H__
