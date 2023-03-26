#ifndef __PAIR_H__
#define __PAIR_H__

// value initialization
// https://en.cppreference.com/w/cpp/language/value_initialization

namespace ft {

template <class T1, class T2> struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	first_type first;
	second_type second;

    // default
	pair() : first(), second() {}

    // initialization
	pair(const T1 &x, const T2 &y) :
    first(x), second(y) {}

    // copy
	template <class U1, class U2> pair(const pair<U1, U2> &p)
    : first(p.first), second(p.second) {}

    pair& operator=( const pair& other )
    {
        this->first = other.first;
        this->second = other.second;
        return *this;
    }
}; // class pair

template< class T1, class T2 >
pair<T1, T2> make_pair( T1 t, T2 u )
{
    return (pair<T1, T2>(t, u));
}

template< class T1, class T2 >
bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template< class T1, class T2 >
bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (!(lhs == rhs));
}

template< class T1, class T2 >
bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (lhs.first < rhs.first || (lhs.first == rhs.first && lhs.second < rhs.second));
}

template< class T1, class T2 >
bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (!(lhs > rhs));
}

template< class T1, class T2 >
bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (lhs.first > rhs.first || (lhs.first == rhs.first && lhs.second > rhs.second));
}

template< class T1, class T2 >
bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs )
{
    return (!(lhs < rhs));
}

}; // namespace ft

#endif // __PAIR_H__
