/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 22:39:10 by gleal             #+#    #+#             */
/*   Updated: 2022/05/17 18:44:30 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HPP
# define FT_HPP

#ifndef FT
# define FT 0
#endif

#if FT
	#include <map.hpp>
	#include <stack.hpp>
	#include <vector.hpp>
#else
	#include <map>
	#include <stack>
	#include <vector>
	namespace ft = std;
#endif

#endif
