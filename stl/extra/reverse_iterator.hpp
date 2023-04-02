/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/11/20 18:26:34 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

// Reverse Iterator Iter is the ReverseAccessIterator

#include <iostream>

// TODO: Create generic ft::reverse_iterator which simply inverts base iterator (requirement for project)

namespace ft
{
    template< class Iter >
    struct Reverse_Iterator
    {
        public:
        /* ------------------------------ Member Types ------------------------------ */
			typedef Iter												iterator_type;
            typedef random_access_iterator_tag							iterator_category;
            typedef typename iterator_traits<Iter>::value_type			value_type;
			typedef typename iterator_traits<Iter>::difference_type		difference_type;
			typedef typename iterator_traits<Iter>::pointer				pointer;
			typedef typename iterator_traits<Iter>::reference			reference;

		/* ---------------------------- Member Functions ---------------------------- */
		
		/* ------------------------------ CONSTRUCTORS ------------------------------ */
				  
		Reverse_Iterator( void ) : base_iterator() {}
		explicit Reverse_Iterator( iterator_type x ) : base_iterator(x) {}
		template< class U >
		Reverse_Iterator( const Reverse_Iterator<U>& other ) : base_iterator(other.base()) {}
		template< class U >
		Reverse_Iterator& operator=( const Reverse_Iterator<U>& other )
		{
			base_iterator = other.base();
		}
		iterator_type base() const
		{
			return base_iterator;
		}
	    reference operator*() const
		{
			iterator_type temp = base_iterator;
			return *--temp;
		}
		pointer operator->() const
		{
			return &(operator*());
		}	
		reference operator[] (difference_type n) const { return *(*this + n); }
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
			operator++();
			return(tmp);
		}
		Reverse_Iterator operator--( int )
		{
			Reverse_Iterator tmp(*this);
			operator--();
			return(tmp);
		}
		Reverse_Iterator operator+( difference_type n ) const
		{
			return Reverse_Iterator(base_iterator - n );
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

	// Non-member functions
	template< class Iterator1, class Iterator2 >
	bool operator==( const Reverse_Iterator<Iterator1>& lhs,
		const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() == rhs.base()); }

	template< class Iterator1, class Iterator2 >
	bool operator!=( const Reverse_Iterator<Iterator1>& lhs,
		const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() != rhs.base()); }

	template< class Iterator1, class Iterator2 >
	bool operator<( const Reverse_Iterator<Iterator1>& lhs,
					const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() > rhs.base());}	

	template< class Iterator1, class Iterator2 >
	bool operator<=( const Reverse_Iterator<Iterator1>& lhs,
					const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() >= rhs.base()); }

	template< class Iterator1, class Iterator2 >
	bool operator>( const Reverse_Iterator<Iterator1>& lhs,
                const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() < rhs.base()); }

	template< class Iterator1, class Iterator2 >
	bool operator>=( const Reverse_Iterator<Iterator1>& lhs,
					const Reverse_Iterator<Iterator2>& rhs )
	{ return (lhs.base() <= rhs.base()); }

	template< class Iter >
	Reverse_Iterator<Iter>
		operator+( typename Reverse_Iterator<Iter>::difference_type n,
               const Reverse_Iterator<Iter>& it )
	{ return Reverse_Iterator<Iter>(it.base() - n); }

	template< class Iterator1, class Iterator2 >
	typename Reverse_Iterator<Iterator1>::difference_type
		operator-( const Reverse_Iterator<Iterator1>& lhs,
               const Reverse_Iterator<Iterator2>& rhs )
	{ return (rhs.base() - lhs.base()); }
};

#endif
