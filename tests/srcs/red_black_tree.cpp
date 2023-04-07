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
#include <utility>

void test_red_black_tree()
{
	std::less<int> cmp;
	RedBlackTree<ft::pair<int, int>, std::less<int>, std::allocator<int> > tree(cmp);
	tree.find_add_node_is_in_tree(ft::pair<int, int>(5, 5));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(2, 2));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(10, 10));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(8, 8));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(12, 12));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(6, 6));
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.find_add_node_is_in_tree(ft::pair<int, int>(9, 9));
	tree.print(tree.root, "ROOT", "");

	std::cout << "After 2 comes [" << tree.find_node(2)->next()->data.first
		  << "]\n";
	std::cout << "Before 5 comes [" << tree.find_node(5)->prev()->data.first
		  << "]\n";
	std::cout << "After 5 comes [" << tree.find_node(5)->next()->data.first
		  << "]\n";
	std::cout << "Before 6 comes [" << tree.find_node(6)->prev()->data.first
		  << "]\n";
	std::cout << "After 6 comes [" << tree.find_node(6)->next()->data.first
		  << "]\n";
	std::cout << "Before 8 comes [" << tree.find_node(8)->prev()->data.first
		  << "]\n";
	std::cout << "After 8 comes [" << tree.find_node(8)->next()->data.first
		  << "]\n";
	std::cout << "Before 9 comes [" << tree.find_node(9)->prev()->data.first
		  << "]\n";
	std::cout << "After 9 comes [" << tree.find_node(9)->next()->data.first
		  << "]\n";
	std::cout << "Before 10 comes [" << tree.find_node(10)->prev()->data.first
		  << "]\n";
	std::cout << "After 10 comes [" << tree.find_node(10)->next()->data.first
		  << "]\n";
	std::cout << "Before 12 comes [" << tree.find_node(12)->prev()->data.first
		  << "]\n";

	std::cout << "\n\nABOUT TO DELETE 5\n\n";
	tree.delete_node(5);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	std::cout << "\n\nABOUT TO DELETE 2\n\n";
	tree.delete_node(2);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.delete_node(10);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.delete_node(8);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.delete_node(12);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	tree.delete_node(6);
	tree.print(tree.root, "ROOT", "");
	std::cout << "\n\n";
	// std::cout << "TO DELETE IS " << ptr->data.first << std::endl;
	tree.delete_node(9);
	// tree.print(tree.root, "ROOT", "");

	return;
}
