/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:21:20 by gleal             #+#    #+#             */
/*   Updated: 2022/12/02 23:44:28 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RedBlackTree.hpp"

Node::Node(int nbr, Node *parent)
    : data(nbr), parent(parent), left(NULL), right(NULL)
{}

RedBlackTree::RedBlackTree() : root(NULL) {}

void RedBlackTree::add_node(int nbr)
{
	Node *it = root;
	Node *parent = NULL;
	while (it != NULL)
	{
		if (nbr < it->data)
		{
			if (!it->left)
			{
				parent = it;
			}
			it = it->left;
		} else if (nbr < it->data)
		{
			it = it->right;
		} else
			break;
	}
	if (it == NULL)
	{
		Node *nd = new Node(nbr, it);
		nd->parent = parent;
	}
}

void    RedBlackTree::print()
{

}