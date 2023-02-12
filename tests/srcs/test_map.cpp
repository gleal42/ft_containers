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
	
	ft::pair<int, int> a(2, 3);
	map1.insert(a);

	std::cout << map1.begin()->first << std::endl;
	std::cout << map1.begin()->second << std::endl;
}

void    test_map_constructors_rev_iterator()
{
	std::cout << "Default MAP Constructor" << std::endl;
	ft::map<std::string, int> map1;

	ft::pair<std::string, int> a("anything", 1);
	ft::pair<std::string, int> b("is possible", 2);
	map1.insert(a);
	map1.insert(b);
	map1.insert(a);

	std::greater<std::string> great;

	std::cout << "MAP Constructor with compare" << std::endl;
	ft::map<std::string, int, std::greater<std::string> > map2(great);
	map2.insert(a);
	map2.insert(b);
	map2.insert(a);
	ft::map<std::string, int>::iterator itcompare = map2.begin();
	std::cout << itcompare->first << std::endl;
	std::cout << itcompare->second << std::endl;
	std::cout << (itcompare++)->first << std::endl;
	std::cout << itcompare->second << std::endl;
	std::cout << itcompare->first << std::endl;
	std::cout << (--itcompare)->first << std::endl;
	std::cout << (itcompare)->second << std::endl;

	std::cout << "MAP range constructor" << std::endl;
	ft::map<std::string, int> iter(map2.begin(), map2.end());
	ft::map<std::string, int>::iterator it = iter.begin();
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	std::cout << (it++)->first << std::endl;
	std::cout << it->second << std::endl;
	std::cout << it->first << std::endl;
	std::cout << (--it)->first << std::endl;
	std::cout << (it)->second << std::endl;
	it++;

	std::cout << "MAP REVERSE ITER" << std::endl;
	ft::map<std::string, int>::reverse_iterator rev_it(it);
	std::cout << rev_it->first << std::endl;
	std::cout << rev_it->second << std::endl;
	rev_it--;
	std::cout << "-----" << std::endl;
	std::cout << rev_it->first << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << rev_it->second << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << rev_it->first << std::endl;

	ft::map<std::string, int>ite2(iter);
	std::cout << ite2.begin()->first << std::endl;
	std::cout << ite2.begin()->second << std::endl;
}

void    test_map_assignment()
{
	std::cout << "MAP Assignment" << std::endl;
	ft::map<int, int> ref_map;
	ft::pair<int, int> a(1, 10);
	ft::pair<int, int> b(2, 20);
	ft::pair<int, int> c(3, 30);
	ft::pair<int, int> d(4, 40);
	ref_map.insert(a);
	ref_map.insert(c);
	ref_map.insert(a);
	ref_map.insert(b);
	ref_map.insert(b);
	ref_map.insert(b);
	ref_map.insert(a);
	ref_map.insert(d);

	for (ft::map<int, int>::iterator it = ref_map.begin(); it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	
	ft::map<int, int> map2;
	ft::pair<int, int> e(5, 50);
	map2.insert(e);
	map2.insert(a);

	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	map2 = 	ref_map;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
}

void test_map_element_access()
{
}

// void    map_test_42()
// {
// 	// 42 test
// 	ft::map<int, int> map_int;
// 	for (int i = 0; i < COUNT; ++i)
// 	{
// 		map_int.insert(ft::make_pair(rand(), rand()));
// 	}

// 	int sum = 0;
// 	for (int i = 0; i < 10000; i++)
// 	{
// 		int access = rand();
// 		sum += map_int[access];
// 	}
// 	std::cout << "should be constant with the same seed: " << sum << std::endl;
// 	{
// 		ft::map<int, int> copy = map_int;
// 	}
// }

void    test_map()
{
	// test_map_iterator();
	// test_map_constructors_rev_iterator();
	// test_map_assignment();
	test_map_element_access();
	// test_map_element_access();
	// map_test_42();
}