/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/10/02 22:05:54 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

// Reverse Iterator Iter is the ReverseAccessIterator

#include <iostream>

namespace ft
{
    template< class Iter >
    struct reverse_iterator
    {
        public:
        /* ------------------------------ Member Types ------------------------------ */
			typedef typename Iter												iterator_type;
            typedef typename iterator_traits<Iter>::random_access_iterator_tag	iterator_category;
            typedef typename iterator_traits<Iter>::value_type					value_type;
			typedef typename iterator_traits<Iter>::difference_type				difference_type;
			typedef typename iterator_traits<Iter>::pointer						pointer;
			typedef typename iterator_traits<Iter>::reference					reference;

		/* ---------------------------- Member Functions ---------------------------- */
		
		/* ------------------------------ CONSTRUCTORS ------------------------------ */
				  
		reverse_iterator( void ) : ptr(pointer()) {}
		explicit reverse_iterator( iterator_type x ) : base_iterator(x) {}
		// TODO: Check if it works
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other ) : ptr(other.base()) {}
		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ) { base_iterator = other.base();}
		iterator_type base() const { return base_iterator;}
	    reference operator*() const{ return *base_iterator;}
		pointer operator->() const { return base_iterator.operator->(); }	
		reference operator[] (difference_type n) const { return *(base_iterator - n); }
		
		private:
		iterator_type base_iterator;
};

#endif
