/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:55 by gleal             #+#    #+#             */
/*   Updated: 2022/05/17 02:18:08 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

#include "all.hpp"

/* 
    Requirements to be added:
    1 - It will use your vector class as default underlying container (Still need
    to change)
    2 - Reference and Const reference not clear if 98
*/

namespace ft
{
    template<class T, class Container = std::deque<T> > class stack
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
            explicit stack( const Container& cont = Container() );
            stack( const stack& other );
            ~stack();
            stack& operator=( const stack& other );
            reference top();
            const_reference top() const;
            bool empty() const;
            size_type size() const;
            void push( const value_type& value );
            void pop();
/* ----------------------------- Member Objects ----------------------------- */
            protected:
                Container c;
    };
    template< class T, class Container >
    bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
    template< class T, class Container >
    bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
    template< class T, class Container >
    bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
    template< class T, class Container >
    bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
    template< class T, class Container >
    bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
    template< class T, class Container >
    bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
};

#endif
