/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/06/08 17:21:24 by gleal            ###   ########.fr       */
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

void test_vec_42()
{
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
}

void	test_vec_fts()
{
	// (constructor)
	// default (1)	
	// explicit vector (const allocator_type& alloc = allocator_type());

		ft::vector<std::string> vector1;
		ft::vector<int> vector2;
		ft::vector<char> vector3;
		ft::vector<char *> vector4;
		ft::vector<const int> vector5;

	// fill (2)	
	// explicit vector (size_type n, const value_type& val = value_type(),
	//                  const allocator_type& alloc = allocator_type());

		ft::vector<std::string> vector6(5, "Hello");
	
		ft::vector<int> vector7(10, 5);
		ft::vector<char> vector8(3, 'k');
		char a[] = "Okay";
		ft::vector<char *> vector9(4, a);
		ft::vector<const int> vector10(2, 4);

	// range (3)	
	// template <class InputIterator>
	//          vector (InputIterator first, InputIterator last,
	//                  const allocator_type& alloc = allocator_type());

		ft::vector<std::string> vector11(vector6.begin(), vector6.end());
		ft::vector<int> vector12(vector7.begin(), vector7.end());
		int myints[] = {16,2,77,29};
		ft::vector<int> vector13 (myints, myints + sizeof(myints) / sizeof(int) );
		ft::vector<char> vector14(vector8.begin(), vector8.end());
		ft::vector<char *> vector15(vector9.begin(), vector9.end());
		ft::vector<const int> vector16(vector10.begin(), vector10.end());

	// copy (4)	
	// vector (const vector& x);
		ft::vector<std::string> vector17(vector11);
		ft::vector<int> vector18(vector12);
		ft::vector<int> vector19 (vector13);
		ft::vector<char> vector20(vector14);
		ft::vector<char *> vector21(vector15);
		ft::vector<const int> vector22(vector16);

	// (destructor)
	// ~vector();

	// operator=
	// vector& operator= (const vector& x);

	// empty = non-empty

	// non-empty = empty
	

	// Iterators
	// iterator begin();
	
	// const_iterator begin() const;
	// Add error to check that std ft is being called


	// Capacity
	
}

void    test_vector()
{
	// test_vec_42();
	test_vec_fts();
	// main from 42

	ft::vector<int> vector_int;

	ft::vector<int> multi_nbr(10, 5);

	ft::vector<int>::iterator begin = multi_nbr.begin();

	std::cout << *begin << std::endl;

	
	test_vector_iterator();
}