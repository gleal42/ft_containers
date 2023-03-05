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

void    test_map_iterators()
{
	std::cout << "Map iterators" << std::endl;
	ft::map<int, int> map1;
	
	ft::pair<int, int> a(1, 2);
	ft::pair<int, int> b(2, 3);
	ft::pair<int, int> c(3, 5);
	ft::pair<int, int> d(6, 8);
	map1.insert(a);
	map1.insert(b);
	map1.insert(c);
	map1.insert(d);
	ft::map<int, int>::iterator beg = map1.begin();
	std::cout << beg->first << std::endl;
	std::cout << beg->second << std::endl;

	ft::map<int, int>::const_iterator last = --map1.end();
	std::cout << last->first << std::endl;
	std::cout << last->second << std::endl;

	ft::map<int, int>::reverse_iterator rbeg = map1.rbegin();
	std::cout << rbeg->first << std::endl;
	std::cout << rbeg->second << std::endl;

	ft::map<int, int>::reverse_iterator rlast = --map1.rend();
	std::cout << rlast->first << std::endl;
	std::cout << rlast->second << std::endl;

	ft::map<int, int>::const_reverse_iterator crbeg = map1.rbegin();
	std::cout << crbeg->first << std::endl;
	std::cout << crbeg->second << std::endl;

	ft::map<int, int>::const_reverse_iterator crlast = --map1.rend();
	std::cout << crlast->first << std::endl;
	std::cout << crlast->second << std::endl;
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

	std::cout << "FIRST MAP" << std::endl;
	for (ft::map<int, int>::iterator it = ref_map.begin(); it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	
	ft::map<int, int> map2;
	ft::pair<int, int> e(5, 50);
	map2.insert(e);
	map2.insert(a);

	std::cout << "Second MAP" << std::endl;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	std::cout << "Third MAP" << std::endl;
	map2 = 	ref_map;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
}

void test_map_element_access()
{
	std::cout << "MAP Assignment" << std::endl;
	ft::map<std::string, int> ref_map;
	ft::pair<std::string, int> a("First", 1);
	ft::pair<std::string, int> b("Second", 2);
	ft::pair<std::string, int> c("Third", 3);
	ft::pair<std::string, int> d("Fourth", 4);
	ft::pair<std::string, int> e("Fifth", 5);

	ref_map.insert(c);
	ref_map.insert(b);
	ref_map.insert(a);
	ref_map.insert(d);
	ref_map.insert(e);

	int res_1 = ref_map.at("Second");
	std::cout << res_1 << std::endl;
	ref_map.at("Second") = 22;
	const int res_2 = ref_map.at("Second");
	std::cout << res_2 << std::endl;
	try
	{
		int res_3 = ref_map.at("Sixth");
		std::cout << res_3 << std::endl;
	}
	catch(const std::out_of_range & e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		const int res_4 = ref_map.at("Sixth");
		std::cout << res_4 << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
	const int res_5 = ref_map["Sixth"];
	std::cout << res_5 << std::endl;
	ref_map["Sixth"] = 6;
	int res_6 = ref_map["Sixth"];
	std::cout << res_6 << std::endl;
}

void    test_map_capacity()
{
	std::cout << "MAP capacity" << std::endl;
	ft::map<int, int> map_int;
	bool is_empty = map_int.empty();
	std::cout << "The map is empty? " << is_empty << std::endl;
	map_int[2] = 3;
	is_empty = map_int.empty();
	std::cout << "What about now? " << is_empty << std::endl;

	std::cout << "MAP size" << std::endl;
	map_int[1] = 2;
	map_int[3] = 4;
	map_int[5] = 10;
	map_int[4] = 20;
	std::cout << map_int.size() << std::endl;
	std::cout << map_int.max_size() << std::endl;
}

void    test_modifiers()
{
	std::cout << "---Testing Modifiers---" << std::endl;
	std::cout << "---void clear();---" << std::endl;
	ft::map<char, int> ref_map;
	ft::pair<char, int> a('a', 1);
	ft::pair<char, int> b('b', 2);
	ft::pair<char, int> c('c', 3);
	ft::pair<char, int> d('d', 4);
	ft::pair<char, int> e('e', 5);

	ref_map.insert(d);
	ref_map.insert(a);
	ref_map.insert(e);
	ref_map.insert(c);
	ref_map.insert(b);
	for (ft::map<char, int>::const_iterator it = ref_map.begin(); it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ref_map.clear();
	for (ft::map<char, int>::const_iterator it = ref_map.begin(); it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ref_map.insert(d);
	ref_map.insert(a);
	for (ft::map<char, int>::iterator it = ref_map.begin(); it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "---iterator insert( iterator pos, const value_type& value );---" << std::endl;

}

void    map_test_42()
{
	// 42 test
	ft::map<int, int> map_int;
	for (int i = 0; i < COUNT; ++i)
	{
		map_int.insert(ft::make_pair(rand(), rand()));
	}

	int sum = 0;
	for (int i = 0; i < 10000; i++)
	{
		int access = rand();
		sum += map_int[access];
	}
	std::cout << "should be constant with the same seed: " << sum << std::endl;
	{
		ft::map<int, int> copy = map_int;
	}
}

void    test_map()
{
	test_map_iterators();
	test_map_constructors_rev_iterator();
	test_map_assignment();
	test_map_element_access();
	test_map_capacity();
	test_modifiers();
	map_test_42();
}
