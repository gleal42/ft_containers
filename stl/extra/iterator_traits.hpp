/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:04:47 by gleal             #+#    #+#             */
/*   Updated: 2022/10/02 16:49:19 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

#include <cstddef>
#include <iterator>

// Criar testes a usar std::distance/std::advance para provar a utilidade dos tags

namespace ft
{
    /* ---------------------------------- Tags ---------------------------------- */
    
    typedef	std::input_iterator_tag		        input_iterator_tag;
    typedef	std::output_iterator_tag		    output_iterator_tag;
    typedef	std::forward_iterator_tag		    forward_iterator_tag;
    typedef	std::bidirectional_iterator_tag		bidirectional_iterator_tag;
    typedef	std::random_access_iterator_tag		random_access_iterator_tag;

    /* --------------------- Non specialized Iterator_traits -------------------- */

    template< class Iter >
    struct iterator_traits
    {
        typedef typename Iter::difference_type   difference_type;
        typedef typename Iter::value_type        value_type;
        typedef typename Iter::pointer           pointer;
        typedef typename Iter::reference         reference;
        typedef typename Iter::iterator_category iterator_category;
    };

    /* ----------------------- Specialized Iterator_traits ---------------------- */

    template< class T >
    struct iterator_traits<T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T                            value_type;
        typedef T*                           pointer;
        typedef T&                           reference;
        typedef random_access_iterator_tag      iterator_category;
    };

    template< class T >
    struct iterator_traits<const T*>
    {
        typedef std::ptrdiff_t                  difference_type;
        typedef T							value_type;
		typedef const T*					    pointer;
		typedef const T&					    reference;
		typedef random_access_iterator_tag	    iterator_category;
    };
};

#endif
