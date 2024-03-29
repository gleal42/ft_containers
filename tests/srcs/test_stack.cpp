/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:46:22 by gleal             #+#    #+#             */
/*   Updated: 2022/05/29 19:48:03 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"

void test_stack_gen()
{
	ft::stack<int> stack_int;
	stack_int.push(2);
	const ft::stack<int> stack_int_cpy(stack_int);

	ft::vector<int>::reference ref_top = stack_int.top();
	ft::vector<int>::const_reference cref_top = stack_int_cpy.top();
	std::cout << "Original top " << ref_top << std::endl;
	std::cout << "Copy top " << cref_top << std::endl;

	std::cout << "Original == Copy? " << (stack_int == stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original != Copy? " << (stack_int != stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original < Copy? " << (stack_int < stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original <= Copy? " << (stack_int <= stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original > Copy? " << (stack_int > stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original >= Copy? " << (stack_int >= stack_int_cpy ? "true" : "false") << std::endl;

	stack_int.push(3);
	std::cout << "Is the stack empty? " << (stack_int.empty() ? "true" : "false") << std::endl;
	std::cout << "Stack Size: " << stack_int.size() << std::endl;
	stack_int.pop();
	stack_int.pop();
	std::cout << "Is the stack empty? " << (stack_int.empty() ? "true" : "false") << std::endl;
	std::cout << "Stack Size: " << stack_int.size() << std::endl;

	std::cout << "Original == Copy? " << (stack_int == stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original != Copy? " << (stack_int != stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original < Copy? " << (stack_int < stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original <= Copy? " << (stack_int <= stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original > Copy? " << (stack_int > stack_int_cpy ? "true" : "false") << std::endl;
	std::cout << "Original >= Copy? " << (stack_int >= stack_int_cpy ? "true" : "false") << std::endl;
}

// Testing the usage of the member types

void	test_stack_mem_types()
{
	ft::stack<int> stack_int;
	ft::stack<int>::container_type dq;
	stack_int.push(5);
	ft::stack<int>::container_type type = dq;
	ft::stack<int>::value_type value;
	value = stack_int.top();
	ft::stack<int>::size_type size;
	size = stack_int.size();
	ft::stack<int>::reference ref = stack_int.top();
	ft::stack<int>::const_reference cref = stack_int.top();
	ref = cref;
	std::cout << size << " " << value << std::endl;
}

void test_stack_class()
{
	ft::stack<Buffer, ft::vector<Buffer> > stack_deq_buffer;
}

// Not possible to use push using stack from standard library because map has no push_back

void test_stack_map()
{
	ft::map<std::string, int> map1;
	map1["something"] = 69;
	map1["anything"] = 199;
	map1["that thing"] = 50;
	ft::stack<ft::map<std::string, int>::value_type, ft::map<std::string, int> > stack_map_buffer(map1);
	// stack_map_buffer.push(4);
}

void test_stack_inherit()
{
	MutantStack<char> iterable_stack;
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;
}

void    test_stack()
{
	test_stack_gen();
	test_stack_mem_types();
	test_stack_class();
	test_stack_map();
	test_stack_inherit();
}