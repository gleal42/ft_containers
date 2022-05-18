/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:37:46 by gleal             #+#    #+#             */
/*   Updated: 2022/05/17 19:54:07 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include "ft.hpp"

template<typename T>
class MutantStack : public ft::stack<T>
{
    public:
        MutantStack() {}
        MutantStack(const MutantStack<T>& src) { *this = src; }
        MutantStack<T>& operator=(const MutantStack<T>& rhs) 
        {
            this->c = rhs.c;
            return *this;
        }
        ~MutantStack() {}

        typedef typename ft::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

#endif
