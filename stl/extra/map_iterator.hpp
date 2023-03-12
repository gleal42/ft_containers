#ifndef __MAP_ITERATOR_H__
#define __MAP_ITERATOR_H__

#include "Node.hpp"

template <class T>
struct map_const_bidirectional_iterator;
namespace ft {
template <class T> struct map_bidirectional_iterator
{
	public:
	/* ------------------------------ Member Types *
	 * ------------------------------ */
	template<typename> friend class CompareHelper;
	template<typename> friend class map_const_bidirectional_iterator;

	typedef std::bidirectional_iterator_tag iterator_category;
	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef typename std::ptrdiff_t difference_type;

	typedef Node<T> node;
	typedef node *node_pointer;

	map_bidirectional_iterator() : node_ptr(node_pointer()) {}
	map_bidirectional_iterator(const node_pointer node) : node_ptr(node) {}
	map_bidirectional_iterator(const map_bidirectional_iterator &old_it)
	    : node_ptr(old_it.node_ptr)
	{
	}
	map_bidirectional_iterator(const map_const_bidirectional_iterator<T> &old_it)
	    : node_ptr(old_it.node_ptr)
	{
	}

	map_bidirectional_iterator &
	operator=(const map_bidirectional_iterator &ra_iter)
	{
		this->node_ptr = ra_iter.node_ptr;
		return *this;
	}

	~map_bidirectional_iterator() {}

	reference operator*() const
	{
		return (node_ptr->data);
	}

	pointer operator->() const
	{
		return (&node_ptr->data);
	}

	map_bidirectional_iterator &operator++()
	{
		node_ptr = node_ptr->next();
		return *this;
	}

	map_bidirectional_iterator operator++(int)
	{
		map_bidirectional_iterator<T> temp(*this);
		++(*this);
		return temp;
	}

	map_bidirectional_iterator &operator--()
	{
		node_ptr = node_ptr->prev();
		return *this;
	}

	map_bidirectional_iterator operator--(int)
	{
		map_bidirectional_iterator<T> temp(*this);
		--(*this);
		return temp;
	}

	// DATA
	private:
	node_pointer node_ptr;
};

template <class T>
struct map_const_bidirectional_iterator
{
	template<typename> friend class CompareHelper;
	template<typename> friend class map_bidirectional_iterator;

	typedef std::bidirectional_iterator_tag iterator_category;
	typedef const Node<T> node;
	typedef node *node_pointer;
	typedef const T value_type;
	typedef const T& reference;
	typedef const T* pointer;
	typedef typename std::ptrdiff_t difference_type;

	map_const_bidirectional_iterator(const node_pointer node) : node_ptr(node) {}
	map_const_bidirectional_iterator(const map_const_bidirectional_iterator<T> &old_it)
	    : node_ptr(old_it.node_ptr)
	{
	}

	map_const_bidirectional_iterator(const map_bidirectional_iterator<T> &old_it)
	    : node_ptr(old_it.node_ptr)
	{
	}
	map_const_bidirectional_iterator<T> &operator++()
	{
		node_ptr = node_ptr->const_next();
		return *this;
	}

	map_const_bidirectional_iterator<T> operator++(int)
	{
		map_const_bidirectional_iterator<T> temp(*this);
		++(*this);
		return temp;
	}
	map_const_bidirectional_iterator<T> &operator--()
	{
		node_ptr = node_ptr->const_prev();
		return *this;
	}
	map_const_bidirectional_iterator<T> operator--(int)
	{
		map_const_bidirectional_iterator<T> temp(*this);
		--(*this);
		return temp;
	}
	reference operator*() const
	{
		return (node_ptr->data);
	}
	pointer operator->() const
	{
		return (&node_ptr->data);
	}

    private:
	// DATA
	node_pointer node_ptr;
};

// Friend compare helper class to be able to access private node_ptr indirectly
// if user tries to create Compare Helper it will not be possible to redifine
// This way we prevent having many operator overloader methods

template<typename T>
class CompareHelper
{
	public:
	typename map_const_bidirectional_iterator<T>::node_pointer m_first;
	typename map_const_bidirectional_iterator<T>::node_pointer m_second;

	CompareHelper(const map_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
		: m_first(a.node_ptr), m_second(b.node_ptr)
	{

	}
	CompareHelper(const map_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
		: m_first(a.node_ptr), m_second(b.node_ptr)
	{

	}
	CompareHelper(const map_const_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
		: m_first(a.node_ptr), m_second(b.node_ptr)
	{

	}
	CompareHelper(const map_const_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
		: m_first(a.node_ptr), m_second(b.node_ptr)
	{

	}
	bool equal() const
	{
		return m_first==m_second;
	}
	bool different() const
	{
		return !equal();
	}
};

template <class T>
bool operator==(const map_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.equal());
}

template <class T>
bool operator!=(const map_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.different());
}

template <class T>
bool operator==(const map_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.equal());
}

template <class T>
bool operator==(const map_const_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.equal());
}

template <class T>
bool operator==(const map_const_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.equal());
}

template <class T>
bool operator!=(const map_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.different());
}

template <class T>
bool operator!=(const map_const_bidirectional_iterator<T> &a,
		const map_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.different());
}

template <class T>
bool operator!=(const map_const_bidirectional_iterator<T> &a,
		const map_const_bidirectional_iterator<T> &b)
{
	CompareHelper<T> temp_compare(a, b);
	return (temp_compare.different());
}

}; // namespace ft

#endif // __MAP_ITERATOR_H__
