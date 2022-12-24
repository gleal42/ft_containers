/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:17:15 by gleal             #+#    #+#             */
/*   Updated: 2022/12/04 01:40:38 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REDBLACKTREE_H__
#define __REDBLACKTREE_H__

#include <cstddef>
#include <iostream>

#include "Node.hpp"

struct RedBlackTree
{
	RedBlackTree();
	~RedBlackTree();
	Node *root;

	Node *find_node(int nbr);
	Node *minimum(Node *ptr);
	Node *maximum(Node *ptr); // TODO
	Node *previous(Node *ptr); // TODO
	Node *next(Node *ptr); // TODO
	Node::Color getColour(Node *node);
	void setColour(Node *node, Node::Color clr);

	void add_node(int nbr);
	void delete_node(int nbr);
	void transplant(Node *spot, Node *sub_tree);
	void print(Node *ptr, const std::string &side,
		   const std::string &depth);
	void left_rotate(Node *old);
	void right_rotate(Node *old);
	void fix_insert(Node *inserted);
	void fix_insert(Node **ptr, Node *uncle, bool is_opposite_parent,
			      void (RedBlackTree::*grandparent_rot)(Node *),
			      void (RedBlackTree::*parent_rot)(Node *));
	void fix_delete(Node *inserted);
};

void test_red_black_tree();

#endif // __REDBLACKTREE_H__
