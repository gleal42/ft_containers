#if !defined(__MAP_ITERATOR_H__)
#define __MAP_ITERATOR_H__

#include "iterator_traits.hpp"

// HERE

namespace ft {
template <class T> struct Map_Bidirectional_Iterator
{
      public:
	/* ------------------------------ Member Types
	 * ------------------------------ */
	typedef bidirectional_iterator_tag iterator_category;
	typedef typename iterator_traits<T>::value_type value_type;
	typedef typename iterator_traits<T>::difference_type difference_type;
	typedef typename iterator_traits<T>::pointer pointer;
	typedef typename iterator_traits<T>::reference reference;

	/* ---------------------------- General Iterator
	 * ---------------------------- */
	Map_Bidirectional_Iterator(const pointer point) : ptr(point) {}

	Map_Bidirectional_Iterator(const Map_Bidirectional_Iterator &ra_iter)
	    : ptr(ra_iter.ptr)
	{
	}

	Map_Bidirectional_Iterator &
	operator=(const Map_Bidirectional_Iterator &ra_iter)
	{
		this->ptr = ra_iter.ptr;
		return *this;
	}

	~Map_Bidirectional_Iterator() {}
	Map_Bidirectional_Iterator &operator++();
	Map_Bidirectional_Iterator operator++(int);
	/* ----------------------------- Input Iterator
	 * ----------------------------- */

	template <class T1>
	friend bool operator==(const Map_Bidirectional_Iterator<T1> &a,
			       const Map_Bidirectional_Iterator<T1> &b);
	template <class T1>
	friend bool operator!=(const Map_Bidirectional_Iterator<T1> &a,
			       const Map_Bidirectional_Iterator<T1> &b);

	reference operator*() const;
	pointer operator->() const;

	/* ---------------------------- Forward Iterator
	 * ---------------------------- */

	Map_Bidirectional_Iterator();

	/* ------------------------- Bidirectional Iterator
	 * ------------------------- */

	Map_Bidirectional_Iterator &operator--();
	Map_Bidirectional_Iterator operator--(int);

	/* ------------------------- Random Access Iterator
	 * ------------------------- */

	Map_Bidirectional_Iterator operator+(difference_type n) const;
	Map_Bidirectional_Iterator operator-(difference_type n) const;
	// Map_Bidirectional_Iterator operator-(const Map_Bidirectional_Iterator
	// &it) const;

	template <class T1>
	friend Map_Bidirectional_Iterator<T1>
	operator+(typename Map_Bidirectional_Iterator<T1>::difference_type n,
		  const Map_Bidirectional_Iterator<T1> &it);
	template <class T1>
	friend typename Map_Bidirectional_Iterator<T1>::difference_type
	operator-(const Map_Bidirectional_Iterator<T1> &a,
		  const Map_Bidirectional_Iterator<T1> &b);
	template <class T1>
	friend bool operator<(const Map_Bidirectional_Iterator<T1> &a,
			      const Map_Bidirectional_Iterator<T1> &b);
	template <class T1>
	friend bool operator>(const Map_Bidirectional_Iterator<T1> &a,
			      const Map_Bidirectional_Iterator<T1> &b);
	template <class T1>
	friend bool operator<=(const Map_Bidirectional_Iterator<T1> &a,
			       const Map_Bidirectional_Iterator<T1> &b);
	template <class T1>
	friend bool operator>=(const Map_Bidirectional_Iterator<T1> &a,
			       const Map_Bidirectional_Iterator<T1> &b);

	Map_Bidirectional_Iterator &operator+=(difference_type n);
	Map_Bidirectional_Iterator &operator-=(difference_type n);

	reference operator[](difference_type n) const;

      private:
	pointer ptr;
};

/* ---------------------------- General Iterator ---------------------------- */

template <class T> Map_Bidirectional_Iterator<T>::~Map_Bidirectional_Iterator()
{
}

template <class T>
Map_Bidirectional_Iterator<T> &Map_Bidirectional_Iterator<T>::operator++()
{
	++(this->ptr);
	return *this;
}

template <class T>
Map_Bidirectional_Iterator<T> Map_Bidirectional_Iterator<T>::operator++(int)
{
	Map_Bidirectional_Iterator<T> temp(*this);
	++(*this);
	return temp;
}

/* ----------------------------- Input Iterator ----------------------------- */

template <class T>
bool operator==(const Map_Bidirectional_Iterator<T> &a,
		const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr == b.ptr);
}

template <class T>
bool operator!=(const Map_Bidirectional_Iterator<T> &a,
		const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr != b.ptr);
}

template <class T>
typename Map_Bidirectional_Iterator<T>::reference
Map_Bidirectional_Iterator<T>::operator*() const
{
	return (*ptr);
}

template <class T>
typename Map_Bidirectional_Iterator<T>::pointer
Map_Bidirectional_Iterator<T>::operator->() const
{
	return (ptr);
}

/* ---------------------------- Forward Iterator ---------------------------- */

template <class T>
Map_Bidirectional_Iterator<T>::Map_Bidirectional_Iterator() : ptr(pointer())
{
}

/* ------------------------- Bidirectional Iterator ------------------------- */
template <class T>
Map_Bidirectional_Iterator<T> &Map_Bidirectional_Iterator<T>::operator--()
{
	--(this->ptr);
	return *this;
}

template <class T>
Map_Bidirectional_Iterator<T> Map_Bidirectional_Iterator<T>::operator--(int)
{
	Map_Bidirectional_Iterator<T> temp(*this);
	--(*this);
	return temp;
}

// /* ------------------------- Random Access Iterator -------------------------
// */
template <class T>
Map_Bidirectional_Iterator<T>
Map_Bidirectional_Iterator<T>::operator+(difference_type n) const
{
	return (Map_Bidirectional_Iterator<T>(this->ptr + n));
}

template <class T>
Map_Bidirectional_Iterator<T>
operator+(typename Map_Bidirectional_Iterator<T>::difference_type n,
	  const Map_Bidirectional_Iterator<T> &it)
{
	Map_Bidirectional_Iterator<T> temp(it);

	temp += n;
	return (temp);
}

template <class T>
Map_Bidirectional_Iterator<T>
Map_Bidirectional_Iterator<T>::operator-(difference_type n) const
{
	return (Map_Bidirectional_Iterator<T>(this->ptr - n));
}

// Still deciding if I use this one:
/*
	template< class T >
	typename Map_Bidirectional_Iterator<T>::difference_type
   Map_Bidirectional_Iterator<T>::operator-(const Map_Bidirectional_Iterator<T>
   &it) const
	{
		return (this->ptr - it.ptr);
	}
*/
template <class T>
typename Map_Bidirectional_Iterator<T>::difference_type
operator-(const Map_Bidirectional_Iterator<T> &a,
	  const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr - b.ptr);
}

template <class T>
bool operator<(const Map_Bidirectional_Iterator<T> &a,
	       const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr < b.ptr);
}

template <class T>
bool operator>(const Map_Bidirectional_Iterator<T> &a,
	       const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr > b.ptr);
}

template <class T>
bool operator<=(const Map_Bidirectional_Iterator<T> &a,
		const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr <= b.ptr);
}

template <class T>
bool operator>=(const Map_Bidirectional_Iterator<T> &a,
		const Map_Bidirectional_Iterator<T> &b)
{
	return (a.ptr >= b.ptr);
}
template <class T>
Map_Bidirectional_Iterator<T> &Map_Bidirectional_Iterator<T>::operator+=(
	    Map_Bidirectional_Iterator<T>::difference_type n)
{
	this->ptr += n;
	return (*this);
}

template <class T>
Map_Bidirectional_Iterator<T> &Map_Bidirectional_Iterator<T>::operator-=(
	    Map_Bidirectional_Iterator<T>::difference_type n)
{
	this->ptr -= n;
	return (*this);
}

template <class T>
typename Map_Bidirectional_Iterator<T>::reference
Map_Bidirectional_Iterator<T>::operator[](
	    Map_Bidirectional_Iterator<T>::difference_type n) const
{
	return (this->ptr[n]);
}
}; // namespace ft

#endif // __MAP_ITERATOR_H__
