/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:12:09 by gleal             #+#    #+#             */
/*   Updated: 2022/12/02 22:48:38 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"
#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) {
	(void)argc;
	(void)argv;
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);
	test_stack();
	test_vector();
	test_red_black_tree();
	test_pair();
	test_map();
	test_rebind();
	
	return (0);
}
