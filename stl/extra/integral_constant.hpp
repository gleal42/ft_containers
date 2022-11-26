/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integral_constant.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:21:20 by gleal             #+#    #+#             */
/*   Updated: 2022/11/26 17:21:31 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGRAL_CONSTANT_HPP
# define INTEGRAL_CONSTANT_HPP

namespace ft
{
template <class T, T v> struct integral_constant
{
    static const T value = v;
    typedef T value_type;
    typedef integral_constant<T, v> type;
};
}; // namespace ft

#endif
