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
	typedef typename std::size_t size_type;
	typedef typename std::ptrdiff_t difference_type;
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

	map()
	    : tree(), _map_alloc()
	{
	}

    explicit map( const Compare& comp,
                const Allocator& alloc = Allocator() )
    :  tree(comp)
    {

    }

    template< class InputIt >
    map( InputIt first, InputIt last,
        const Compare& comp = Compare(),
        const Allocator& alloc = Allocator() )
    {

    }

    map (const map& x)
    {

    }

    void insert(const value_type &value) { tree.add_node(value); }
	iterator begin() { return tree.begin(); }
	// const_iterator begin() const;

      private:
	RedBlackTree<value_type, key_compare, Allocator> tree;
	Allocator _map_alloc;
}; // class map

} // namespace ft

#endif
