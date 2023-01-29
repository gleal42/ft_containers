/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:46:55 by gleal             #+#    #+#             */
/*   Updated: 2022/05/17 16:14:21 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"

void    test_map_iterator()
{
	ft::map<int, int> map1;
	
	ft::pair<const int, int> a(2, 3);
	map1.insert(a);

	std::cout << map1.begin()->first << std::endl;
}

void    test_map()
{

	test_map_iterator();
	// 42 test
	// ft::map<int, int> map_int;
	// for (int i = 0; i < COUNT; ++i)
	// {
	// 	map_int.insert(ft::make_pair(rand(), rand()));
	// }

	// int sum = 0;
	// for (int i = 0; i < 10000; i++)
	// {
	// 	int access = rand();
	// 	sum += map_int[access];
	// }
	// std::cout << "should be constant with the same seed: " << sum << std::endl;
	// {
	// 	ft::map<int, int> copy = map_int;
	// }
}