/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:42:39 by gleal             #+#    #+#             */
/*   Updated: 2022/12/04 00:40:38 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

void test_red_black_tree()
{
	RedBlackTree tree;
	tree.add_node(4);
	tree.add_node(3);
	tree.add_node(2);
	tree.add_node(7);
	tree.add_node(6);
	tree.add_node(10);
	tree.print(tree.root, "ROOT", "");
	return ;
}