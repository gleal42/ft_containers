/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:34:55 by gleal             #+#    #+#             */
/*   Updated: 2022/05/18 18:50:32 by gleal            ###   ########.fr       */
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
            // ~stack();
            stack& operator=( const stack& other );
            reference top();
            const_reference top() const;
            bool empty() const;
            size_type size() const;
            void push( const value_type& value );
            void pop();
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

    template<class T, class Container>
    stack<T, Container>::stack(const Container& cont) : c(cont)
    {
    }

    template<class T, class Container>
    stack<T, Container>::stack( const stack& other ) : c(other.c)
    {
    }

    template<class T, class Container>
    stack<T, Container>& stack<T, Container>::operator=( const stack<T, Container> &other)
    {
        this->c=other.c;
    }

    template<class T, class Container>
    typename stack<T, Container>::reference stack<T, Container>::top()
    {
        // std::cout << "ref_top" << std::endl;
        return (this->c.back());
    }

    template<class T, class Container>
    typename stack<T, Container>::const_reference stack<T, Container>::top() const
    {
        // std::cout << "cref_top" << std::endl;
        return (this->c.back());
    }

    template<class T, class Container>
    void stack<T, Container>::push(const value_type& value)
    {
        this->c.push_back(value);
    }


    template<class T, class Container>
    bool stack<T, Container>::empty() const
    {
        return (this->c.empty());
    }

    template<class T, class Container>
    typename stack<T, Container>::size_type stack<T, Container>::size() const
    {
        return (this->c.size());
    }

    template<class T, class Container>
    void stack<T, Container>::pop()
    {
        this->c.pop_back();
    }

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
