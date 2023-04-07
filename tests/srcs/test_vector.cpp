/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/11/26 16:30:35 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"
#include <algorithm>

void test_vec_42()
{
	ft::vector<Buffer> vector_buffer;
	std::cout << "SIZE: [" << vector_buffer.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_buffer.capacity() << "]" << std::endl;
	for (int i = 0; i < COUNT; i++)
	{
		vector_buffer.push_back(Buffer());
		std::cout << "SIZE: [" << vector_buffer.size() << "]" << std::endl;
		std::cout << "CAPACITY: [" << vector_buffer.capacity() << "]" << std::endl;
	}
	for (int i = 0; i < COUNT; i++)
	{
		const int idx = rand() % COUNT;
		vector_buffer[idx].idx = 5;
	}
	ft::vector<Buffer>().swap(vector_buffer);

	try
	{
		for (int i = 0; i < COUNT; i++)
		{
			const int idx = rand() % COUNT;
			vector_buffer.at(idx);
			std::cerr << "Error: THIS VECTOR SHOULD BE EMPTY!!" <<std::endl;
		}
	}
	catch(const std::exception& e)
	{
		//NORMAL ! :P
	}
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
	print_stats(vector_str);
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

	ft::vector<std::string> vector_str_base(1, "Hello");
	vector_str_base.push_back("my");
	vector_str_base.push_back("name");
	vector_str_base.push_back("is");
	vector_str_base.push_back("Gonçalo");
	print_stats(vector_str_base);
	ft::vector<std::string> vector_str_range(vector_str_base.begin(), vector_str_base.end());
	print_stats(vector_str_range);

	ft::vector<int> vector_int_base(10, 5);
	print_stats(vector_int_base);
	ft::vector<int> vector_int_range(vector_int_base.begin(), vector_int_base.end());
	print_stats(vector_int_range);

	ft::vector<char> vector_char_base(3, 'k');
	print_stats(vector_char_base);
	ft::vector<char> vector_char_range(vector_char_base.begin(), vector_char_base.end());
	print_stats(vector_char_range);

	char a[] = "Okay";
	ft::vector<char *> vector_charptr_base(4, a);
	print_stats(vector_charptr_base);
	ft::vector<char *> vector_charptr_range(vector_charptr_base.begin(), vector_charptr_base.end());
	print_stats(vector_charptr_range);

	int myints[] = {16, 2, 77, 29};
	ft::vector<int> vector_int_direct(myints, myints + sizeof(myints) / sizeof(int));
	print_stats(vector_int_direct);

	// ft::vector<const int> vector16(vector10.begin(), vector10.end());	

	// ft::vector<const int> vector10(2, 4); // const elements not allowed
}

/**
 * @brief copy (4)
 * vector (const vector& x);
 * 
 * TODO: Add test with increased capacity and create copy
 * (what happens is the capacity is not taken into consideration)
 * TODO: Test assign with more capacity than size and then assign and check new size.
 */

void vector_copy_constructor( void )
{
	// Replace these with different push_back, insert created, etc
	ft::vector<std::string> vec_str(5, "Hello");
	vec_str.reserve(10);

	print_stats(vec_str);
	ft::vector<std::string> vector_cpy_str(vec_str);
	print_stats(vector_cpy_str);

	ft::vector<int> vec_int(10, 5);
	print_stats(vec_int);
	ft::vector<int> vector_cpy_int(vec_int);
	print_stats(vector_cpy_int);

	ft::vector<char> vec_char(3, 'k');
	print_stats(vec_char);
	ft::vector<char> vec_cpy_char(vec_char);
	print_stats(vec_cpy_char);

	char a[] = "Okay";
	ft::vector<char *> vec_char_ptr(4, a);
	print_stats(vec_char_ptr);
	ft::vector<char *> vec_cpy_char_ptr(vec_char_ptr);
	print_stats(vec_cpy_char_ptr);
	// ft::vector<const int> vector10(2, 4);	
	// ft::vector<const int> vector22(vector10);
}

void	vector_assignment_operator()
{
	std::cout << "TESTING VECTOR ASSIGNMENT OPERATOR SMALL TO BIG" << std::endl;
	
	ft::vector<int> vector_big1(1, 1);
	vector_big1.push_back(2);
	vector_big1.push_back(3);
	vector_big1.push_back(4);
	vector_big1.push_back(5);
	vector_big1.push_back(6);
	vector_big1.push_back(7);
	vector_big1.reserve(20);

	std::cout << "BIG VECTOR" << std::endl;
	print_container(vector_big1);
	ft::vector<int> vector_small1(2, 10);
	vector_small1.push_back(11);
	vector_small1.push_back(12);

	std::cout << "SMALL VECTOR BEFORE ASSIGNING BIG VECTOR" << std::endl;
	print_container(vector_small1);
	std::cout << "SIZE: [" << vector_small1.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_small1.capacity() << "]" << std::endl;

	vector_small1 = vector_big1;

	std::cout << "AFTER ASSIGNING" << std::endl;
	print_container(vector_small1);
	std::cout << "SIZE: [" << vector_small1.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_small1.capacity() << "]" << std::endl;

	std::cout << "TESTING VECTOR ASSIGNMENT OPERATOR BIG to SMALL" << std::endl;

	ft::vector<int> vector_small2(2, 10);
	vector_small2.push_back(11);
	vector_small2.push_back(12);

	ft::vector<int> vector_big2(1, 1);
	vector_big2.push_back(2);
	vector_big2.push_back(3);
	vector_big2.push_back(4);
	vector_big2.push_back(5);
	vector_big2.push_back(6);
	vector_big2.push_back(7);
	vector_big2.reserve(20);

	std::cout << "SMALL VECTOR" << std::endl;
	print_container(vector_small2);

	std::cout << "BIG VECTOR BEFORE ASSIGNING BIG VECTOR" << std::endl;
	print_container(vector_big2);
	std::cout << "SIZE: [" << vector_big2.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_big2.capacity() << "]" << std::endl;

	vector_big2 = vector_small2;

	std::cout << "AFTER ASSIGNING" << std::endl;
	print_container(vector_big2);
	std::cout << "SIZE: [" << vector_big2.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_big2.capacity() << "]" << std::endl;
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
	print_stats(vector_str);

	vector_str.reserve(vector_str.size() + 3);
	std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;

	vector_str.assign(3, "YO");
	std::cout << "VECTOR SIMPLE ASSIGN with size smaller than capacity" << std::endl;
	print_stats(vector_str);
	// print_container(vector_str);
	// print_container_capacity(vector_str);
	// std::cout << "SIZE: [" << vector_str.size() << "]" << std::endl;
	// std::cout << "CAPACITY: [" << vector_str.capacity() << "]" << std::endl;

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

// // TODO: Make more tests for each

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

	std::cout << "Inserting range [" << *(vector_int.begin() + 1) << " to "  <<*(vector_int.end()-2) << "]" <<std::endl;
	range_insert_vec.insert(range_insert_vec.begin() + 2, vector_int.begin() + 1, vector_int.end()-1);

	std::cout << "VECTOR after range insert" << std::endl;
	print_stats(range_insert_vec);

	ft::vector<int> quick_test(vector_int);
	quick_test.reserve(quick_test.size() + 1);
	quick_test.insert(quick_test.begin(), 100);
	print_stats(quick_test);

	ft::vector<int> big_vector;
	big_vector.push_back(1);
	big_vector.push_back(2);
	big_vector.push_back(3);
	big_vector.push_back(4);
	big_vector.push_back(5);
	big_vector.push_back(6);
	big_vector.push_back(7);
	big_vector.push_back(8);
	big_vector.push_back(10);
	print_stats(big_vector);

	std::cout << "VECTOR with insert range more than double empty" << std::endl;
	ft::vector<int> small_vector_empty;
	small_vector_empty.insert(small_vector_empty.begin(), big_vector.begin(), big_vector.end());
	print_stats(small_vector_empty);

	std::cout << "VECTOR with insert range more than double not empty" << std::endl;
	ft::vector<int> small_vector_not_empty(1, 0);
	small_vector_not_empty.insert(small_vector_not_empty.begin(), big_vector.begin(), big_vector.end());
	print_stats(small_vector_not_empty);

	std::cout << "VECTOR with single insert versus push_back" << std::endl;
	ft::vector<int> pb_vector;
	std::cout << "push_back 1" << std::endl;
	pb_vector.push_back(1);
	print_stats(pb_vector);
	std::cout << "push_back 2" << std::endl;
	pb_vector.push_back(2);
	print_stats(pb_vector);
	std::cout << "push_back 3" << std::endl;
	pb_vector.push_back(3);
	print_stats(pb_vector);

	ft::vector<int> single_ins_vector;
	std::cout << "insert 1 2 3 1st time" << std::endl;
	single_ins_vector.insert(single_ins_vector.end(), 1);
	print_stats(single_ins_vector);
	std::cout << "insert 1 2 3 2ND TIME" << std::endl;
	single_ins_vector.insert(single_ins_vector.end(), 2);
	print_stats(single_ins_vector);
	std::cout << "insert 1 2 3" << std::endl;
	single_ins_vector.insert(single_ins_vector.end(), 3);
	print_stats(single_ins_vector);

	std::cout << "VECTOR with range insert versus push_back" << std::endl;
	ft::vector<int> pb_vector2;
	std::cout << "push_back 1" << std::endl;
	pb_vector2.push_back(1);
	print_stats(pb_vector2);
	std::cout << "push_back 2" << std::endl;
	pb_vector2.push_back(2);
	print_stats(pb_vector2);
	std::cout << "push_back 3" << std::endl;
	pb_vector2.push_back(3);
	print_stats(pb_vector2);

	ft::vector<int> ins_vector;
	std::cout << "insert 1 2 3 1st time" << std::endl;
	ins_vector.insert(ins_vector.end(), pb_vector.begin(), (pb_vector.begin()+3));
	print_stats(ins_vector);
	std::cout << "insert 1 2 3 2ND TIME" << std::endl;
	ins_vector.insert(ins_vector.end(), pb_vector.begin(), (pb_vector.begin()+3));
	print_stats(ins_vector);
	std::cout << "insert 1 2 3" << std::endl;
	ins_vector.insert(ins_vector.end(), pb_vector.begin(), (pb_vector.begin()+3));
	print_stats(ins_vector);

	std::cout << "VECTOR huge range insert" << std::endl;

	std::cout << "VECTOR empty insert" << std::endl;
	ft::vector<int> no_change_vec(1, 2);
	print_stats(no_change_vec);
	no_change_vec.insert(no_change_vec.end(), no_change_vec.begin(), no_change_vec.begin());
	print_stats(no_change_vec);
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

void vector_external_swap()
{
	ft::vector<int> vec_1(1, 1);
	vec_1.push_back(2);
	vec_1.push_back(3);

	ft::vector<int> vec_2(1, 4);
	vec_2.push_back(5);
	vec_2.push_back(6);

	std::cout << "VECTOR 1 before swap" << std::endl;
	print_stats(vec_1);
	std::cout << "VECTOR 2 before swap" << std::endl;
	print_stats(vec_2);

	ft::swap(vec_1, vec_2);

	std::cout << "VECTOR 1 after swap" << std::endl;
	print_stats(vec_1);
	std::cout << "VECTOR 2 after swap" << std::endl;
	print_stats(vec_2);
}

void vector_comparisons()
{
	std::cout << "Comparing VECTORS" << std::endl;

	ft::vector<int> vec_1(1, 1);
	vec_1.push_back(2);
	vec_1.push_back(3);

	ft::vector<int> vec_2(1, 1);
	vec_2.push_back(2);
	vec_2.push_back(3);
	
	std::cout << std::boolalpha;
	std::cout << "-------VEC 1-------" << std::endl;
	print_container(vec_1);
	std::cout << "-------VEC 2-------" << std::endl;
	print_container(vec_2);
	std::cout << "VECTOR 1 == VECTOR 2 returns " << (vec_1 == vec_2) << std::endl;	
	std::cout << "VECTOR 1 != VECTOR 2 returns " << (vec_1 != vec_2) << std::endl;	
	std::cout << "VECTOR 1 <  VECTOR 2 returns " << (vec_1 < vec_2) << '\n';
    std::cout << "VECTOR 1 <= VECTOR 2 returns " << (vec_1 <= vec_2) << '\n';
    std::cout << "VECTOR 1 >  VECTOR 2 returns " << (vec_1 > vec_2) << '\n';
    std::cout << "VECTOR 1 >= VECTOR 2 returns " << (vec_1 >= vec_2) << '\n';

	vec_2.pop_back();
	std::cout << "-------VEC 1-------" << std::endl;
	print_container(vec_1);
	std::cout << "-------VEC 2-------" << std::endl;
	print_container(vec_2);
	std::cout << "VECTOR 1 == VECTOR 2 returns " << (vec_1 == vec_2) << std::endl;	
	std::cout << "VECTOR 1 != VECTOR 2 returns " << (vec_1 != vec_2) << std::endl;	
	std::cout << "VECTOR 1 <  VECTOR 2 returns " << (vec_1 < vec_2) << '\n';
    std::cout << "VECTOR 1 <= VECTOR 2 returns " << (vec_1 <= vec_2) << '\n';
    std::cout << "VECTOR 1 >  VECTOR 2 returns " << (vec_1 > vec_2) << '\n';
    std::cout << "VECTOR 1 >= VECTOR 2 returns " << (vec_1 >= vec_2) << '\n';
	
	vec_2.push_back(2);
	std::cout << "-------VEC 1-------" << std::endl;
	print_container(vec_1);
	std::cout << "-------VEC 2-------" << std::endl;
	print_container(vec_2);
	std::cout << "VECTOR 1 == VECTOR 2 returns " << (vec_1 == vec_2) << std::endl;	
	std::cout << "VECTOR 1 != VECTOR 2 returns " << (vec_1 != vec_2) << std::endl;	
	std::cout << "VECTOR 1 <  VECTOR 2 returns " << (vec_1 < vec_2) << '\n';
    std::cout << "VECTOR 1 <= VECTOR 2 returns " << (vec_1 <= vec_2) << '\n';
    std::cout << "VECTOR 1 >  VECTOR 2 returns " << (vec_1 > vec_2) << '\n';
    std::cout << "VECTOR 1 >= VECTOR 2 returns " << (vec_1 >= vec_2) << '\n';

	vec_1.pop_back();
	std::cout << "-------VEC 1-------" << std::endl;
	print_container(vec_1);
	std::cout << "-------VEC 2-------" << std::endl;
	print_container(vec_2);
	std::cout << "VECTOR 1 == VECTOR 2 returns " << (vec_1 == vec_2) << std::endl;	
	std::cout << "VECTOR 1 != VECTOR 2 returns " << (vec_1 != vec_2) << std::endl;	
	std::cout << "VECTOR 1 <  VECTOR 2 returns " << (vec_1 < vec_2) << '\n';
    std::cout << "VECTOR 1 <= VECTOR 2 returns " << (vec_1 <= vec_2) << '\n';
    std::cout << "VECTOR 1 >  VECTOR 2 returns " << (vec_1 > vec_2) << '\n';
    std::cout << "VECTOR 1 >= VECTOR 2 returns " << (vec_1 >= vec_2) << '\n';
}

void	vector_reverse_iterator()
{
	ft::vector<int> vec_1(1, 1);
	vec_1.push_back(2);
	vec_1.push_back(3);
	vec_1.push_back(4);
	vec_1.push_back(5);
    std::cout << "RBEGIN TO REND" << std::endl;
	for (ft::vector<int>::reverse_iterator rev_it = vec_1.rbegin();
		rev_it != vec_1.rend();
		rev_it++)
	{
		std::cout << *rev_it << std::endl;
	}
    std::cout << "REND - 1 TO RBEGIN - 1" << std::endl;
	for (ft::vector<int>::reverse_iterator rev_it = vec_1.rend() - 1;
		rev_it != vec_1.rbegin() - 1;
		rev_it--)
	{
		std::cout << *rev_it << std::endl;
	}
}

/**
 * TODO: Test Destructor somehow. Maybe call manually?
 */

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
	vector_external_swap();
	vector_comparisons();
	vector_reverse_iterator();
}

int test_vector()
{
	std::cout << "\nRunning custom tests\n" << std::endl;
	vector_custom_tests();
	// main from 42
	test_vec_42();
	return (0);
}