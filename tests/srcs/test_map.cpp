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

void test_map_iterators()
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

void test_map_constructors_rev_iterator()
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

	ft::map<std::string, int> ite2(iter);
	std::cout << ite2.begin()->first << std::endl;
	std::cout << ite2.begin()->second << std::endl;
}

void test_map_assignment()
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
	for (ft::map<int, int>::iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	ft::map<int, int> map2;
	ft::pair<int, int> e(5, 50);
	map2.insert(e);
	map2.insert(a);

	std::cout << "Second MAP" << std::endl;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end();
	     it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	std::cout << "Third MAP" << std::endl;
	map2 = ref_map;
	for (ft::map<int, int>::iterator it = map2.begin(); it != map2.end();
	     it++)
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
	} catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		const int res_4 = ref_map.at("Sixth");
		std::cout << res_4 << std::endl;
	} catch (const std::out_of_range &e)
	{
		std::cerr << e.what() << '\n';
	}
	const int res_5 = ref_map["Sixth"];
	std::cout << res_5 << std::endl;
	ref_map["Sixth"] = 6;
	int res_6 = ref_map["Sixth"];
	std::cout << res_6 << std::endl;
}

void test_map_capacity()
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

void test_modifiers()
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
	for (ft::map<char, int>::const_iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ref_map.clear();
	for (ft::map<char, int>::const_iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ref_map.insert(d);
	ref_map.insert(a);
	for (ft::map<char, int>::iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "\n---iterator insert( iterator pos, const value_type& "
		     "value );---"
		  << std::endl;

	ft::map<char, int> hint_map;
	{
		ft::map<char, int>::iterator hint1 = hint_map.begin();
		ft::map<char, int>::iterator it = hint_map.insert(hint1, a);
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	{
		ft::map<char, int>::iterator hint1 = hint_map.begin();
		ft::map<char, int>::iterator it = hint_map.insert(hint1, a);
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	{
		ft::map<char, int>::iterator hint2 = hint_map.begin();
		ft::map<char, int>::iterator it = hint_map.insert(hint2, b);
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	{
		ft::map<char, int>::iterator hint3 = hint_map.find(b.first);
		ft::map<char, int>::iterator it = hint_map.insert(hint3, b);
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ref_map.insert(d);
	ref_map.insert(a);
	ref_map.insert(e);
	ref_map.insert(c);
	ref_map.insert(b);
	std::cout << "\n---void insert( InputIt first, InputIt last );---"
		  << std::endl;
	ft::map<char, int> range_insert_map;
	range_insert_map.insert(ref_map.begin(), ref_map.end());
	for (ft::map<char, int>::const_iterator it = range_insert_map.begin();
	     it != range_insert_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	std::cout << "\n---void erase (iterator position);---" << std::endl;
	ft::map<char, int> erase_map(ref_map);
	ft::map<char, int>::iterator erase_it = erase_map.find('c');
	erase_map.erase(erase_it);
	for (ft::map<char, int>::const_iterator it = erase_map.begin();
	     it != erase_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	std::cout << "\n---size_type erase (const key_type& k);---"
		  << std::endl;
	ft::map<char, int>::size_type ret = erase_map.erase('a');
	std::cout << "deleting a was a success so we got " << ret << std::endl;
	for (ft::map<char, int>::const_iterator it = erase_map.begin();
	     it != erase_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	ret = erase_map.erase('a');
	std::cout << "if we try again it won't work so ret is " << ret
		  << std::endl;
	for (ft::map<char, int>::const_iterator it = erase_map.begin();
	     it != erase_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "\n---void erase (iterator first, iterator last);---"
		  << std::endl;
	erase_it = erase_map.end();
	erase_it--;
	erase_map.erase(erase_map.begin(), erase_it);
	for (ft::map<char, int>::const_iterator it = erase_map.begin();
	     it != erase_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "\n---	void swap (map& x);---" << std::endl;
	ft::map<char, int> swap_map(ref_map);
	ft::pair<char, int> f('f', 6);
	swap_map.erase('a');
	ref_map.insert(f);

	std::cout << "\n---	swap_map before ---" << std::endl;
	for (ft::map<char, int>::const_iterator it = swap_map.begin();
	     it != swap_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "\n---	ref_map before ---" << std::endl;
	for (ft::map<char, int>::const_iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	swap_map.swap(ref_map);

	std::cout << "\n---	swap_map after ---" << std::endl;
	for (ft::map<char, int>::const_iterator it = swap_map.begin();
	     it != swap_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
	std::cout << "\n---	ref_map after ---" << std::endl;
	for (ft::map<char, int>::const_iterator it = ref_map.begin();
	     it != ref_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}
}

void test_lookup()
{
	std::cout << "\n|---Testing Lookup---|\n" << std::endl;
	ft::pair<std::string, int> a("Hello", 10);
	ft::pair<std::string, int> b("my", 1);
	ft::pair<std::string, int> c("name", 2);
	ft::pair<std::string, int> d("name", 10000);
	ft::pair<std::string, int> e("is", 1123);
	ft::pair<std::string, int> f("Goncalo", 112421);

	ft::map<std::string, int> look_up_map;
	look_up_map.insert(a);
	look_up_map.insert(b);
	look_up_map.insert(c);
	look_up_map.insert(d);
	look_up_map.insert(e);
	look_up_map.insert(f);
	for (ft::map<std::string, int>::const_iterator it = look_up_map.begin();
	     it != look_up_map.end(); it++)
	{
		std::cout << "it->first " << it->first << std::endl;
		std::cout << "it->second " << it->second << std::endl;
	}

	std::cout << "\n---	size_type count( const Key& key ) const; ---"
		  << std::endl;
	std::cout << "If I find occurrence I will get "
		  << look_up_map.count("Hello") << std::endl;
	std::cout << "If I do not find occurrence I will get "
		  << look_up_map.count("Helos") << std::endl;

	std::cout << "\n---	iterator find( const Key& key ); ---"
		  << std::endl;
	ft::map<std::string, int>::iterator iter = look_up_map.begin();
	std::cout << "begin() is " << iter->first << std::endl;
	ft::map<std::string, int>::const_iterator citer = look_up_map.begin();
	std::cout << "const begin() string size is " << citer->first.size()
		  << std::endl;
}

void test_bounds()
{
	std::cout << "\n|---Testing bounds---|\n" << std::endl;

	ft::pair<int, int> a(1, 10);
	ft::pair<int, int> b(4, 40);
	ft::pair<int, int> c(7, 70);
	ft::pair<int, int> d(30, 300);
	ft::pair<int, int> e(20, 200);
	ft::pair<int, int> f(17, 170);

	ft::map<int, int> bound_map;
	bound_map.insert(a);
	bound_map.insert(b);
	bound_map.insert(c);
	bound_map.insert(d);
	bound_map.insert(e);
	bound_map.insert(f);

	std::cout << "\n---	iterator lower_bound( const Key& key ); ---" << std::endl;
	ft::map<int, int>::iterator lower1 = bound_map.lower_bound(-1);
	std::cout << "lower_bound 1 is " << lower1->first << std::endl;

	ft::map<int, int>::iterator lower2 = bound_map.lower_bound(17);
	std::cout << "lower_bound 2 is " << lower2->first << std::endl;

	ft::map<int, int>::iterator lower3 = bound_map.lower_bound(30);
	std::cout << "lower_bound 3 is " << lower3->first << std::endl;

	ft::map<int, int>::iterator lower4 = bound_map.lower_bound(320);
	std::cout << "lower_bound 4 same as end? " << (lower4 == bound_map.end()) << std::endl;

	std::cout << "\n---	const_iterator lower_bound( const Key& key ) const; ---" << std::endl;
	ft::map<int, int>::const_iterator clower1 = bound_map.lower_bound(-1);
	std::cout << "const_lower_bound 1 is " << clower1->first << std::endl;

	ft::map<int, int>::const_iterator clower2 = bound_map.lower_bound(17);
	std::cout << "const_lower_bound 2 is " << clower2->first << std::endl;

	ft::map<int, int>::const_iterator clower3 = bound_map.lower_bound(30);
	std::cout << "const_lower_bound 3 is " << clower3->first << std::endl;

	ft::map<int, int>::const_iterator clower4 = bound_map.lower_bound(320);
	std::cout << "lower_bound 4 same as end? " << (clower4 == bound_map.end()) << std::endl;

	std::cout << "\n---	iterator upper_bound( const Key& key ); ---" << std::endl;
	ft::map<int, int>::iterator upper1 = bound_map.upper_bound(-1);
	std::cout << "upper_bound 1 is " << upper1->first << std::endl;

	ft::map<int, int>::iterator upper2 = bound_map.upper_bound(17);
	std::cout << "upper_bound 2 is " << upper2->first << std::endl;

	ft::map<int, int>::iterator upper3 = bound_map.upper_bound(30);
	std::cout << "upper_bound 3 same as end? " << (upper3 == bound_map.end()) << std::endl;

	ft::map<int, int>::iterator upper4 = bound_map.upper_bound(320);
	std::cout << "upper_bound 4 same as end? " << (upper4 == bound_map.end()) << std::endl;

	std::cout << "\n---	const_iterator upper_bound( const Key& key ) const; ---" << std::endl;
	ft::map<int, int>::const_iterator cupper1 = bound_map.upper_bound(-1);
	std::cout << "const_upper_bound 1 is " << cupper1->first << std::endl;

	ft::map<int, int>::const_iterator cupper2 = bound_map.upper_bound(17);
	std::cout << "const_upper_bound 2 is " << cupper2->first << std::endl;

	ft::map<int, int>::const_iterator cupper3 = bound_map.upper_bound(30);
	std::cout << "const_upper_bound 3 same as end? " << (cupper3 == bound_map.end()) << std::endl;

	ft::map<int, int>::const_iterator cupper4 = bound_map.upper_bound(320);
	std::cout << "const_upper_bound 4 same as end? " << (cupper4 == bound_map.end()) << std::endl;


	std::cout << "\n---	ft::pair<iterator,iterator> equal_range( const Key& key ); ---" << std::endl;
	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> equal_range1 = bound_map.equal_range(-1);
	std::cout << "equal_range.lower_bound1 is " << equal_range1.first->first << std::endl;
	std::cout << "equal_range.upper_bound1 is " << equal_range1.second->first << std::endl;

	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> equal_range2 = bound_map.equal_range(17);
	std::cout << "equal_range.lower_bound2 is " << equal_range2.first->first << std::endl;
	std::cout << "equal_range.upper_bound2 is " << equal_range2.second->first << std::endl;

	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> equal_range3 = bound_map.equal_range(30);
	std::cout << "equal_range.lower_bound3 is " << equal_range3.first->first << std::endl;
	std::cout << "equal_range.upper_bound3 same as end? " << (equal_range3.first == bound_map.end()) << std::endl;

	ft::pair<ft::map<int, int>::iterator, ft::map<int, int>::iterator> equal_range4 = bound_map.equal_range(320);
	std::cout << "equal_range.lower_bound4 same as end? " << (equal_range4.first == bound_map.end()) << std::endl;
	std::cout << "equal_range.upper_bound4 same as end? " << (equal_range4.second == bound_map.end()) << std::endl;

	std::cout << "\n---	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const; ---" << std::endl;
	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> const_equal_range1 = bound_map.equal_range(-1);
	std::cout << "const_equal_range.lower_bound1 is " << const_equal_range1.first->first << std::endl;
	std::cout << "const_equal_range.upper_bound1 is " << const_equal_range1.second->first << std::endl;

	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> const_equal_range2 = bound_map.equal_range(17);
	std::cout << "const_equal_range.lower_bound2 is " << const_equal_range2.first->first << std::endl;
	std::cout << "const_equal_range.upper_bound2 is " << const_equal_range2.second->first << std::endl;

	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> const_equal_range3 = bound_map.equal_range(30);
	std::cout << "const_equal_range.lower_bound3 is " << const_equal_range3.first->first << std::endl;
	std::cout << "const_equal_range.upper_bound3 same as end? " << (const_equal_range3.first == bound_map.end()) << std::endl;

	ft::pair<ft::map<int, int>::const_iterator, ft::map<int, int>::const_iterator> const_equal_range4 = bound_map.equal_range(320);
	std::cout << "const_equal_range.lower_bound4 same as end? " << (const_equal_range4.first == bound_map.end()) << std::endl;
	std::cout << "const_equal_range.upper_bound4 same as end? " << (const_equal_range4.second == bound_map.end()) << std::endl;	
}

void test_observers()
{
	std::cout << "\n|---Testing Observers---|\n" << std::endl;
	std::cout << "\n---	key_compare key_comp() const; ---" << std::endl;
	ft::map<int, char, Compare> observ_map;
	ft::pair<int, char> a(1, 'a');
	ft::pair<int, char> b(2, 'b');
	ft::pair<int, char> c(3, 'c');
	ft::pair<int, char> d(4, 'd');
	ft::pair<int, char> e(5, 'e');
	observ_map.insert(a);
	observ_map.insert(b);
	observ_map.insert(c);
	observ_map.insert(d);
	observ_map.insert(e);
	ft::map<int, char, Compare>::key_compare comp_func = observ_map.key_comp();
    for (ft::map<int, char, Compare>::iterator it = observ_map.begin(); it != observ_map.end(); it++) {
        bool before = comp_func(it->first, 100);
        bool after = comp_func(100, it->first);
        std::cout << '(' << it->first << ',' << it->second;
        if (!before && !after)
            std::cout << ") equivalent to key 100\n";
        else if (before)
            std::cout << ") goes before key 100\n";
        else if (after)
            std::cout << ") goes after key 100\n";
    }

	std::cout << "\n---	std::map::value_compare value_comp() const; ---" << std::endl;
}

void test_comparators()
{
	ft::map<int, char> comp_map;
	ft::pair<int, char> a(1, 'a');
	ft::pair<int, char> b(2, 'b');
	ft::pair<int, char> c(3, 'c');
	ft::pair<int, char> d(4, 'd');
	ft::pair<int, char> e(5, 'e');
	comp_map.insert(a);
	comp_map.insert(b);
	comp_map.insert(c);
	comp_map.insert(d);
	comp_map.insert(e);

	ft::map<int, char> other_map(comp_map);
	
	other_map.erase(--other_map.end());

	std::cout << "Maps equal?" << (comp_map==other_map)  << std::endl;
	std::cout << "Maps different?" << (comp_map!=other_map)  << std::endl;
	std::cout << "Maps less?" << (comp_map<other_map)  << std::endl;
	std::cout << "Maps less equal?" << (comp_map<=other_map)  << std::endl;
	std::cout << "Maps greater?" << (comp_map>other_map)  << std::endl;
	std::cout << "Maps greater equal?" << (comp_map>=other_map)  << std::endl;
}

void map_test_42()
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
	std::cout << "should be constant with the same seed: " << sum
		  << std::endl;
	{
		ft::map<int, int> copy = map_int;
	}
}

void test_map()
{
	test_map_iterators();
	test_map_constructors_rev_iterator();
	test_map_assignment();
	test_map_element_access();
	test_map_capacity();
	test_modifiers();
	test_lookup();
	test_bounds();
	test_observers();
	test_comparators();
	map_test_42();
}
