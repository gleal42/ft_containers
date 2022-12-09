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

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
	enum Color
	{
		BLACK,
		RED
	};

	Color clr;
	Node(int nbr, Node *parent);
};

struct RedBlackTree
{
	RedBlackTree();
	~RedBlackTree();
	Node *root;
	void add_node(int nbr);
	Node *find_node(int nbr);
	void print(Node *ptr, const std::string &side,
		   const std::string &depth);
	void left_rotate(Node *old);
	void right_rotate(Node *old);
	void fix_insert(Node *inserted);
	void fix_insert(Node **ptr, Node *uncle, bool is_opposite_parent,
			      void (RedBlackTree::*grandparent_rot)(Node *),
			      void (RedBlackTree::*parent_rot)(Node *));
	Node::Color getColour(Node *node);
	void setColour(Node *node, Node::Color clr);
};

void test_red_black_tree();

#endif // __REDBLACKTREE_H__
