/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:46:22 by gleal             #+#    #+#             */
/*   Updated: 2022/05/18 13:14:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"

// Apagarrr
#include <map>

void test_stack_gen()
{
	ft::stack<int> stack_int;
	stack_int.push(2);
	ft::stack<int> stack_int_cpy(stack_int);
	stack_int_cpy.top();
}

void test_stack_class()
{
	ft::stack<Buffer, std::deque<Buffer> > stack_deq_buffer;	
}

void test_stack_map()
{
	std::map<std::string, int> map1;
	map1["something"] = 69;
	map1["anything"] = 199;
	map1["that thing"] = 50;
	ft::stack<std::map<std::string, int>::value_type, std::map<std::string, int> > stack_map_buffer(map1);
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
	test_stack_class();
	test_stack_map();
	test_stack_inherit();
}