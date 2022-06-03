/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/06/03 01:05:16 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"

// difference_type operator-(const Random_Access_Iterator &it) const;
// friend difference_type operator-(const Random_Access_Iterator &a, const Random_Access_Iterator &b);
// Can be dereferenced as an lvalue vs rvalue not clear implementation
// Multi-Pass not clear implementation

void	test_vector_iterator()
{
	// ft::vector<int>::iterator a;
	// ft::vector<int>::iterator b;
	
	// std::cout << b - a << std::endl;

	// std::cout << *(5 + a) << std::endl;

	// X b(a);
	// b = a;
	// ++a
	// a++
	// a == b
	// a != b
	// *a
	// a->m
	// *a = t
	// *a++ = t
	// 	X a;
	// X()
	// { b=a; *a++; *b; }
	// --a
	// a--
	// *a--
	// a + 5
	// 5 + a
	// a - 5
	// 5 - a
	// a < b
	// a > b
	// a <= b
	// a >= b
	// a += n
	// a -= n
	// a[n]
}
	// Where X is an iterator type, a and b are objects of this iterator type, t is an object of the type pointed by the iterator type, and n is an integer value.

void    test_vector()
{
	ft::vector<std::string> vector_str;
	ft::vector<int> vector_int;

	ft::vector<int> multi_nbr(10, 5);

	ft::vector<int>::iterator begin = multi_nbr.begin();

	std::cout << *begin << std::endl;

	// ft::vector<Buffer> vector_buffer;
    
	// for (int i = 0; i < COUNT; i++)
	// {
	// 	vector_buffer.push_back(Buffer());
	// }
	// for (int i = 0; i < COUNT; i++)
	// {
	// 	const int idx = rand() % COUNT;
	// 	vector_buffer[idx].idx = 5;
	// }
	// ft::vector<Buffer>().swap(vector_buffer);

	// try
	// {
	// 	for (int i = 0; i < COUNT; i++)
	// 	{
	// 		const int idx = rand() % COUNT;
	// 		vector_buffer.at(idx);
	// 		std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
	// 	}
	// }
	// catch(const std::exception& e)
	// {
	// 	//NORMAL ! :P
	// }
	
	test_vector_iterator();
}