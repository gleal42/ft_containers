/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/10/05 16:37:22 by gleal            ###   ########.fr       */
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
    struct Reverse_Iterator
    {
        public:
        /* ------------------------------ Member Types ------------------------------ */
			typedef Iter												iterator_type;
            typedef typename iterator_traits<Iter>::random_access_iterator_tag	iterator_category;
            typedef typename iterator_traits<Iter>::value_type					value_type;
			typedef typename iterator_traits<Iter>::difference_type				difference_type;
			typedef typename iterator_traits<Iter>::pointer						pointer;
			typedef typename iterator_traits<Iter>::reference					reference;

		/* ---------------------------- Member Functions ---------------------------- */
		
		/* ------------------------------ CONSTRUCTORS ------------------------------ */
				  
		Reverse_Iterator( void ) : base_iterator(pointer()) {}
		explicit Reverse_Iterator( iterator_type x ) : base_iterator(x) {}
		// TODO: Check if it works
		template< class U >
		Reverse_Iterator( const Reverse_Iterator<U>& other ) : base_iterator(other.base()) {}
		template< class U >
		Reverse_Iterator& operator=( const Reverse_Iterator<U>& other ) { base_iterator = other.base();}
		iterator_type base() const { return base_iterator;}
	    reference operator*() const{ return *base_iterator;}
		pointer operator->() const { return base_iterator.operator->(); }	
		reference operator[] (difference_type n) const { return *(base_iterator - n); }
		Reverse_Iterator& operator++()
		{
			--base_iterator;
			return(*this);
		}
		Reverse_Iterator& operator--()
		{
			++base_iterator;
			return(*this);
		}	
		Reverse_Iterator operator++( int )
		{
			Reverse_Iterator tmp(*this);
			++(*this);
			return(tmp);
		}
		Reverse_Iterator operator--( int )
		{
			Reverse_Iterator tmp(*this);
			--(*this);
			return(tmp);
		}
		Reverse_Iterator operator+( difference_type n ) const
		{
			return (Reverse_Iterator(base_iterator - n));
		}
		Reverse_Iterator operator-( difference_type n ) const
		{
			return (Reverse_Iterator(base_iterator + n));
		}
		Reverse_Iterator& operator+=( difference_type n )
		{
			base_iterator-=n;
			return (*this);
		}
		Reverse_Iterator& operator-=( difference_type n )
		{
			base_iterator+=n;
			return (*this);
		}

		protected:
		iterator_type base_iterator;
	};
};

#endif
