/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   false_type.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 00:22:54 by gleal             #+#    #+#             */
/*   Updated: 2022/06/06 00:23:29 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FALSE_TYPE_HPP
# define FALSE_TYPE_HPP

#include "integral_constant.hpp"

namespace ft
{
    typedef integral_constant<bool,false> false_type;
};

#endif
