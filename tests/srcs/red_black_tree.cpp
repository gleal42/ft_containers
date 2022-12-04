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
	tree.add_node(2);
	tree.add_node(10);
	tree.add_node(8);
	tree.add_node(12);
	tree.add_node(6);
	tree.add_node(9);
	tree.print(tree.root, "ROOT", "");
	tree.left_rotate(tree.root);
	std::cout << "_________________________" << std::endl;
	tree.print(tree.root, "ROOT", "");
	std::cout << "_________________________" << std::endl;
	tree.right_rotate(tree.root);
	tree.print(tree.root, "ROOT", "");
	return ;
}