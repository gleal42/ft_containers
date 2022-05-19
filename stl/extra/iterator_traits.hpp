/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:04:47 by gleal             #+#    #+#             */
/*   Updated: 2022/05/19 02:03:01 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>

namespace ft
{
    /* ---------------------------------- Tags ---------------------------------- */
    struct input_iterator_tag { };
    struct output_iterator_tag { };
    struct forward_iterator_tag : public input_iterator_tag { };
    struct bidirectional_iterator_tag : public forward_iterator_tag { };
    struct random_access_iterator_tag : public bidirectional_iterator_tag { };

    /* --------------------- Non specialized Iterator_traits -------------------- */

    template< class Iter >
    struct iterator_traits
    {
        typedef Iter::difference_type   difference_type;
        typedef Iter::value_type        value_type;
        typedef Iter::pointer           pointer;
        typedef Iter::reference         reference;
        typedef Iter::iterator_category iterator_category;
    };

    /* ----------------------- Specialized Iterator_traits ---------------------- */

    template< class T >
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t              difference_type;
        typedef T                           value_type;
        typedef T*                          pointer;
        typedef T&                          reference;
        typedef random_access_iterator_tag  iterator_category;
    };

    template< class T >
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t              difference_type;
        typedef T							value_type;
		typedef const T*					pointer;
		typedef const T&					reference;
		typedef random_access_iterator_tag	iterator_category;
    };
};

#endif
