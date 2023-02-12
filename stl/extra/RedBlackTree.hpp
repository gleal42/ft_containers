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
#include "rebind.hpp"
#include "map_iterator.hpp"


template <typename T, class Compare = std::less<typename T::first_type>, typename Allocator = std::allocator<T> >
struct RedBlackTree
{
	typedef typename rebind<Allocator>::template to<Node<T> >::other node_allocator;
	typedef typename node_allocator::pointer node_pointer;

	typedef ft::map_bidirectional_iterator<T> iterator;
	typedef ft::map_bidirectional_iterator<const T> const_iterator; // TODO: test
	
	// Member types
	node_allocator _node_alloc;
	node_pointer root;
	node_pointer _end;
	Compare _cmp;

	RedBlackTree() : root(NULL), _cmp()
	{
		init();
	}
	RedBlackTree(const Compare& cmp) : root(NULL), _cmp(cmp)
	{
		init();
	}

	~RedBlackTree()
	{
		destroy_all();
	}

	void init()
	{
		_end = _node_alloc.allocate(1);
		_node_alloc.construct(_end, Node<T>(T(), NULL, _end));
	}

	void	destroy_all()
	{
		Node<T> **it = &root;
		if (root == NULL)
		{
			_node_alloc.destroy(_end);
			_node_alloc.deallocate(_end, 1);
			_end = NULL;
			return;
		}

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
			_node_alloc.destroy(*it);
			_node_alloc.deallocate(*it, 1);
			*it = NULL;
		}
		_node_alloc.destroy(root);
		_node_alloc.deallocate(root, 1);
		root = NULL;
		_node_alloc.destroy(_end);
		_node_alloc.deallocate(_end, 1);
		_end = NULL;
	}

	Node<T> *find_node(typename T::first_type nbr)
	{
		Node<T> *it = root;
		while (it != NULL)
		{
			if (_cmp(nbr, it->data.first))
			{
				it = it->left;
			} else if (_cmp(it->data.first, nbr))
			{
				it = it->right;
			} else
				return it;
		}
		return it;
	}

	Node<T> *minimum(Node<T> *ptr)
	{
		if (ptr == NULL)
			return NULL;
		while (ptr->left != NULL)
		{
			ptr = ptr->left;
		}
		return ptr;
	}

	Node<T> *maximum(Node<T> *ptr)
	{
		while (ptr->right != NULL)
		{
			ptr = ptr->right;
		}
		return ptr;
	}

	typename Node<T>::Color getColour(Node<T> *node)
	{
		if (node)
			return node->clr;
		return Node<T>::BLACK;
	}

	void setColour(Node<T> *node, typename Node<T>::Color clr)
	{
		if (node)
			node->clr = clr;
	}

	void rbt_add_node(T nbr)
	{
		if (root == NULL)
		{
			root = _node_alloc.allocate(1);
			_node_alloc.construct(root, Node<T>(nbr, NULL, _end));
			fix_insert(root);
			return;
		}
		Node<T> *it = root;
		while (it != NULL)
		{
			if (_cmp(nbr.first, it->data.first))
			{
				if (!it->left)
				{
					it->left = _node_alloc.allocate(1);
					_node_alloc.construct(it->left, Node<T>(nbr, it, _end));
					fix_insert(it->left);
					return;
				}
				it = it->left;
			} else if (_cmp(it->data.first, nbr.first))
			{
				if (!it->right)
				{
					it->right = _node_alloc.allocate(1); 
					_node_alloc.construct(it->right, Node<T>(nbr, it, _end));
					fix_insert(it->right);
					return;
				}
				it = it->right;
			} else
				return;
		}
	}

	void rbt_delete_node(typename T::first_type nbr)
	{
		Node<T> *to_delete = find_node(nbr);
		if (to_delete == NULL)
			return;
		Node<T> *y = to_delete;
		Node<T> *x;
		typename Node<T>::Color y_color = y->clr;
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
		_node_alloc.destroy(to_delete);
		_node_alloc.deallocate(to_delete, 1);
		if (y_color == Node<T>::BLACK && x != NULL)
		{
			fix_delete(x);
		}
	}

	void add_node(T nbr)
	{
		rbt_add_node(nbr);
		update_end();
	}

	void delete_node(typename T::first_type nbr)
	{
		rbt_delete_node(nbr);
		update_end();
	}

	void transplant(Node<T> *spot, Node<T> *sub_tree)
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

	void print(Node<T> *ptr, const std::string &side,
		   const std::string &depth)
	{
		if (ptr != NULL)
		{
			print(ptr->right, "RIGHT", (depth + "         "));
			std::cout << depth
				  << (ptr != root ? ptr->parent->data.first : 0)
				  << "->" << side << " [" << ptr->data.first << "] "
				  << (ptr->clr ? "red" : "blk") << std::endl;
			print(ptr->left, "LEFT", (depth + "         "));
		}
	}

	void left_rotate(Node<T> *x)
	{
		Node<T> *y = x->right;
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

	void right_rotate(Node<T> *old)
	{
		Node<T> *new_base = old->left;
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

	void fix_insert(Node<T> *ptr)
	{
		while (getColour(ptr->parent) == Node<T>::RED)
		{
			Node<T> *parent = ptr->parent;
			Node<T> *grand_parent = parent->parent;
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
		root->clr = Node<T>::BLACK;
	}

	void fix_insert(Node<T> **ptr, Node<T> *uncle, bool is_opposite_parent,
			void (RedBlackTree::*grandparent_rot)(Node<T> *),
			void (RedBlackTree::*parent_rot)(Node<T> *))
	{
		Node<T> *parent = (*ptr)->parent;
		Node<T> *grandparent = parent->parent;
		if (getColour(uncle) == Node<T>::RED) // Case 1
		{
			setColour(parent, Node<T>::BLACK);
			setColour(uncle, Node<T>::BLACK);
			setColour(grandparent, Node<T>::RED);
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
			setColour(parent, Node<T>::BLACK);
			setColour(grandparent, Node<T>::RED);
			(this->*grandparent_rot)(grandparent);
		}
	}
	void fix_delete(Node<T> *to_fix)
	{
		while (to_fix != root && to_fix->clr == Node<T>::BLACK)
		{
			if (to_fix == to_fix->parent->left)
			{
				Node<T> *sibling = to_fix->parent->right;
				// case 1
				if (sibling->clr == Node<T>::RED)
				{
					sibling->clr = Node<T>::BLACK;
					to_fix->parent->clr = Node<T>::RED;
					left_rotate(to_fix->parent);
					sibling = to_fix->parent->right;
				}
				// case 2
				if (sibling->left->clr == Node<T>::BLACK &&
				    sibling->right->clr == Node<T>::BLACK)
				{
					sibling->clr = Node<T>::RED;
					to_fix = to_fix->parent;
				} else
				{
					// case 3
					if (sibling->right->clr ==
					    Node<T>::BLACK)
					{
						sibling->left->clr =
							    Node<T>::BLACK;
						sibling->clr = Node<T>::RED;
						right_rotate(sibling);
						sibling = to_fix->parent->right;
					}
					// case 4
					sibling->clr = to_fix->parent->clr;
					to_fix->parent->clr = Node<T>::BLACK;
					sibling->right->clr = Node<T>::BLACK;
					left_rotate(to_fix->parent);
					to_fix = root;
				}
			} else
			{
				Node<T> *sibling = to_fix->parent->left;
				// case 1
				if (sibling->clr == Node<T>::RED)
				{
					sibling->clr = Node<T>::BLACK;
					to_fix->parent->clr = Node<T>::RED;
					right_rotate(to_fix->parent);
					sibling = to_fix->parent->left;
				}
				// case 2
				if (sibling->right->clr == Node<T>::BLACK &&
				    sibling->left->clr == Node<T>::BLACK)
				{
					sibling->clr = Node<T>::RED;
					to_fix = to_fix->parent;
				} else
				{
					// case 3
					if (sibling->left->clr ==
					    Node<T>::BLACK)
					{
						sibling->right->clr =
							    Node<T>::BLACK;
						sibling->clr = Node<T>::RED;
						right_rotate(sibling);
						sibling = to_fix->parent->left;
					}
					// case 4
					sibling->clr = to_fix->parent->clr;
					to_fix->parent->clr = Node<T>::BLACK;
					sibling->left->clr = Node<T>::BLACK;
					right_rotate(to_fix->parent);
					to_fix = root;
				}
			}
		}
		to_fix->clr = Node<T>::BLACK;
	}

	iterator begin()
	{
		if (root == NULL)
			return iterator(_end);
		return iterator(root->minimum_subtree());
	}
	const_iterator begin() const
	{
		if (root == NULL)
			return const_iterator(_end);
		return const_iterator(root->minimum_subtree());
	}

	iterator end()
	{
		return iterator(_end);
	}

	const_iterator end() const
	{
		return const_iterator(_end);
	}

	void update_end()
	{
		if (root == NULL)
			_end->parent = NULL;
		else if (_end->parent != root->maximum_subtree())
		{
			_end->parent = root->maximum_subtree();
		}
	}
};

#endif // __REDBLACKTREE_H__
