/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:50 by gleal             #+#    #+#             */
/*   Updated: 2022/11/26 17:21:51 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "RedBlackTree.hpp"
#include "iterator_traits.hpp"
#include "pair.hpp"
#include "reverse_iterator.hpp"
#include <memory>

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
	  class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{

      public:
	typedef Key key_type;
	typedef T mapped_type;
	typedef ft::pair<const Key, T> value_type;
	typedef Compare key_compare;
	typedef Allocator allocator_type;
	typedef typename allocator_type::reference reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer pointer;
	typedef typename allocator_type::const_pointer const_pointer;
	typedef typename RedBlackTree<value_type>::iterator iterator;
	typedef typename RedBlackTree<value_type>::const_iterator
		    const_iterator;
	typedef Reverse_Iterator<iterator> reverse_iterator;
	typedef Reverse_Iterator<const_iterator> const_reverse_iterator;
	typedef typename std::size_t size_type;
	typedef typename std::ptrdiff_t difference_type;

	map() : tree(), _map_alloc() {}

	explicit map(const Compare &comp, const Allocator &alloc = Allocator())
	    : tree(comp), _map_alloc(alloc)
	{
	}

	template <class InputIt>
	map(InputIt first, InputIt last, const Compare &comp = Compare(),
	    const Allocator &alloc = Allocator())
	    : tree(comp), _map_alloc(alloc)
	{
		for (InputIt copy_it = first; copy_it != last; copy_it++)
		{
			tree.add_node(*copy_it);
		}
	}
	map(const map &x) : tree(x.tree._cmp), _map_alloc(x._map_alloc)
	{
		for (const_iterator copy_it = x.begin(); copy_it != x.end();
		     copy_it++)
		{
			tree.add_node(*copy_it);
		}
	}
	// Dealloc and destroy done automatically in RBT destructor
	~map() {}

	map &operator=(const map &other)
	{
		tree.destroy_all();
		tree.init();
		for (const_iterator copy_it = other.begin();
		     copy_it != other.end(); copy_it++)
		{
			tree.add_node(*copy_it);
		}
		return *this;
	}

	allocator_type get_allocator() const { return (_map_alloc); }

	// Element access
	T &at(const Key &key)
	{
		Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
			throw std::out_of_range("");
		return found_node->data.second;
	}
	const T &at(const Key &key) const
	{
		const Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
			throw std::out_of_range("");
		return found_node->data.second;
	}
	T &operator[](const Key &key)
	{
		Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
		{
			value_type temp = ft::pair<const Key, T>(key, T());
			tree.add_node(temp);
			return (tree.find_node(key)->data.second);
		}
		return found_node->data.second;
	}
    // Iterators 
	iterator begin() { return tree.begin(); }
	const_iterator begin() const { return tree.begin(); }
	iterator end() { return tree.end(); }
	const_iterator end() const { return tree.end(); }
	reverse_iterator rbegin() { return reverse_iterator(tree.end()); }
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(tree.end());
	}
	reverse_iterator rend() { return reverse_iterator(tree.begin()); }
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(tree.begin());
	}
    // Capacity 
    bool empty() const
    {
        return tree.empty();
    }
    size_type size() const
    {
        return(tree.size());
    }
    size_type max_size() const
    {
        return (tree.max_size());
    }
	void insert(const value_type &value) { tree.add_node(value); }

      private:
	RedBlackTree<value_type, key_compare, Allocator> tree;
	Allocator _map_alloc;
}; // class map

} // namespace ft

#endif
