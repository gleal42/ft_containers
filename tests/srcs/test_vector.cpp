/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/10/30 18:05:53 by gleal            ###   ########.fr       */
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

/**
 * @brief range (3)
 * template <class InputIterator>
 * vector (InputIterator first, InputIterator last,
 *         const allocator_type& alloc = allocator_type());
 * 
 * TODO: Check what happens with capacity:
 * Create vector with 5 size and 10 capacity and use this from begin() to
 * end() + 2 for example
 */
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

/**
 * @brief copy (4)
 * vector (const vector& x);
 * 
 * TODO: Add test with increased capacity and create copy
 * (what happens is the capacity is not taken into consideration)
 */

void vector_copy_constructor( void )
{
	// Replace these with different push_back, insert created, etc
	ft::vector<std::string> vec_str(5, "Hello");
	vec_str.reserve(10);

	std::cout << "print_container" << std::endl;	
	print_container(vec_str);
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vec_str);
	std::cout << "SIZE: [" << vec_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vec_str.capacity() << "]" << std::endl;
	ft::vector<std::string> vector_cpy_str(vec_str);
	std::cout << "SIZE: [" << vector_cpy_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_cpy_str.capacity() << "]" << std::endl;

	ft::vector<int> vec_int(10, 5);
	std::cout << "print_container" << std::endl;
	print_container(vec_int);
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vec_int);
	std::cout << "SIZE: [" << vec_int.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vec_int.capacity() << "]" << std::endl;

	ft::vector<int> vector18(vec_int);

	ft::vector<char> vec_char(3, 'k');

	std::cout << "print_container" << std::endl;
	print_container(vec_char);
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vec_char);
	std::cout << "SIZE: [" << vec_char.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vec_char.capacity() << "]" << std::endl;

	ft::vector<char> vector20(vec_char);

	char a[] = "Okay";
	ft::vector<char *> vec_char_ptr(4, a);

	std::cout << "print_container" << std::endl;
	print_container(vec_char_ptr);
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vec_char_ptr);
	std::cout << "SIZE: [" << vec_char_ptr.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vec_char_ptr.capacity() << "]" << std::endl;

	ft::vector<char *> vector21(vec_char_ptr);

	// ft::vector<const int> vector10(2, 4);	
	// ft::vector<const int> vector22(vector10);
}

void	vector_assignment_operator()
{
	std::cout << "TESTING VECTOR ASSIGNMENT OPERATOR" << std::endl;
	
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
	std::cout << "print_container" << std::endl;
	print_container(vector_str);
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vector_str);
	vector_str.reserve(vector_str.size() + 3);
	std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;

	vector_str.assign(3, "YO");
	std::cout << "VECTOR SIMPLE ASSIGN with size smaller than capacity" << std::endl;
	std::cout << "print_container" << std::endl;
	print_container(vector_str);
	std::cout << "print_container_capacity" << std::endl;
	print_container_capacity(vector_str);
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

// TODO: Make more tests for each

void	vector_insert()
{
	std::cout << "TESTING VECTOR INSERT" << std::endl;

	ft::vector<int> vector_int(1, 1);
	vector_int.push_back(2);
	vector_int.push_back(3);
	vector_int.push_back(4);
	vector_int.push_back(5);
	vector_int.push_back(6);
	
	size_t vec_size = vector_int.size() + 6; 

	ft::vector<int> val_insert_vec(vector_int);
 
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "VECTOR before value (single) insert" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	print_stats(val_insert_vec);

	val_insert_vec.insert((val_insert_vec.begin() + 3), 200);

	std::cout << "VECTOR after value (single) insert" << std::endl;
	print_stats(val_insert_vec);

	ft::vector<int> multi_val_insert_vec(vector_int);
	multi_val_insert_vec.reserve(vec_size);

	std::cout << "-----------------------------------" << std::endl;
	std::cout << "VECTOR before multiple value insert" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	print_stats(multi_val_insert_vec);

	multi_val_insert_vec.insert(multi_val_insert_vec.begin() + 3, 3, 200);

	std::cout << "VECTOR after multiple value insert" << std::endl;
	print_stats(multi_val_insert_vec);

	ft::vector<int> range_insert_vec(vector_int);
	std::cout << "--------------------------" << std::endl;
	std::cout << "VECTOR before range insert" << std::endl;
	std::cout << "--------------------------" << std::endl;


	print_stats(range_insert_vec);

	range_insert_vec.insert(range_insert_vec.begin() + 2, vector_int.begin() + 1, vector_int.end()-1);

	std::cout << "VECTOR after range insert" << std::endl;
	print_stats(range_insert_vec);

	ft::vector<int> quick_test(vector_int);
	quick_test.reserve(quick_test.size() + 1);
	quick_test.insert(quick_test.begin(), 100);
	print_stats(quick_test);
}

void	vector_clear()
{
	std::cout << "TESTING VECTOR CLEAR" << std::endl;

	ft::vector<int> vector_int(1, 1);
	vector_int.push_back(2);
	vector_int.push_back(3);
	
	ft::vector<int> clear_vec(vector_int);
 
	std::cout << "-------------------" << std::endl;
	std::cout << "VECTOR before clear" << std::endl;
	std::cout << "-------------------" << std::endl;
	print_container(clear_vec);

	clear_vec.clear();

	std::cout << "VECTOR after clear" << std::endl;
	print_stats(clear_vec);
	
	std::cout << "VECTOR after clear and push_back (depends on end()" << std::endl;
	clear_vec.push_back(12);
	print_stats(clear_vec);
}

void	vector_erase()
{
	std::cout << "TESTING VECTOR ERASE" << std::endl;

	ft::vector<int> vector_int(1, 1);
	vector_int.push_back(2);
	vector_int.push_back(3);
	vector_int.push_back(4);
	vector_int.push_back(5);
	vector_int.push_back(6);
	vector_int.push_back(7);
	
	ft::vector<int> erase_vec(vector_int);
 
	std::cout << "-------------------" << std::endl;
	std::cout << "VECTOR before erase" << std::endl;
	std::cout << "-------------------" << std::endl;

	print_stats(erase_vec);

	std::cout << "VECTOR after erase begin + 2" << std::endl;

	ft::vector<int>::iterator return_val = erase_vec.erase(erase_vec.begin() + 2);
	print_stats(erase_vec);
	std::cout << "RETURN VALUE: [" << *return_val << "]" << std::endl;

	std::cout << "VECTOR after range erase begin + 2 twice (no effect)" << std::endl;

	return_val = erase_vec.erase(erase_vec.begin() + 2, erase_vec.begin() + 2);
	print_stats(erase_vec);
	std::cout << "RETURN VALUE: [" << *return_val << "]" << std::endl;

	std::cout << "VECTOR after range erase begin + 2  && + 3 (erase 1)" << std::endl;

	return_val = erase_vec.erase(erase_vec.begin() + 2, erase_vec.begin() + 3);
	print_stats(erase_vec);
	std::cout << "RETURN VALUE: [" << *return_val << "]" << std::endl;

	std::cout << "VECTOR after range erase val to end" << std::endl;

	return_val = erase_vec.erase(erase_vec.begin() + 5, erase_vec.end());
	print_stats(erase_vec);
	std::cout << "RETURN VALUE: [" << *return_val << "]" << std::endl;
}

void	vector_pop_back()
{
	std::cout << "TESTING VECTOR POP_BACK" << std::endl;

	ft::vector<std::string> pop_vec(1, "A");
	pop_vec.push_back("B");
	pop_vec.push_back("C");
	pop_vec.push_back("D");
	std::cout << "-------------------" << std::endl;
	std::cout << "VECTOR before pop_back" << std::endl;
	std::cout << "-------------------" << std::endl;
	print_stats(pop_vec);
	std::cout << "VECTOR after op_backs" << std::endl;
	pop_vec.pop_back();
	print_stats(pop_vec);
	pop_vec.pop_back();
	print_stats(pop_vec);
	pop_vec.pop_back();
	print_stats(pop_vec);
	pop_vec.pop_back();
	print_stats(pop_vec);
}

void	vector_resize()
{
	std::cout << "TESTING VECTOR RESIZE" << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "VECTOR before RESIZE" << std::endl;
	std::cout << "--------------------" << std::endl;
	ft::vector<int> resize_vec(1, 1);
	print_stats(resize_vec);

	std::cout << "VECTOR after resize with no value" << std::endl;
	resize_vec.resize(2);
	print_stats(resize_vec);

	std::cout << "VECTOR after 2nd resize with value 3" << std::endl;
	resize_vec.resize(4, 3);
	print_stats(resize_vec);

	std::cout << "VECTOR after 3nd resize down" << std::endl;
	resize_vec.resize(2, 3);
	print_stats(resize_vec);

}

void	vector_swap()
{
	std::cout << "TESTING VECTOR SWAP" << std::endl;

	std::cout << "--------------------" << std::endl;
	std::cout << "VECTOR 1 before SWAP" << std::endl;
	std::cout << "--------------------" << std::endl;
	ft::vector<int> vec_1(1, 1);
	vec_1.push_back(2);
	vec_1.push_back(3);
	print_stats(vec_1);

	std::cout << "--------------------" << std::endl;
	std::cout << "VECTOR 2 before SWAP" << std::endl;
	std::cout << "--------------------" << std::endl;
	ft::vector<int> vec_2(1, 111);
	vec_2.push_back(77);
	print_stats(vec_2);

	vec_1.swap(vec_2);

	std::cout << "VECTOR 1 after swap" << std::endl;
	print_stats(vec_1);
	std::cout << "VECTOR 2 after swap" << std::endl;
	print_stats(vec_2);
}

void vector_custom_tests()
{
	vector_default_constructor();
	vector_fill_constructor();
	vector_range_constructor();
	vector_copy_constructor();

	vector_assignment_operator();

	vector_assign();
	vector_insert();
	vector_clear();
	vector_erase();
	vector_pop_back();
	vector_resize();
	vector_swap();

	
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