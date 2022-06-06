/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 22:02:42 by gleal             #+#    #+#             */
/*   Updated: 2022/06/06 01:04:44 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

#include "true_type.hpp"
#include "false_type.hpp"

namespace ft
{
    
    template<typename> struct is_integral_base: false_type {};
    template<> struct is_integral_base<bool>: true_type {};
    template<> struct is_integral_base<char>: true_type {};
    template<> struct is_integral_base<signed char>: true_type {};
    template<> struct is_integral_base<short int>: true_type {};
    template<> struct is_integral_base<int>: true_type {};
    template<> struct is_integral_base<long int>: true_type {};
    template<> struct is_integral_base<long long int>: true_type {};
    template<> struct is_integral_base<unsigned char>: true_type {};
    template<> struct is_integral_base<unsigned short int>: true_type {};
    template<> struct is_integral_base<unsigned int>: true_type {};
    template<> struct is_integral_base<unsigned long int>: true_type {};
    template<> struct is_integral_base<unsigned long long int>: true_type {};
    
    template< class T > struct remove_cv                   { typedef T type; };
    template< class T > struct remove_cv<const T>          { typedef T type; };
    template< class T > struct remove_cv<volatile T>       { typedef T type; };
    template< class T > struct remove_cv<const volatile T> { typedef T type; };
    
    template<typename T> struct is_integral: is_integral_base<typename remove_cv<T>::type> {};
};

#endif
