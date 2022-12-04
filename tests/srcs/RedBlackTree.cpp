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
    : data(nbr), parent(parent), left(NULL), right(NULL), clr(BLACK)
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
		print(ptr->left, "LEFT", (depth + "    "));
		std::cout << depth << side << " " << ptr->data << " "
			  << (ptr->clr ? "red" : "blk") << " p: " << (ptr!=root?ptr->parent->data:0) << std::endl;
		print(ptr->right, "RIGHT", (depth + "    "));
	}
}

void RedBlackTree::left_rotate(Node *old)
{
	Node *new_base = old->right;
	old->right = new_base->left;
	if (new_base->left != NULL)
	{
		new_base->left->parent = old;
	}
	new_base->parent = old->parent;
	if (old->parent == NULL)
	{
		root = new_base;
	} else if (old == old->parent->left)
	{
		old->parent->left = new_base;
	} else
	{
		old->parent->right = new_base;
	}
	new_base->left = old;
	old->parent = new_base;
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