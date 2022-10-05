/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:59 by gleal             #+#    #+#             */
/*   Updated: 2022/10/05 23:37:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Implement is_const

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "macros.hpp"
#include "vector_iterator.hpp"
#include "vector_reverse_iterator.hpp"
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
            typedef Reverse_Iterator<iterator>			               		reverse_iterator;
            typedef Reverse_Iterator<const_iterator>						const_reverse_iterator;
            typedef typename std::ptrdiff_t                                 difference_type;
            typedef typename std::size_t                                    size_type;
            /* ---------------------------- Member Functions ---------------------------- */

			/* -------------------------------------------------------------------------- */
			/*                                 CONSTRUCTOR                                */
			/* -------------------------------------------------------------------------- */
			explicit vector (const allocator_type& alloc = allocator_type())
			: _start(0), _finish(0), _end_of_storage(0), _alloc(alloc)
			{
				LOG("default constructor called for vector of type [" << typeid(T).name() << "]" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
			}
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
			{
				LOG("fill constructor called" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
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
				LOG("range constructor called" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
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
			vector (const vector& other)
			{
				LOG("copy constructor called" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
				_start = _alloc.allocate(other.capacity());
				_finish = _start;
				const_iterator other_begin = other.begin();
				const_iterator other_end = other.end();
				while (other_begin < other_end)
				{
					_alloc.construct(_finish, *other_begin);
					_finish++;
					other_begin++;
				}
				_end_of_storage = _start + other.capacity();
			}
			/* ------------------------------ (destructor) ------------------------------ */
			~vector()
			{
				LOG("destructor called" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
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
				LOG("Assignment operator called" << std::endl);
				LOG( (std::is_const<T>::value ? "It IS constant " : "It is NOT constant"));
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
			// TODO: HEEEEEEEEEEEEEERE last time
			void assign( size_type count, const T& value )
			{
				LOG("Assign function called" << std::endl);

				if (count > this->capacity())
				{
					while (_finish-_start > 0)
					{
						_alloc.destroy(_start);
						_finish--;
					}
					_alloc.deallocate(_start, capacity());
					_start = _alloc.allocate(count);
					_finish = _start;
				}
				while ((_finish - _start) < count)
				{
					_alloc.construct(_finish, value);
					_finish++;
				}
				_end_of_storage = _start + count;	
			}
			// template< class InputIt >
			// void assign( InputIt first, InputIt last )
			// {
				
			// }

			/* -------------------------------------------------------------------------- */
			/*                                  Iterators                                 */
			/* -------------------------------------------------------------------------- */

			/* ---------------------------------- begin --------------------------------- */
			iterator begin()
			{
				LOG("iterator begin() called" << std::endl);
				return (iterator(_start));
			}
			const_iterator begin() const
			{
				LOG("const_iterator begin() called" << std::endl);
				return (const_iterator(_start));
			}
			/* ----------------------------------- end ---------------------------------- */
			iterator end()
			{
				LOG("iterator end() called" << std::endl);
				return (iterator(_finish));
			}
			const_iterator end() const
			{
				LOG("const_iterator end() called" << std::endl);
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
			// void resize (size_type n, value_type val = value_type())
			// {
				
			// }

			size_type capacity() const
			{
				return (_end_of_storage - _start);
			}

			/* -------------------------------------------------------------------------- */
			/*                               Element access                               */
			/* -------------------------------------------------------------------------- */

			reference at( size_type pos )
			{
				size_type size_vec = size();
				if (size_vec && pos < size_vec)
					return (_start[pos]);
				throw std::out_of_range("vector");
			}
			const_reference at( size_type pos ) const
			{
				size_type size_vec = size();
				if (size_vec && pos < size_vec)
					return (_start[pos]);
				throw std::out_of_range("vector");	
			}

			reference operator[]( size_type pos )
			{
				return this->_start[pos];
			}

			const_reference operator[]( size_type pos ) const
			{
				return this->_start[pos];
			}
			reference front()
			{
				return *this->_start;
			}
			const_reference front() const
			{
				return *this->_start;
			}	
			reference back()
			{
				return *(this->_finish - 1);
			}
			const_reference back() const
			{
				return *(this->_finish - 1);
			}
			T* data()
			{
				return _start;
			}
			const T* data() const
			{
				return _start;
			}
        private:
            pointer		_start;
            pointer		_finish;
			pointer		_end_of_storage;
            allocator_type	_alloc;
			friend void	vector_custom_tests();
    };
};

#endif
