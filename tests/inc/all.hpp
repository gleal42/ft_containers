/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:35:51 by gleal             #+#    #+#             */
/*   Updated: 2022/12/02 22:48:01 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALL_HPP
# define ALL_HPP

#include <iostream>
#include <string>
#include <deque>

#include "ft.hpp"
#include "utils.hpp"
#include "MutantStack.hpp"

#include <stdlib.h>
#include <typeinfo>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096

struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};

std::ostream & operator << (std::ostream &os, const Buffer &buf);

#define COUNT (MAX_RAM / (int)sizeof(Buffer))

void    test_stack();
int    	test_vector();
void	test_pair();

#ifdef DEBUG
#define LOG( x ) std::cout << x
#else
#define LOG( x ) 
#endif


#endif
