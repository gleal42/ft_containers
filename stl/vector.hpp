/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:59 by gleal             #+#    #+#             */
/*   Updated: 2022/05/19 18:35:56 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "vector_iterator.hpp"
#include <memory>

namespace ft
{
    template< class T, class Allocator = std::allocator<T> >
	class vector
    {
        private:

        public:
            /* ------------------------------ Member Types ------------------------------ */
            typedef T                               	value_type;
            typedef Allocator	    					allocator_type;
            typedef typename allocator_type::reference			reference;
            typedef typename allocator_type::const_reference		const_reference;
            typedef typename allocator_type::pointer             pointer;
            typedef typename allocator_type::const_pointer       const_pointer;

    };



};

#endif
