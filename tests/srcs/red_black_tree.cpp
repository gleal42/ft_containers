/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/12/04 01:40:26 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

void test_red_black_tree()
{
	RedBlackTree tree;
	tree.add_node(5);

	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(2);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(10);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(8);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(12);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(6);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.add_node(9);
	tree.print(tree.root, "ROOT", "");


 
	std::cout << "\n\nABOUT TO DELETE\n\n";
	// tree.delete_node(5);
	// tree.print(tree.root, "ROOT", "");
	// std::cout << "\n\n";
	// tree.delete_node(2);
	// tree.print(tree.root, "ROOT", "");
	// std::cout << "\n\n";
	// tree.delete_node(10);
	// tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.delete_node(8);
	tree.print(tree.root, "ROOT", "");
	// std::cout << "\n\n";
	// tree.delete_node(12);
	// tree.print(tree.root, "ROOT", "");
	// std::cout << "\n\n";
	// tree.delete_node(6);
	// tree.print(tree.root, "ROOT", "");
	// std::cout << "\n\n";
	// tree.delete_node(9);
	// tree.print(tree.root, "ROOT", "");

	return ;
}