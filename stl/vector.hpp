/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:22:04 by gleal             #+#    #+#             */
/*   Updated: 2022/11/26 17:22:07 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "extra/enable_if.hpp"
#include "extra/vector_iterator.hpp"
#include "extra/reverse_iterator.hpp"
#include <memory>
#include <sstream>

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class vector
{
  public:

	/* ------------------------------ Member Types ------------------------------ */

    typedef T 													value_type;
    typedef Allocator 											allocator_type;
    typedef typename allocator_type::reference 					reference;
    typedef typename allocator_type::const_reference 			const_reference;
    typedef typename allocator_type::pointer 					pointer;
    typedef typename allocator_type::const_pointer 				const_pointer;
    typedef Random_Access_Iterator<pointer> 					iterator;
    typedef Random_Access_Iterator<const_pointer> 				const_iterator;
    typedef Reverse_Iterator<iterator> 							reverse_iterator;
    typedef Reverse_Iterator<const_iterator> 					const_reverse_iterator;
    typedef typename std::ptrdiff_t 							difference_type;
    typedef typename std::size_t 								size_type;

    /* ---------------------------- Member Functions * ---------------------------- */

	/* -------------------------------------------------------------------------- */
	/*                                 CONSTRUCTOR                                */
	/* -------------------------------------------------------------------------- */

    explicit vector (const allocator_type &alloc = allocator_type ())
        : _start (0), _finish (0), _end_of_storage (0), _alloc (alloc)
    {
    }

    explicit vector (size_type n, const value_type &val = value_type (),
                     const allocator_type &alloc = allocator_type ())
        : _alloc (alloc)
    {
        alloc_empty (n);
        set_contents (n, val);
    }
    template <class InputIterator>
    vector (InputIterator first, InputIterator last,
            const allocator_type &alloc = allocator_type (),
            typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
        : _alloc (alloc)
    {
        alloc_empty (range_difference(first, last));
        copy_contents_range_to_end (first, last);
    }
    vector (const vector &other)
    {
        alloc_empty (other.size ());
        copy_contents_range_to_end (other.begin (), other.end ());
    }
	/* ------------------------------ (destructor) ------------------------------ */
    ~vector ()
    {
        destroy_contents ();
        dealloc ();
    }

    // TODO: Test with empty vector before
    vector &operator= (const vector &x)
    {
        destroy_contents ();
        if (x.size () > capacity ()) {
            dealloc ();
            alloc_empty (x.size ());
        }
        copy_contents_range_to_end (x.begin (), x.end ());
        return *this;
    }

    void assign (size_type count, const T &value)
    {
        destroy_contents ();
        if (count > this->capacity ()) {
            dealloc ();
            alloc_empty (count);
        }
        set_contents (count, value);
    }

    template <class InputIt>
    void assign (InputIt first, InputIt last,
                 typename enable_if<!is_integral<InputIt>::value>::type * = 0)
    {
        size_type count = range_difference(first, last);
        destroy_contents ();
        if (count > this->capacity ()) {
            dealloc ();
            alloc_empty (count);
        }
        copy_contents_range_to_end (first, last);
    }

    allocator_type get_allocator () const { return _alloc; }

	/* ----------------------------- Element access ----------------------------- */
    reference at (size_type pos)
    {
        size_type size_vec = size ();
        if (size_vec && pos < size_vec)
            return (_start[pos]);
#ifdef __linux__
        throw std::out_of_range (at_error (pos));
#else
        throw std::out_of_range ("vector");
#endif
    }
    const_reference at (size_type pos) const
    {
        size_type size_vec = size ();
        if (size_vec && pos < size_vec)
            return (_start[pos]);
#ifdef __linux__
        throw std::out_of_range (at_error (pos));
#else
        throw std::out_of_range ("vector");
#endif
    }

    reference operator[] (size_type pos) { return this->_start[pos]; }

    const_reference operator[] (size_type pos) const
    {
        return this->_start[pos];
    }
    reference front () { return *this->_start; }
    const_reference front () const { return *this->_start; }
    // TODO: test back() on empty container
    reference back () { return *(this->_finish - 1); }
    const_reference back () const { return *(this->_finish - 1); }
    T *data () { return _start; }
    const T *data () const { return _start; }

	/* -------------------------------------------------------------------------- */
	/*                                  Iterators                                 */
	/* -------------------------------------------------------------------------- */

	/* ---------------------------------- begin --------------------------------- */
    iterator begin ()
    {
        return (iterator (_start));
    }
    const_iterator begin () const
    {
        return (const_iterator (_start));
    }
	/* ----------------------------------- end ---------------------------------- */
    iterator end ()
    {
        return (iterator (_finish));
    }
    const_iterator end () const
    {
        return (const_iterator (_finish));
    }

	/* --------------------------------- rbegin --------------------------------- */

    reverse_iterator rbegin () { return (reverse_iterator (_finish)); }
    const_reverse_iterator rbegin () const
    {
        return (const_reverse_iterator (_finish));
    }

	/* ---------------------------------- rend ---------------------------------- */
    reverse_iterator rend () { return (reverse_iterator (_start)); }
    const_reverse_iterator rend () const
    {
        return (const_reverse_iterator (_start));
    }

	/* -------------------------------------------------------------------------- */
	/*                                  Capacity                                  */
	/* -------------------------------------------------------------------------- */
    bool empty () const { return (_finish == _start); }
    size_type size () const { return (_finish - _start); }
    size_type max_size () const { return (_alloc.max_size ()); }
    void reserve (size_type n)
    {
        if (n > capacity ())
            set_capacity (n);
    }
    size_type capacity () const { return (_end_of_storage - _start); }

	/* -------------------------------------------------------------------------- */
	/*                                  Modifiers                                 */
	/* -------------------------------------------------------------------------- */
    // TODO: create test erasing and checking capacity
    void clear () { destroy_contents (); }

    // Not clear in cppreference but clear in cplusplus
    iterator insert (iterator pos, const T &value)
    {
        insert (pos, 1, value);
        return pos;
    }

    // Not clear in cppreference but clear in cplusplus
    // size_t new_cap = _end_of_storage - _start + n;
    void insert (iterator position, size_type n, const value_type &val)
    {
        insert_realloc (position, n);
        move_contents_forward_from (position, n);
        set_contents (n, val, &(*position));
        _finish += n;
    }

    // Not clear in cppreference but clear in cplusplus
    // NOTE: cap > 0 might be redundant
    template <class InputIterator>
    void
    insert (iterator position, InputIterator first, InputIterator last,
            typename enable_if<!is_integral<InputIterator>::value>::type * = 0)
    {
        size_type n = range_difference(first, last);
        insert_realloc (position, n);
        move_contents_forward_from (position, n);
        while (first != last) {
            set_contents (1, *first, &(*position));
            first++;
            position++;
        }
        _finish += n;
    }

    iterator erase (iterator pos) { return (erase (pos, pos + 1)); }

    iterator erase (iterator first, iterator last)
    {
        iterator ret_val = first;
        while (last != end ()) {
            _alloc.destroy (&*first);
            _alloc.construct (&*first, *last);
            ++last;
            ++first;
        }
        _finish = &*first;
        return (ret_val);
    }

    void push_back (const T &value) { insert (end (), 1, value); }

    void pop_back () { erase (end () - 1); }

    void resize (size_type n, value_type val = value_type ())
    {
        if (n < size())
        {
            while (n < size ()) {
                _alloc.destroy (_finish);
                _finish--;
            }
        }
        else if (n > size ())
        {
            if (n > (size() * 2))
                set_capacity (n);
            else
                {
                    size_type i = n - size();
                    for (; i > 0; i--) {
                        this->push_back(val);
                    }
                }

        }
        set_contents (n - size (), val);
    }
    void swap (vector &other)
    {
        swap (&_start, &other._start);
        swap (&_finish, &other._finish);
        swap (&_end_of_storage, &other._end_of_storage);
    }

private:
    void swap (pointer *first, pointer *second)
    {
        pointer tmp = *first;
        *first = *second;
        *second = tmp;
    }
    void destroy_contents (void)
    {
        while (_finish - _start > 0) {
            _alloc.destroy (_start);
            _finish--;
        }
    }
    void dealloc ()
    {
        _alloc.deallocate (_start, capacity ());
        _end_of_storage = _start;
    }
    void insert_realloc (iterator &position, size_t n)
    {
        if (_finish + n > _end_of_storage) {
            size_t cap = capacity ();
            size_t req_cap = cap + _finish + n - _end_of_storage;
            size_t pos_dist = position - begin ();
            if (cap < req_cap)
                cap = (cap > 0 && (cap * 2) > req_cap) ? cap * 2 : req_cap;
            set_capacity (cap);
            position = _start + pos_dist;
        }
    }
    void alloc_empty (size_t n)
    {
        _start = _alloc.allocate (n);
        _finish = _start;
        _end_of_storage = _start + n;
    }
    void set_capacity (size_t n)
    {
        if (n > max_size()){
            throw std::length_error("vector::reserve");
        }
        pointer new_start = _alloc.allocate (n);
        pointer new_finish = new_start;
        const_pointer iterate_current = _start;
        while (iterate_current < _finish) {
            _alloc.construct (new_finish, *iterate_current);
            new_finish++;
            iterate_current++;
        }
        destroy_contents ();
        dealloc ();
        _start = new_start;
        _finish = new_finish;
        _end_of_storage = new_start + n;
    }
    template <class InputIt>
    void copy_contents_range_to_end (
        InputIt first, InputIt last,
        typename enable_if<!is_integral<InputIt>::value>::type * = 0)
    {
        while (range_difference(first, last) > 0) {
            _alloc.construct (_finish, *first);
            _finish++;
            first++;
        }
    }

    // Most pos are _finish add iterator (end())
    void set_contents (size_type n, const value_type &val)
    {
        for (size_type vec_size = 0; vec_size < n; vec_size++) {
            _alloc.construct (_finish, val);
            _finish++;
        }
    }

    void set_contents (size_type n, const value_type &val, pointer pos)
    {
        for (size_type vec_size = 0; vec_size < n; vec_size++) {
            _alloc.construct (pos, val);
            pos++;
        }
    }

    // [1][2][3][4][5][6][ ][ ][ ][ ][ ][ ]
    // [1][2][3][4][5][ ][ ][ ][ ][6][ ][ ]
    // [1][2][3][4][ ][ ][ ][ ][5][6][ ][ ]
    // [1][2][3][ ][ ][ ][ ][4][5][6][ ][ ]
    // [1][2][ ][ ][ ][ ][3][4][5][6][ ][ ]

    void move_contents_forward_from (iterator start, size_type n)
    {
        if (n == 0)
            return;
        iterator move_from = _finish - 1;
        iterator move_to = move_from + n;
        while (start <= move_from) {
            _alloc.construct (&*move_to, *move_from);
            _alloc.destroy (&*move_from);
            --move_from;
            --move_to;
        }
    }

    std::string at_error (size_type pos) const
    {
        std::stringstream ss;
        ss << "vector::_M_range_check: __n (which is " << pos
           << ") >= this->size() (which is " << size () << ")";
        return (ss.str ());
    }

    template <class InputIterator>
    size_t range_difference(InputIterator first, InputIterator last)
    {
        size_t range_diff = 0;
        while (first != last)
        {
            ++first;
            ++range_diff;
        }
        return range_diff;
    }
    /* ---------------------------- Member Variables
     * ---------------------------- */
    pointer _start;
    pointer _finish;
    pointer _end_of_storage;
    allocator_type _alloc;
}; // class vector

template <class T, class Alloc>
void swap (vector<T, Alloc> &lhs, vector<T, Alloc> &rhs)
{
    lhs.swap (rhs);
}

template <class T, class Alloc>
bool operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    if (lhs.size () != rhs.size ())
        return false;
    for (typename vector<T, Alloc>::const_iterator it_lhs = lhs.begin (),
                                                   it_rhs = rhs.begin ();
         it_lhs != lhs.end (); it_lhs++, it_rhs++) {
        if (*it_lhs != *it_rhs)
            return false;
    }
    return true;
}

template <class T, class Alloc>
bool operator!= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator< (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    typename vector<T, Alloc>::const_iterator it_lhs = lhs.begin (),
                                              it_rhs = rhs.begin ();
    for (; it_lhs != lhs.end () && it_rhs != rhs.end () && *it_lhs == *it_rhs;
         it_lhs++, it_rhs++) {
    }
    if (it_rhs == rhs.end ()) {
        return false;
    }
    if (it_lhs == lhs.end ()) {
        return true;
    }
    return *it_lhs < *it_rhs;
}

template <class T, class Alloc>
bool operator<= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return lhs < rhs || lhs == rhs;
}

template <class T, class Alloc>
bool operator> (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return !(lhs <= rhs);
}

template <class T, class Alloc>
bool operator>= (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return lhs > rhs || lhs == rhs;
}

}; // namespace ft

#endif
