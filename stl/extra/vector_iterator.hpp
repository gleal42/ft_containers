/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:18:17 by gleal             #+#    #+#             */
/*   Updated: 2022/05/19 23:38:13 by gleal            ###   ########.fr       */
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
            Random_Access_Iterator(const Random_Access_Iterator &ra_iter);
            Random_Access_Iterator &operator=(const Random_Access_Iterator &ra_iter);
            ~Random_Access_Iterator();
            Random_Access_Iterator &operator++();
            Random_Access_Iterator &operator++(int);
		/* ----------------------------- Input Iterator ----------------------------- */
			bool	operator==(const Random_Access_Iterator &ra_iter);
			bool	operator!=(const Random_Access_Iterator &ra_iter);
			reference operator*();
			pointer operator->();
			// Can be dereferenced as an lvalue vs rvalue not clear implementation

		/* ---------------------------- Forward Iterator ---------------------------- */
            Random_Access_Iterator();
			// Multi-Pass not clear implementation

		/* ------------------------- Bidirectional Iterator ------------------------- */
            Random_Access_Iterator &operator--();
            Random_Access_Iterator &operator--(int);
		/* ------------------------- Random Access Iterator ------------------------- */
            Random_Access_Iterator &operator+(difference_type n);
            Random_Access_Iterator &operator-(difference_type n);
            Random_Access_Iterator &operator+(Random_Access_Iterator &n);
            Random_Access_Iterator &operator-(Random_Access_Iterator &)n;

			bool	operator<(const Random_Access_Iterator &ra_iter);
			bool	operator>(const Random_Access_Iterator &ra_iter);
			bool	operator<=(const Random_Access_Iterator &ra_iter);
			bool	operator>=(const Random_Access_Iterator &ra_iter);

            Random_Access_Iterator &operator+=(difference_type n);
            Random_Access_Iterator &operator-=(difference_type n);

			reference operator[](difference_type n);
        private:
			pointer ptr;
    };






};

#endif
