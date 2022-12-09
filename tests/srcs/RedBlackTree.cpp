/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:21:20 by gleal             #+#    #+#             */
/*   Updated: 2022/12/04 01:45:39 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

Node::Node(int nbr, Node *parent)
    : data(nbr), parent(parent), left(NULL), right(NULL), clr(RED)
{}

RedBlackTree::RedBlackTree() : root(NULL) {}

RedBlackTree::~RedBlackTree()
{
	Node **it = &root;
	if (root == NULL)
		return;

	while (root->left != NULL || root->right != NULL)
	{
		it = &root;
		while ((*it)->left != NULL || (*it)->right != NULL)
		{
			while ((*it)->left != NULL)
			{
				it = &(*it)->left;
			}
			while ((*it)->right != NULL)
			{
				it = &(*it)->right;
			}
		}
		delete *it;
		*it = NULL;
	}
	delete root;
	root = NULL;
}

void RedBlackTree::add_node(int nbr)
{
	if (root == NULL)
	{
		root = new Node(nbr, NULL);
		return;
	}
	Node *it = root;
	while (it != NULL)
	{
		if (nbr < it->data)
		{
			if (!it->left)
			{
				it->left = new Node(nbr, it);
				return;
			}
			it = it->left;
		} else if (nbr > it->data)
		{
			if (!it->right)
			{
				it->right = new Node(nbr, it);
				return;
			}
			it = it->right;
		} else
			return;
	}
}

void RedBlackTree::print(Node *ptr, const std::string &side,
			 const std::string &depth)
{
	if (ptr != NULL)
	{
		print(ptr->right, "RIGHT", (depth + "         "));
		std::cout << depth
			  << (ptr != root ? ptr->parent->data : 0)
			  << "->" 
			  << side << " [" << ptr->data << "] "
			  << (ptr->clr ? "red" : "blk")
			  << std::endl;
		print(ptr->left, "LEFT", (depth + "         "));
	}
}

void RedBlackTree::left_rotate(Node *x)
{
	Node *y = x->right;
	x->right = y->left;
	if (y->left != NULL)
	{
		y->left->parent = x;
	}
	y->parent = x->parent;
	if (x->parent == NULL)
	{
		root = y;
	} else if (x == x->parent->left)
	{
		x->parent->left = y;
	} else
	{
		x->parent->right = y;
	}
	y->left = x;
	x->parent = y;
}

void RedBlackTree::right_rotate(Node *old)
{
	Node *new_base = old->left;
	old->left = new_base->right;
	if (new_base->right != NULL)
	{
		new_base->right->parent = old;
	}
	new_base->parent = old->parent;
	if (old->parent == NULL)
	{
		root = new_base;
	} else if (old == old->parent->right)
	{
		old->parent->right = new_base;
	} else
	{
		old->parent->left = new_base;
	}
	new_base->right = old;
	old->parent = new_base;
}

void RedBlackTree::fix_insert(Node *ptr)
{
	while (getColour(ptr->parent) == Node::RED)
	{
		Node *parent = ptr->parent;
		Node *grand_parent = parent->parent;
		if (ptr->parent == grand_parent->left)
		{
			fix_insert(&ptr, grand_parent->right,
				   (ptr == parent->right),
				   &RedBlackTree::right_rotate,
				   &RedBlackTree::left_rotate);
		} else
		{
			fix_insert(&ptr, grand_parent->left,
				   (ptr == parent->left),
				   &RedBlackTree::left_rotate,
				   &RedBlackTree::right_rotate);
		}
	}
	root->clr = Node::BLACK; // Case  ptr =
}

void RedBlackTree::fix_insert(Node **ptr, Node *uncle, bool is_opposite_parent,
			      void (RedBlackTree::*grandparent_rot)(Node *),
			      void (RedBlackTree::*parent_rot)(Node *))
{
	Node *parent = (*ptr)->parent;
	Node *grandparent = parent->parent;
	if (getColour(uncle) == Node::RED) // Case 1
	{
		setColour(parent, Node::BLACK);
		setColour(uncle, Node::BLACK);
		setColour(grandparent, Node::RED);
		(*ptr) = grandparent;
	} else // Case 2 and 3
	{
		if (is_opposite_parent) // Case 2
		{
			(this->*parent_rot)(parent);
			(*ptr) = parent;
			parent = (*ptr)->parent;
			grandparent = parent->parent;
		}
		// Case 3
		setColour(parent, Node::BLACK);
		setColour(grandparent, Node::RED);
		(this->*grandparent_rot)(grandparent);
	}
}

Node *RedBlackTree::find_node(int nbr)
{
	Node *it = root;
	while (it != NULL)
	{
		if (nbr < it->data)
		{
			it = it->left;
		} else if (nbr > it->data)
		{
			it = it->right;
		} else
			return it;
	}
	return it;
}

// void RedBlackTree::fix_insert_right_parent(Node *ptr)
// {
// 	Node *parent = ptr->parent;
// 	Node *grandparent = parent->parent;
// 	Node *uncle = grandparent->left;
// 	if (getColour(uncle) == Node::RED) // Case 1
// 	{
// 		setColour(parent, Node::BLACK);
// 		setColour(uncle, Node::BLACK);
// 		setColour(grandparent, Node::RED);
// 		left_rotate(grandparent);
// 		ptr = grandparent;
// 	} else // Case 2 and 3
// 	{
// 		if (ptr == parent->right) // Case 2
// 		{
// 			right_rotate(parent);
// 			ptr = parent;
// 			parent = ptr->parent;
// 			grandparent = parent->parent;
// 		}
// 		// Case 3
// 		SetColour(parent, Node::BLACK);
// 		SetColour(grandparent, Node::RED);
// 		left_rotate(grandparent);
// 	}
// }

Node::Color RedBlackTree::getColour(Node *node)
{
	if (node)
		return node->clr;
	return Node::BLACK;
}

void RedBlackTree::setColour(Node *node, Node::Color clr)
{
	if (node)
		node->clr = clr;
}