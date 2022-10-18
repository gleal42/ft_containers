/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/10/18 15:44:06 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"
#include <algorithm>

/**
 * TODO: Make tests to check if assign and assignment operator adjust capacity
 * if new contents are smaller or this resizing is only done in case the size
 * is not enough
 */

// difference_type operator-(const Random_Access_Iterator &it) const;
// friend difference_type operator-(const Random_Access_Iterator &a, const Random_Access_Iterator &b);
// Can be dereferenced as an lvalue vs rvalue not clear implementation
// Multi-Pass not clear implementation

void test_vector_iterator()
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

/**
 * @brief default (constructor) (1)
 * explicit vector (const allocator_type& alloc = allocator_type());
 */

void vector_default_constructor(void)
{
	std::cout << "\n[TESTING DEFAULT CONSTRUCTOR FOR DIFFERENT TYPES]" << std::endl;
	std::cout << "_______________________________________\n" << std::endl;
	ft::vector<std::string> vector_str;
	std::cout << "Data of vector string is [" << typeid(vector_str.data()).name() << "]" << std::endl;
	std::cout << "and corresponding value type is [" << typeid(ft::vector<std::string>::value_type).name() << "]" << std::endl;

	std::cout << "_______________________________________\n" << std::endl;
	ft::vector<int> vector2;
	std::cout << "Data of vector int is [" << typeid(vector2.data()).name() << "]" << std::endl;
	std::cout << "and corresponding value type is [" << typeid(ft::vector<int>::value_type).name() << "]" << std::endl;

	std::cout << "_______________________________________\n" << std::endl;
	ft::vector<char> vector3;
	std::cout << "Data of vector char is [" << typeid(vector3.data()).name() << "]" << std::endl;
	std::cout << "and corresponding value type is [" << typeid(ft::vector<char>::value_type).name() << "]" << std::endl;

	std::cout << "_______________________________________\n" << std::endl;
	ft::vector<char *> vector4;
	std::cout << "Data of vector char pointer is [" << typeid(vector4.data()).name() << "]" << std::endl;
	std::cout << "and corresponding value type is [" << typeid(ft::vector<char *>::value_type).name() << "]" << std::endl;

	std::cout << "_______________________________________\n" << std::endl;
	// ft::vector<const int> vector5;
	// std::cout << "Data of vector char pointer is [" << typeid(vector5.data()).name() << "]" << std::endl;
	// std::cout << "and corresponding value type is [" << typeid(ft::vector<const int>::value_type).name() << "]" << std::endl;
}

// fill (2)
// explicit vector (size_type n, const value_type& val = value_type(),
//                  const allocator_type& alloc = allocator_type());

void vector_fill_constructor( void )
{
	std::cout << "\n[TESTING FILL CONSTRUCTOR FOR DIFFERENT TYPES]" << std::endl;
	std::cout << "_______________________________________\n" << std::endl;

	ft::vector<std::string> vector_str(5, "Example String");
	std::cout << "vector<std::string>.at[3] [" << vector_str.at(3) << "]" << std::endl;
	try
	{
		std::cout << "try vector<std::string>.at[5]: " << vector_str.at(5) << std::endl;
	}
	catch (std::out_of_range & exc)
	{
		std::cout << "WHOOPS [" << exc.what() << "]"  << std::endl;
		std::cout << exc.what() << std::endl;
	}
	std::cout << "vector<std::string> vector_str[3] [" << vector_str[3] << "]" << std::endl;
	std::cout << "vector<std::string>.front() [" << vector_str.front() << "]" << std::endl;
	std::cout << "vector<std::string>.back() [" << vector_str.back() << "]" << std::endl;
	std::cout << "vector<std::string>.data() [" << *vector_str.data() << "]" << std::endl;


}

// range (3)
// template <class InputIterator>
//          vector (InputIterator first, InputIterator last,
//                  const allocator_type& alloc = allocator_type());

void vector_range_constructor( void )
{
	// Replace these with different push_back, insert created, etc
	std::cout << "[VECTOR RANGE CONSTRUCTOR]" << std::endl;

	ft::vector<std::string> vector_str(1, "Hello");
	vector_str.push_back("my");
	vector_str.push_back("name");
	vector_str.push_back("is");
	vector_str.push_back("Gonçalo");
	print_container(vector_str);

	ft::vector<int> vector7(10, 5);
	ft::vector<char> vector8(3, 'k');
	char a[] = "Okay";
ft::vector<char *> vector9(4, a);
	// ft::vector<const int> vector10(2, 4); // const elements not allowed

	ft::vector<std::string> vector_str_range(vector_str.begin(), vector_str.end());

	ft::vector<int> vector12(vector7.begin(), vector7.end());
	int myints[] = {16, 2, 77, 29};
	ft::vector<int> vector13(myints, myints + sizeof(myints) / sizeof(int));
	ft::vector<char> vector14(vector8.begin(), vector8.end());
	ft::vector<char *> vector15(vector9.begin(), vector9.end());
	// ft::vector<const int> vector16(vector10.begin(), vector10.end());	

	// TODO: Test assign with more capacity than size and then assign and check new size.

}

// copy (4)
// vector (const vector& x);
void vector_copy_constructor( void )
{
	// Replace these with different push_back, insert created, etc
	ft::vector<std::string> vector6(5, "Hello");
	ft::vector<int> vector7(10, 5);
	ft::vector<char> vector8(3, 'k');
	char a[] = "Okay";
	ft::vector<char *> vector9(4, a);
	// ft::vector<const int> vector10(2, 4);	

	ft::vector<std::string> vector17(vector6);
	ft::vector<int> vector18(vector7);
	ft::vector<char> vector20(vector8);
	ft::vector<char *> vector21(vector9);
	// ft::vector<const int> vector22(vector10);
}

void vector_assign()
{
	std::cout << "TESTING VECTOR ASSIGN" << std::endl;

	ft::vector<std::string> vector_str(1, "Hello");
	vector_str.push_back("my");
	vector_str.push_back("name");
	vector_str.push_back("is");
	vector_str.push_back("Gonçalo");
	
	ft::vector<std::string> temp(vector_str);
	
	std::cout << "VECTOR BEFORE ASSIGN" << std::endl;
	print_container(vector_str);
	vector_str.reserve(vector_str.size() + 3);
	std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;

	vector_str.assign(3, "YO");
	std::cout << "VECTOR SIMPLE ASSIGN with size smaller than capacity" << std::endl;
	print_container(vector_str);
	std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;

	std::cout << "VECTOR RANGE ASSIGN" << std::endl;
	temp.push_back("these");
	temp.push_back("are");
	temp.push_back("some");
	temp.push_back("extra");
	temp.push_back("super");
	temp.push_back("crazily");
	temp.push_back("amazinglt");
	temp.push_back("small");
	temp.push_back("words");
	temp.push_back("to");
	temp.push_back("use");
	temp.push_back("big");
	temp.push_back("range");
	
	ft::vector<std::string>::iterator first = std::find(temp.begin(), temp.end(), "are");
	ft::vector<std::string>::iterator last = std::find(temp.begin(), temp.end(), "big");
	std::cout << "The range will be from [" << *first << "] which is in " << (first - temp.begin()) << " position"<< std::endl;
	std::cout << "to [" << *last << "] which is in " << (last - temp.begin()) << " position." << std::endl;
	vector_str.assign(first, last);
	std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;
}

void vector_custom_tests()
{
	vector_default_constructor();
	vector_fill_constructor();
	vector_range_constructor();
	vector_copy_constructor();

	// operator=
	// vector& operator= (const vector& x);

	vector_assign();

	// (destructor)
	// ~vector();


	// empty = non-empty

	// non-empty = empty

	// Iterators
	// iterator begin();

	// const_iterator begin() const;
	// Add error to check that std ft is being called

	// Capacity
}

int test_vector()
{
	// test_vec_42();
	std::cout << "\nRunning custom tests\n" << std::endl;
	vector_custom_tests();
	// main from 42
	// test_vector_iterator();
	return (0);
}