/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 17:12:09 by gleal             #+#    #+#             */
/*   Updated: 2022/05/19 23:39:17 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.hpp"

#include <iostream>
#include <random>

int main(int argc, char** argv) {
	if (argc != 2)
	{
		std::cerr << "Usage: ./test seed" << std::endl;
		std::cerr << "Provide a seed please" << std::endl;
		std::cerr << "Count value:" << COUNT << std::endl;
		return 1;
	}
	const int seed = atoi(argv[1]);
	srand(seed);
	// test_stack();
	test_vector();
	
	return (0);
}
