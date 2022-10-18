/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:59 by gleal             #+#    #+#             */
/*   Updated: 2022/10/18 15:46:53 by gleal            ###   ########.fr       */
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
#include "is_const.hpp"
#include <typeinfo>
#include <sstream>

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
		LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
	}

	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
	{
		LOG("fill constructor called" << std::endl);
		LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
		alloc_empty(n);
		set_contents(n, val);
	}
	template < class InputIterator>
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	typename enable_if<!is_integral<InputIterator>::value >::type* = 0)
	: _alloc(alloc)
	{
		LOG("range constructor called" << std::endl);
		// LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
		alloc_empty(last - first);
		copy_contents_range_to_end(first, last);
	}
	vector (const vector& other)
	{
		LOG("copy constructor called" << std::endl);
		LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
		alloc_empty(other.capacity());
		copy_contents_range_to_end(other.begin(), other.end());
	}
	/* ------------------------------ (destructor) ------------------------------ */
	~vector()
	{
		LOG("destructor called" << std::endl);
		LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant") << std::endl);
		destroy_contents();
		dealloc();
	}
	/* -------------------------------- operator= ------------------------------- */

	// TODO: Test with empty vector before
	vector& operator= (const vector& x)
	{
		LOG("Assignment operator called" << std::endl);
		LOG( (is_const<T>::value ? "It IS constant " : "It is NOT constant"));
		destroy_contents();
		dealloc();
		alloc_empty(x.capacity());
		copy_contents_range_to_end(x.begin(), x.end());
	}

	void assign( size_type count, const T& value )
	{
		LOG("Assign(size_type count, const T& value) called" << std::endl);
		destroy_contents();
		if (count > this->capacity())
		{
			dealloc();
			alloc_empty(count);
		}
		set_contents(count, value);
	}

	template< class InputIt >
	void assign( InputIt first, InputIt last ,
	typename enable_if<!is_integral<InputIt>::value >::type* = 0)
	{
		LOG("assign( InputIt first, InputIt last) called" << std::endl);

		size_type count = last - first;
		destroy_contents();
		if (count > this->capacity())
		{
			dealloc();
			alloc_empty(count);
		}
		copy_contents_range_to_end(first, last);
	}

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
	reverse_iterator rbegin()
	{
		return (reverse_iterator(_finish));
	}
	const_reverse_iterator rbegin() const
	{
		return (const_reverse_iterator(_finish));
	}

	/* ---------------------------------- rend ---------------------------------- */
	reverse_iterator rend()
	{
		return (reverse_iterator(_start));
	}
	const_reverse_iterator rend() const
	{
		return (const_reverse_iterator(_start));
	}

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
		while (n < size())
		{
			_alloc.destroy(_finish);
			_finish--;
		}
		if (n > capacity())
			set_capacity(n);
		while (size() < n)
		{
			_alloc.constroy(_finish, val);
			_finish++;
		}
	}

	size_type capacity() const
	{
		return (_end_of_storage - _start);
	}

	void reserve (size_type n)
	{
		if (n > capacity())
			set_capacity(n);
	}
	
	/* -------------------------------------------------------------------------- */
	/*                               Element access                               */
	/* -------------------------------------------------------------------------- */

	reference at( size_type pos )
	{
		size_type size_vec = size();
		if (size_vec && pos < size_vec)
			return (_start[pos]);
		throw std::out_of_range(at_error(pos));
	}
	const_reference at( size_type pos ) const
	{
		size_type size_vec = size();
		if (size_vec && pos < size_vec)
			return (_start[pos]);
		throw std::out_of_range(at_error(pos));	
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

	/* -------------------------------------------------------------------------- */
	/*                                  Modifiers                                 */
	/* -------------------------------------------------------------------------- */
	
	// TODO: Checkar melhor / Test
	// TODO: T must meet the requirements of CopyInsertable in order to use overload (1).
	// TODO: exception for max_capacity:
	void push_back( const T& value )
	{
		if (_finish == _end_of_storage)
			set_capacity(_end_of_storage - _start + 1);
		_alloc.construct(_finish, value);
		_finish++;
	}
	
private:
	void destroy_contents( void )
	{
		while (_finish-_start > 0)
		{
			_alloc.destroy(_start);
			_finish--;
		}
	}
	void dealloc()
	{
		_alloc.deallocate(_start, capacity());
		_end_of_storage = _start;
	}
	void alloc_empty(size_t n)
	{
		_start = _alloc.allocate(n);
		_finish = _start;
		_end_of_storage = _start + n;
	}
	void set_capacity(size_t n)
	{
		pointer new_start = _alloc.allocate(n);
		pointer new_finish = new_start;
		const_pointer iterate_current = _start;
		while (iterate_current < _finish)
		{
			_alloc.construct(new_finish, *iterate_current);
			new_finish++;
			iterate_current++;
		}
		destroy_contents();
		dealloc();
		_start = new_start;
		_finish = new_finish;
		_end_of_storage = new_start + n;
	}
	template< class InputIt >
	void copy_contents_range_to_end(InputIt first, InputIt last ,
	typename enable_if<!is_integral<InputIt>::value >::type* = 0)
	{
		while ((last - first) > 0)
		{
			_alloc.construct(_finish, *first);
			_finish++;
			first++;
		}
	}
	void	set_contents(size_type n, const value_type& val)
	{
		for (size_type vec_size = 0; vec_size < n; vec_size++)
		{
			_alloc.construct(_finish, val);
			_finish++;
		}
	}

	#ifdef __linux__
	std::string at_error( size_type pos )
	{
		std::stringstream ss;
		ss << "vector::_M_range_check: __n (which is " << pos << ") >= this->size() (which is " << size() << ")";
		return (ss.str());
	}
	#else
	std::string at_error( size_type pos )
	{
		(void)pos;
		return ("vector");
	}
	#endif

/* ---------------------------- Member Variables ---------------------------- */
	pointer		_start;
	pointer		_finish;
	pointer		_end_of_storage;
	allocator_type	_alloc;
	friend void	vector_custom_tests();
	
}; // class vector
}; // namespace ft

#endif
