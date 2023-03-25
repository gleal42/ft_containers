/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/10/18 21:14:58 by gleal            ###   ########.fr       */
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
            Random_Access_Iterator(const pointer point)
			: ptr(point)
			{
			}

			template <typename T1>
            Random_Access_Iterator(const Random_Access_Iterator<T1> &ra_iter)
			: ptr(ra_iter.ptr)
			{
			}

            Random_Access_Iterator &operator=(const Random_Access_Iterator &ra_iter)
			{
				this->ptr = ra_iter.ptr;
				return *this;
			}

            ~Random_Access_Iterator()
			{
			}
            Random_Access_Iterator &operator++()
			{
				++(this->ptr);
				return *this;
			}
            Random_Access_Iterator operator++(int)
			{
				Random_Access_Iterator<T> temp(*this);
				++(*this);
				return temp;
			}
		/* ----------------------------- Input Iterator ----------------------------- */

			reference operator*() const
			{
				return (*ptr);
			}

			pointer operator->() const
			{
				return (ptr);
			}

		/* ---------------------------- Forward Iterator ---------------------------- */

            Random_Access_Iterator() : ptr(pointer())
			{
			}

		/* ------------------------- Bidirectional Iterator ------------------------- */

            Random_Access_Iterator &operator--()
			{
				--(this->ptr);
				return *this;
			}
            Random_Access_Iterator operator--(int)
			{
				Random_Access_Iterator<T> temp(*this);
				--(*this);
				return temp;
			}

		/* ------------------------- Random Access Iterator ------------------------- */

            Random_Access_Iterator operator+(difference_type n) const
			{
				return (Random_Access_Iterator<T>(this->ptr + n));
			}

            Random_Access_Iterator operator-(difference_type n) const
			{
				return (Random_Access_Iterator<T>(this->ptr - n));
			}

            Random_Access_Iterator &operator+=(difference_type n)
			{
				this->ptr += n;
				return (*this);
			}
            Random_Access_Iterator &operator-=(difference_type n)
			{
				this->ptr -= n;
				return (*this);
			}

			reference operator[](difference_type n) const
			{
				return (this->ptr[n]);
			}

			pointer ptr;
    }; // struct Random_Access_Iterator

    template< class T>
	Random_Access_Iterator<T> operator+(typename Random_Access_Iterator<T>::difference_type n, const Random_Access_Iterator<T> &it)
	{
		Random_Access_Iterator<T>	temp(it);
		temp += n;
		return (temp);
	}

    template< class T1, class T2 >
	bool	operator==(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr == b.ptr);
	}

    template< class T1, class T2 >
	bool	operator!=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr != b.ptr);
	}


    template< class T1, class T2 >
	typename Random_Access_Iterator<T1>::difference_type operator-(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr - b.ptr);
	}

    template< class T1, class T2 >
	bool	operator<(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr < b.ptr);
	}
	
	template< class T1, class T2 >
	bool	operator>(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr > b.ptr);
	}
	
	template< class T1, class T2 >
	bool	operator<=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr <= b.ptr);
	}
	
	template< class T1, class T2 >
	bool	operator>=(const Random_Access_Iterator<T1> &a, const Random_Access_Iterator<T2> &b)
	{
		return (a.ptr >= b.ptr);
	}

}; // namespace ft

#endif
