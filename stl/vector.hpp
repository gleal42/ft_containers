/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:59 by gleal             #+#    #+#             */
/*   Updated: 2022/06/01 23:59:05 by gleal            ###   ########.fr       */
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
        public:
            /* ------------------------------ Member Types ------------------------------ */
            typedef T												        value_type;
            typedef Allocator	     			    				    	allocator_type;
            typedef typename allocator_type::reference			        	reference;
            typedef typename allocator_type::const_reference	        	const_reference;
            typedef typename allocator_type::pointer				        pointer;
            typedef typename allocator_type::const_pointer  	    		const_pointer;
            typedef Random_Access_Iterator<pointer>				     	    iterator;
            typedef Random_Access_Iterator<const_pointer>	        		const_iterator;
            // typedef Reverse_Iterator<iterator>			                reverse_iterator;
            // typedef Reverse_Iterator<const_iterator>		              	const_reverse_iterator;
            typedef typename std::ptrdiff_t                                 difference_type;
            typedef typename std::size_t                                    size_type;
            /* ---------------------------- Member Functions ---------------------------- */
            // vector(); //(1) (not clear if C++98)
            explicit vector( const Allocator& alloc ); //(2)
            explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator()); // (3)
            template< class InputIt >
            vector( InputIt first, InputIt last, const Allocator& alloc = Allocator() ); // (5)
            vector( const vector& other );

        private:
            pointer start;
            pointer finish;
    };
    
/*
    template< class T, class Allocator >
    vector < T, Allocator>::vector()
    {
    }
*/
    template < class T, class Allocator > 
    explicit vector(size_type count, const T& value, const Allocator& alloc)
    {
        
    }

};

#endif
