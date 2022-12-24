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
		fix_insert(root);
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
				fix_insert(it->left);
				return;
			}
			it = it->left;
		} else if (nbr > it->data)
		{
			if (!it->right)
			{
				it->right = new Node(nbr, it);
				fix_insert(it->right);
				return;
			}
			it = it->right;
		} else
			return;
	}
}

void RedBlackTree::delete_node(int nbr)
{
	Node *to_delete = find_node(nbr);
	if (to_delete == NULL)
		return;
	Node *y = to_delete;
	Node *x;
	Node::Color y_color = y->clr;
	if (to_delete->left == NULL)
	{ // case 1
		x = to_delete->right;
		transplant(to_delete, to_delete->right);
	} else if (to_delete->right == NULL)
	{ // case 2
		x = to_delete->left;
		transplant(to_delete, to_delete->left);
	} else // case 3
	{
		y = minimum(to_delete->right);
		y_color = y->clr;
		x = y->right;
		if (y->parent == to_delete)
		{
			if (x != NULL)
			{
				x->parent = y;
			}
		} else
		{
			transplant(y, y->right);
			y->right = to_delete->right;
			y->right->parent = y;
		}
		transplant(to_delete, y);
		y->left = to_delete->left;
		y->left->parent = y;
		y->clr = to_delete->clr;
	}
	delete to_delete;
	if (y_color == Node::BLACK && x != NULL)
	{
		fix_delete(x);
	}
}

void RedBlackTree::transplant(Node *spot, Node *sub_tree)
{
	if (spot->parent == NULL)
		root = sub_tree;
	else if (spot == spot->parent->left)
	{
		spot->parent->left = sub_tree;
	} else
	{
		spot->parent->right = sub_tree;
	}
	if (sub_tree != NULL)
	{
		sub_tree->parent = spot->parent;
	}
}

void RedBlackTree::print(Node *ptr, const std::string &side,
			 const std::string &depth)
{
	if (ptr != NULL)
	{
		print(ptr->right, "RIGHT", (depth + "         "));
		std::cout << depth << (ptr != root ? ptr->parent->data : 0)
			  << "->" << side << " [" << ptr->data << "] "
			  << (ptr->clr ? "red" : "blk") << std::endl;
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

Node *RedBlackTree::minimum(Node *ptr)
{
	while (ptr->left != NULL)
	{
		ptr = ptr->left;
	}
	return ptr;
}

void RedBlackTree::fix_delete(Node *to_fix)
{
	while (to_fix != root && to_fix->clr == Node::BLACK)
	{
		if (to_fix == to_fix->parent->left)
		{
			Node *sibling = to_fix->parent->right;
			// case 1
			if (sibling->clr == Node::RED)
			{
				sibling->clr = Node::BLACK;
				to_fix->parent->clr = Node::RED;
				left_rotate(to_fix->parent);
				sibling = to_fix->parent->right;
			}
			// case 2
			if (sibling->left->clr == Node::BLACK &&
			    sibling->right->clr == Node::BLACK)
			{
				sibling->clr = Node::RED;
				to_fix = to_fix->parent;
			} else
			{
				// case 3
				if (sibling->right->clr == Node::BLACK)
				{
					sibling->left->clr = Node::BLACK;
					sibling->clr = Node::RED;
					right_rotate(sibling);
					sibling = to_fix->parent->right;
				}
				// case 4
				sibling->clr = to_fix->parent->clr;
				to_fix->parent->clr = Node::BLACK;
				sibling->right->clr = Node::BLACK;
				left_rotate(to_fix->parent);
				to_fix = root;
			}
		} else
		{
			Node *sibling = to_fix->parent->left;
			// case 1
			if (sibling->clr == Node::RED)
			{
				sibling->clr = Node::BLACK;
				to_fix->parent->clr = Node::RED;
				right_rotate(to_fix->parent);
				sibling = to_fix->parent->left;
			}
			// case 2
			if (sibling->right->clr == Node::BLACK &&
			    sibling->left->clr == Node::BLACK)
			{
				sibling->clr = Node::RED;
				to_fix = to_fix->parent;
			} else
			{
				// case 3
				if (sibling->left->clr == Node::BLACK)
				{
					sibling->right->clr = Node::BLACK;
					sibling->clr = Node::RED;
					right_rotate(sibling);
					sibling = to_fix->parent->left;
				}
				// case 4
				sibling->clr = to_fix->parent->clr;
				to_fix->parent->clr = Node::BLACK;
				sibling->left->clr = Node::BLACK;
				right_rotate(to_fix->parent);
				to_fix = root;
			}
		}
	}
	to_fix->clr = Node::BLACK;
}