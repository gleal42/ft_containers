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
		tree.destroy_nodes();
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

	// Modifiers
	void clear()
	{
		tree.destroy_nodes();
	}

	void insert(const value_type &value) { tree.add_node(value); }
	iterator insert( iterator pos, const value_type& value )
	{
		return (tree.add_node(pos, value));
	}
	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
		while (first != last)
		{
			tree.add_node(*first);
			first++;
		}
	}
	void erase (iterator position)
	{
		tree.delete_node(position);
	}
	size_type erase (const key_type& k)
	{
		Node<value_type> *found_node = tree.find_node(k);
		if (found_node == NULL || found_node == tree._end)
			return 0;
		tree.delete_node(k);
		return 1;
	}
	void erase (iterator first, iterator last)
	{
		while (first != last && first != tree.end())
		{
			tree.delete_node(first++);
		}
	}
	void swap (map& x)
	{
		tree.swap(x.tree);
		Allocator temp_alloc = _map_alloc;
		_map_alloc = x._map_alloc;
		x._map_alloc = temp_alloc;
	}

	size_type count( const Key& key ) const
	{
		Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
			return 0;
		return 1;
	}

	iterator find( const Key& key )
	{
		Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
			return tree.end();
		return iterator(found_node);
	}
	const_iterator find( const Key& key ) const
	{
		const Node<value_type> *found_node = tree.find_node(key);
		if (found_node == NULL || found_node == tree._end)
			return tree.end();
		return const_iterator(found_node);
	}
	iterator lower_bound( const Key& key )
	{
		return tree.lower_bound(key);
	}
	const_iterator lower_bound( const Key& key ) const
	{
		return tree.lower_bound(key);
	}
	iterator upper_bound( const Key& key )
	{
		return tree.upper_bound(key);
	}
	const_iterator upper_bound( const Key& key ) const
	{
		return tree.upper_bound(key);
	}
	ft::pair<iterator,iterator> equal_range( const Key& key )
	{
		iterator upper = tree.upper_bound(key);
		if (upper == tree.begin())
			return ft::pair<iterator,iterator>(upper, upper);
		iterator lower = upper;
		--lower;
		if (lower->first == key)
			return ft::pair<iterator,iterator>(lower, upper);
		return ft::pair<iterator,iterator>(upper, upper);
	}
	ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
	{
		const_iterator upper = tree.upper_bound(key);
		if (upper == tree.begin())
			return ft::pair<const_iterator,const_iterator>(upper, upper);
		const_iterator lower = upper;
		--lower;
		if (lower->first == key)
			return ft::pair<const_iterator,const_iterator>(lower, upper);
		return ft::pair<const_iterator,const_iterator>(upper, upper);
	}
	key_compare key_comp() const
	{
		return(tree._cmp);
	}
      private:
	RedBlackTree<value_type, key_compare, Allocator> tree;
	Allocator _map_alloc;
}; // class map

} // namespace ft

#endif
