/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:21:20 by gleal             #+#    #+#             */
/*   Updated: 2022/12/04 00:51:37 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

Node::Node(int nbr, Node *parent)
    : data(nbr), parent(parent), left(NULL), right(NULL)
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

void RedBlackTree::print(Node *ptr, const std::string &side, const std::string &depth)
{
	if (ptr != NULL)
	{
		print(ptr->left, "LEFT", (depth + "    "));
		std::cout << depth << side << " " << ptr->data << std::endl;
		print(ptr->right, "RIGHT", (depth + "    "));
	}
}