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

#include <memory>
#include "pair.hpp"
#include "RedBlackTree.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>,
	  class Allocator = std::allocator<ft::pair<const Key, T> > >
class map
{
	public:
	typedef Key												key_type;
	typedef T 												mapped_type;
	typedef ft::pair<const Key, T> 							value_type;
    typedef typename std::size_t 							size_type;
    typedef typename std::ptrdiff_t 						difference_type;
	typedef Compare 										key_compare;
	typedef Allocator 										allocator_type;
    typedef typename allocator_type::reference 				reference;
    typedef typename allocator_type::const_reference 		const_reference;
    typedef typename allocator_type::pointer 				pointer;
    typedef typename allocator_type::const_pointer 			const_pointer;
    // typedef Map_Bidirectional_Iterator<pointer> 			iterator;
    // typedef Map_Bidirectional_Iterator<const_pointer>		const_iterator;
    // typedef Reverse_Iterator<iterator> 						reverse_iterator;
    // typedef Reverse_Iterator<const_iterator> 				const_reverse_iterator;

    map()
    : tree()
    {
    }
    void insert(const value_type& value)
    {
        tree.add_node(value);
    }

private:
	RedBlackTree<ft::pair<Key, T>, Allocator> tree;
}; // class map




} // namespace ft

#endif
