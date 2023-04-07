/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:55 by gleal             #+#    #+#             */
/*   Updated: 2022/05/18 20:06:05 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

/* 
    2 - Reference and Const reference not clear if 98
*/

namespace ft
{
    template<class T, class Container = vector<T> > class stack
    {
        private:

        public:
    /* ------------------------------ Member Types ------------------------------ */
            typedef Container                               container_type;
            typedef typename Container::value_type          value_type;
            typedef typename Container::size_type           size_type;
            typedef typename Container::reference           reference;
            typedef typename Container::const_reference     const_reference;
    /* ---------------------------- Member Functions ---------------------------- */
            explicit stack( const Container& cont = Container() )
            : c(cont)
            {

            }
            stack( const stack& other )
             : c(other.c)
            {
            }
            ~stack()
            {
            }
            stack& operator=( const stack& other )
            {
                this->c=other.c;
            }
            reference top()
            {
                return (this->c.back());
            }
            const_reference top() const
            {
                return (this->c.back());
            }
            bool empty() const
            {
                return (this->c.empty());
            }
            size_type size() const
            {
                return (this->c.size());
            }
            void push( const value_type& value )
            {
                this->c.push_back(value);
            }
            void pop()
            {
                this->c.pop_back();
            }
    /* --------------------------------- Friends -------------------------------- */
            template<class T1, class Container1>
            friend bool operator==( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
            template<class T1, class Container1>
            friend bool operator!=( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
            template<class T1, class Container1>
            friend bool operator<( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
            template<class T1, class Container1>
            friend bool operator<=( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
            template<class T1, class Container1>
            friend bool operator>( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
            template<class T1, class Container1>
            friend bool operator>=( const stack<T1,Container1>& lhs, const stack<T1,Container1>& rhs );
    /* ----------------------------- Member Objects ----------------------------- */
            protected:
                Container c;
    };

    template< class T, class Container >
    bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c == rhs.c);
    }

    template< class T, class Container >
    bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c != rhs.c);
    }

    template< class T, class Container >
    bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c < rhs.c);
    }

    template< class T, class Container >
    bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c <= rhs.c);
    }

    template< class T, class Container >
    bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c > rhs.c);
    }

    template< class T, class Container >
    bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
    {
        return (lhs.c >= rhs.c);
    }

};

#endif
