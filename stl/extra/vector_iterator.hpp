/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/10/02 21:07:31 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

// Needs to be LegacyRandomAccessIterator and LegacyContiguousIterator (LegacyIterator) at the same time

#include <iostream>

namespace ft
{
    template< class T >
    struct Random_Access_Iterator
    {
        public:
        /* ------------------------------ Member Types ------------------------------ */
            typedef random_access_iterator_tag				        iterator_category;
            typedef typename iterator_traits<T>::value_type	    	value_type;
			typedef typename iterator_traits<T>::difference_type	difference_type;
			typedef typename iterator_traits<T>::pointer			pointer;
			typedef typename iterator_traits<T>::reference			reference;
		/* ---------------------------- General Iterator ---------------------------- */
            Random_Access_Iterator(const pointer point);
            Random_Access_Iterator(const Random_Access_Iterator &ra_iter);
            Random_Access_Iterator &operator=(const Random_Access_Iterator &ra_iter);
            ~Random_Access_Iterator();
            Random_Access_Iterator &operator++();
            Random_Access_Iterator operator++(int);
		/* ----------------------------- Input Iterator ----------------------------- */

			template< class T1 >
			friend bool	operator==(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);
			template< class T1 >
			friend bool	operator!=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);

			reference operator*() const;
			pointer operator->() const;

		/* ---------------------------- Forward Iterator ---------------------------- */

            Random_Access_Iterator();

		/* ------------------------- Bidirectional Iterator ------------------------- */

            Random_Access_Iterator &operator--();
            Random_Access_Iterator operator--(int);

		/* ------------------------- Random Access Iterator ------------------------- */

            Random_Access_Iterator operator+(difference_type n) const;
            Random_Access_Iterator operator-(difference_type n) const;
            // Random_Access_Iterator operator-(const Random_Access_Iterator &it) const;
		
			template< class T1 >
			friend Random_Access_Iterator<T1> operator+(typename Random_Access_Iterator<T1>::difference_type n, const Random_Access_Iterator<T1> &it);
			template< class T1 >
			friend typename Random_Access_Iterator<T1>::difference_type operator-(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);
			template< class T1 >
			friend bool	operator<(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);
			template< class T1 >
			friend bool	operator>(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);
			template< class T1 >
			friend bool	operator<=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);
			template< class T1 >
			friend bool	operator>=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T1> &b);

            Random_Access_Iterator &operator+=(difference_type n);
            Random_Access_Iterator &operator-=(difference_type n);

			reference operator[](difference_type n) const;

        private:
			pointer ptr;
    };

	/* ---------------------------- General Iterator ---------------------------- */

    template< class T >
	Random_Access_Iterator<T>::Random_Access_Iterator(const pointer point)
	: ptr(point)
	{
	}

    template< class T >
    Random_Access_Iterator<T>::Random_Access_Iterator(const Random_Access_Iterator<T> &ra_iter)
	{
		*this = ra_iter;
	}
	// TODO: Check if this works (because of private pointer)
    template< class T >
    Random_Access_Iterator<T> &Random_Access_Iterator<T>::operator=(const Random_Access_Iterator<T> &ra_iter)
	{
		this->ptr = ra_iter.ptr;
		return *this;
	}

    template< class T >
    Random_Access_Iterator<T>::~Random_Access_Iterator()
	{
	}

    template< class T >
    Random_Access_Iterator<T> &Random_Access_Iterator<T>::operator++()
	{
		++(this->ptr);
		return *this;
	}
	
    template< class T >
    Random_Access_Iterator<T> Random_Access_Iterator<T>::operator++(int)
	{
		Random_Access_Iterator<T> temp(*this);
		++(*this);
		return temp;
	}

	/* ----------------------------- Input Iterator ----------------------------- */

    template< class T >
	bool	operator==(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr == b.ptr);
	}

    template< class T >
	bool	operator!=(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr != b.ptr);
	}
	
    template< class T >
	typename Random_Access_Iterator<T>::reference Random_Access_Iterator<T>::operator*() const
	{
		return (*ptr);
	}

    template< class T >
	typename Random_Access_Iterator<T>::pointer Random_Access_Iterator<T>::operator->() const
	{
		return (ptr);
	}

	/* ---------------------------- Forward Iterator ---------------------------- */

	template< class T >
    Random_Access_Iterator<T>::Random_Access_Iterator() : ptr(pointer())
	{
	}

	/* ------------------------- Bidirectional Iterator ------------------------- */
	template< class T >
    Random_Access_Iterator<T> &Random_Access_Iterator<T>::operator--()
	{
		--(this->ptr);
		return ptr;
	}
	
	template< class T >
    Random_Access_Iterator<T> Random_Access_Iterator<T>::operator--(int)
	{
		Random_Access_Iterator<T> temp(*this);
		--(*this);
		return temp;
	}
	
	// /* ------------------------- Random Access Iterator ------------------------- */
	template< class T >
    Random_Access_Iterator<T> Random_Access_Iterator<T>::operator+(difference_type n) const
	{
		return (Random_Access_Iterator<T>(this->ptr + n));
	}

	template< class T >
	Random_Access_Iterator<T> operator+(typename Random_Access_Iterator<T>::difference_type n, const Random_Access_Iterator<T> &it)
	{
		Random_Access_Iterator<T>	temp(it);
		
		temp += n;
		return (temp);
	}

	template< class T >
    Random_Access_Iterator<T> Random_Access_Iterator<T>::operator-(difference_type n) const
	{
		return (Random_Access_Iterator<T>(this->ptr - n));
	}

	// Still deciding if I use this one:
/* 	
	template< class T >
	typename Random_Access_Iterator<T>::difference_type Random_Access_Iterator<T>::operator-(const Random_Access_Iterator<T> &it) const
	{
		return (this->ptr - it.ptr);
	}
*/
	template< class T >
	typename Random_Access_Iterator<T>::difference_type operator-(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr - b.ptr);
	}

	template< class T >
	bool	operator<(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr < b.ptr);
	}
	
	template< class T >
	bool	operator>(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr > b.ptr);
	}
	
	template< class T >
	bool	operator<=(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr <= b.ptr);
	}
	
	template< class T >
	bool	operator>=(const Random_Access_Iterator<T> &a, const Random_Access_Iterator<T> &b)
	{
		return (a.ptr >= b.ptr);
	}
	template< class T >
    Random_Access_Iterator<T> &Random_Access_Iterator<T>::operator+=(Random_Access_Iterator<T>::difference_type n)
	{
		this->ptr += n;
		return (*this);
	}

	template< class T >
    Random_Access_Iterator<T> &Random_Access_Iterator<T>::operator-=(Random_Access_Iterator<T>::difference_type n)
	{
		this->ptr -= n;
		return (*this);
	}

	template< class T >
	typename Random_Access_Iterator<T>::reference Random_Access_Iterator<T>::operator[](Random_Access_Iterator<T>::difference_type n) const
	{
		return (this->ptr[n]);
	}
};

#endif
