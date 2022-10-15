/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_const.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:40:25 by ctw02485          #+#    #+#             */
/*   Updated: 2022/10/15 15:51:37 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __IS_CONST_H__
#define __IS_CONST_H__

#include "true_type.hpp"
#include "false_type.hpp"

template<class T> struct is_const          : ft::false_type {};
template<class T> struct is_const<const T> : ft::true_type {};

#endif // __IS_CONST_H__
