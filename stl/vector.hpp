/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:59 by gleal             #+#    #+#             */
/*   Updated: 2022/06/08 17:11:32 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "vector_iterator.hpp"
#include <memory>
#include "enable_if.hpp"

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

			/* ------------------------------ (constructor) ----------------------------- */
			explicit vector (const allocator_type& alloc = allocator_type())
			: _start(0), _finish(0), _end_of_storage(0), _alloc(alloc)
			{
				// std::cout << "default constructor called" << std::endl;
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				// std::cout << "fill constructor called" << std::endl;
				_start = _alloc.allocate(n);
				_finish = _start;
				for (size_type vec_size = 0; vec_size < n; vec_size++)
				{
					_alloc.construct(_finish, val);
					_finish++;
				}
				_end_of_storage = _finish;
			}
			template < class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename enable_if<!is_integral<InputIterator>::value >::type* = 0)
			: _alloc(alloc)
			{
				// std::cout << "range constructor called" << std::endl;
				size_type range_size = last - first;
				_start = _alloc.allocate(range_size);
				_finish = _start;
				while (first < last)
				{
					_alloc.construct(_finish, *first);
					_finish++;
					first++;
				}
				_end_of_storage = _finish;
			}
			vector (const vector& x)
			{
				std::cout << "copy constructor called" << std::endl;
				_start = _alloc.allocate(x.capacity());
				_finish = _start;
				iterator x_begin = x.begin();
				iterator x_end = x.end();
				while (x_begin < x_end)
				{
					_alloc.construct(_finish, *x_begin);
					_finish++;
					x_begin++;
				}
				_end_of_storage = _start + x.capacity();
			}
			/* ------------------------------ (destructor) ------------------------------ */
			~vector()
			{
				size_type count = _finish-_start;
				while (_finish-_start > 0)
				{
					_alloc.destroy(_start);
					_finish--;
				}
				_alloc.deallocate(_start, count);
			}
			/* -------------------------------- operator= ------------------------------- */

			vector& operator= (const vector& x)
			{
				size_type count = _finish -_start;
				while (_finish-_start > 0)
				{
					_alloc.destroy(_start);
					_finish--;
				}
				_alloc.deallocate(_start, count);

				_start = _alloc.allocate(x.capacity());
				_finish = _start;
				pointer x_begin = x.begin();
				pointer x_end = x.end();
				while (x_begin < x_end)
				{
					_alloc.construct(_finish, *x_begin);
					_finish++;
					x_begin++;
				}
				_end_of_storage = _start + x.capacity();
			}

			/* -------------------------------------------------------------------------- */
			/*                                  Iterators                                 */
			/* -------------------------------------------------------------------------- */

			/* ---------------------------------- begin --------------------------------- */
			iterator begin()
			{
				return (iterator(_start));
			}
			const_iterator begin() const
			{
				return (const_iterator(_start));
			}
			/* ----------------------------------- end ---------------------------------- */
			iterator end()
			{
				return (iterator(_finish));
			}
			const_iterator end() const
			{
				return (const_iterator(_finish));
			}
			/* --------------------------------- rbegin --------------------------------- */
			// reverse_iterator rbegin()
			// {
			// 	return (reverse_iterator(_start));
			// }
			// const_reverse_iterator rbegin() const
			// {
			// 	return (const_reverse_iterator(_start));
			// }

			/* ---------------------------------- rend ---------------------------------- */
			// reverse_iterator rend()
			// {
			// 	return (reverse_iterator(_finish));
			// }
			// const_reverse_iterator rend() const
			// {
			// 	return (const_reverse_iterator(_finish));
			// }
	
			/* -------------------------------------------------------------------------- */
			/*                                  Capacity                                  */
			/* -------------------------------------------------------------------------- */
			size_type size() const
			{
				return (_finish - _start);
			}
			size_type max_size() const
			{
				return(_alloc.max_size());
			}
			void resize (size_type n, value_type val = value_type())
			{
				
			}
        private:
            pointer		_start;
            pointer		_finish;
			pointer		_end_of_storage;
            allocator_type	_alloc;
    };
};

#endif
