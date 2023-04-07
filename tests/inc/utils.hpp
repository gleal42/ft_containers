#ifndef __UTILS_H__
#define __UTILS_H__

#include <iostream>

template<typename T>
void	print_container( const T & container)
{
	std::cout << "print_container" << std::endl;
	for (typename T::const_iterator it = container.begin();
		it != container.end();
		it++)
	{
		std::cout << *it << std::endl;
	}	
}

template<typename T>
void	print_stats(const T & container)
{
	print_container(container);
	std::cout << "SIZE: [" << container.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << container.capacity() << "]" << std::endl;	
}

#endif // __UTILS_H__
