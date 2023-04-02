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
#include "map_iterator.hpp"
#include "rebind.hpp"
#include "pair.hpp"

// TODO: remove last from node so that max_size() is correct

template <typename T, class Compare = std::less<typename T::first_type>,
	  typename Allocator = std::allocator<T> >
struct RedBlackTree
{
	typedef typename rebind<Allocator>::template to<Node<T> >::other
		    node_allocator;
	typedef typename node_allocator::pointer node_pointer;

	typedef ft::map_bidirectional_iterator<T> iterator;
	typedef ft::map_const_bidirectional_iterator<T> const_iterator;

	// Member types
	node_allocator _node_alloc;
	node_pointer root;
	node_pointer _end;
	Compare _cmp;

	RedBlackTree() : root(NULL), _cmp() { init(); }
	RedBlackTree(const Compare &cmp) : root(NULL), _cmp(cmp) { init(); }

	~RedBlackTree()
	{
		destroy_nodes();
		destroy_last();
	}

	void init()
	{
		_end = _node_alloc.allocate(1);
		_node_alloc.construct(_end, Node<T>(T(), NULL));
		_end->clr = Node<T>::BLACK;
	}
	void destroy_nodes()
	{
		Node<T> **it = &root;
		if (is_null(root))
		{
			return;
		}

		while (!is_null(root->left) || !is_null(root->right))
		{
			it = &root;
			while (!is_null((*it)->left) || !is_null((*it)->right))
			{
				while (!is_null((*it)->left))
				{
					it = &(*it)->left;
				}
				while (!is_null((*it)->right))
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
	}
	void destroy_last()
	{
		_node_alloc.destroy(_end);
		_node_alloc.deallocate(_end, 1);
		_end = NULL;
	}

	Node<T> *minimum(Node<T> *ptr)
	{
		if (ptr == NULL)
			return NULL;
		while (!is_null(ptr->left))
		{
			ptr = ptr->left;
		}
		return ptr;
	}

	Node<T> *maximum(Node<T> *ptr)
	{
		if (ptr == NULL)
			return NULL;
		while (!is_null(ptr->right))
		{
			ptr = ptr->right;
		}
		return ptr;
	}

	typename Node<T>::Color getColour(Node<T> *node)
	{
		if (!is_null(node))
			return node->clr;
		return Node<T>::BLACK;
	}

	void setColour(Node<T> *node, typename Node<T>::Color clr)
	{
		if (!is_null(node))
			node->clr = clr;
	}

	Node<T> *find_node(typename T::first_type nbr) const
	{
		Node<T> *it = root;
		while (!is_null(it))
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

	Node<T> *find_location_node(Node<T> *it, typename T::first_type nbr)
	{
		while (!is_null(it))
		{
			if (_cmp(nbr, it->data.first))
			{
				if (is_null(it->left))
					return it;
				it = it->left;
			} else if (_cmp(it->data.first, nbr))
			{
				if (is_null(it->right))
					return it;
				it = it->right;
			} else
				return it;
		}
		return it;
	}

	Node<T> *find_location_node(typename T::first_type nbr)
	{
		return find_location_node(root, nbr);
	}

	Node<T> *lower_bound( typename T::first_type key )
	{
		Node<T> *it = root;
		Node<T> *not_less = NULL;
		while (!is_null(it))
		{
			if (_cmp(key, it->data.first))
			{
				not_less = it;
				it = it->left;
			} else if (_cmp(it->data.first, key))
			{
				it = it->right;
			} else
				return it;
		}
		if (!not_less)
		{
			return _end;
		}
		return not_less;
	}
	const Node<T> *lower_bound( typename T::first_type key ) const
	{
		Node<T> *it = root;
		Node<T> *not_less = NULL;
		while (!is_null(it))
		{
			if (_cmp(key, it->data.first))
			{
				not_less = it;
				it = it->left;
			} else if (_cmp(it->data.first, key))
			{
				it = it->right;
			} else
				return it;
		}
		if (!not_less)
		{
			return _end;
		}
		return not_less;
	}

	Node<T> *upper_bound( typename T::first_type key )
	{
		Node<T> *it = root;
		Node<T> *not_less = NULL;
		while (!is_null(it))
		{
			if (_cmp(key, it->data.first))
			{
				not_less = it;
				it = it->left;
			} else if (_cmp(it->data.first, key))
			{
				it = it->right;
			} else
				break;
		}
		if (!not_less)
		{
			return _end;
		}
		return not_less;
	}
	const Node<T> *upper_bound( typename T::first_type key ) const
	{
		Node<T> *it = root;
		Node<T> *not_less = NULL;
		while (!is_null(it))
		{
			if (_cmp(key, it->data.first))
			{
				not_less = it;
				it = it->left;
			} else if (_cmp(it->data.first, key))
			{
				it = it->right;
			} else
				break;
		}
		if (!not_less)
		{
			return _end;
		}
		return not_less;
	}

	typename T::second_type &find_value_for_key(typename T::first_type key)
	{
		Node<T> *location = find_location_node(key);
		if (!is_null(location) && location->data.first == key)
		{
			return location->data.second;
		}
		return update_node(T(key, typename T::second_type()), location)->data.second;
	}

	ft::pair<Node<T> *,bool> find_add_node_is_in_tree(T node)
	{
		Node<T> *location = find_location_node(node.first);
		bool already_exists = false;
		if (!is_null(location) && location->data.first == node.first)
		{
			already_exists = true;
			if (location->data == node)
				return ft::make_pair(location, !already_exists);
		}
		return ft::make_pair(update_node(node, location), !already_exists);
	}

	// if check which find_nodes can be deleted
	// (get location from construct node)

	Node<T> * update_node(T nbr, Node<T> *location)
	{
		if (is_null(location))
		{
			root = _node_alloc.allocate(1);
			construct_node(root, nbr, NULL);
			update_end(root);
			return root;
		}
		if (_cmp(nbr.first, location->data.first))
		{
			location->left = _node_alloc.allocate(1);
			construct_node(location->left, nbr, location);
			return find_node(nbr.first);
		} else if (_cmp(location->data.first, nbr.first))
		{
			location->right = _node_alloc.allocate(1);
			construct_node(location->right, nbr, location);
			if (_cmp(_end->parent->data.first, nbr.first))
			{
				update_end(location->right);
			}
			return find_node(nbr.first);
		}
		return find_node(nbr.first);
	}

	// if hint is too low in subtrees we try to find location from root

	Node<T> * find_add_node_hint(iterator hint, const T& value)
	{
		Node<T> *location = find_location_node(hint.node_ptr, value.first);
		if (is_null(location) || location->data.first != value.first)
		{
			return(find_add_node_is_in_tree(value).first);
		}
		if (location != NULL && location->data == value)
		{
			return location;
		}
		return(update_node(value, location));
	}

	void update_end(Node<T> *last)
	{
		last->right = _end;
		_end->parent = last;
	}

	void	construct_node(Node<T> *location, T nbr, Node<T> *parent)
	{
		_node_alloc.construct(location, Node<T>(nbr, parent));
		fix_insert(location);
	}

	void delete_node(typename T::first_type nbr)
	{
		Node<T> *to_delete = find_node(nbr);
		if (is_null(to_delete))
			return;
		delete_node(to_delete);
	}

	void delete_node(iterator to_delete)
	{
		delete_node(to_delete.node_ptr);
	}
	void delete_node(const_iterator to_delete)
	{
		delete_node(to_delete.node_ptr);
	}

	// print(root, "ROOT", "");
	void delete_node(Node<T> * to_delete)
	{
		bool is_last_node = is_last(to_delete);
		Node<T> *new_last = NULL;
		if (is_last_node)
		{
			new_last = to_delete->prev();
		}
		Node<T> *y = to_delete;
		Node<T> *x;
		typename Node<T>::Color y_color = y->clr;
		if (is_null(to_delete->left))
		{ // case 1
			x = to_delete->right;
			transplant(to_delete, to_delete->right);
		} else if (is_null(to_delete->right))
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
				if (!is_null(x))
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
		if (is_last_node)
		{
			_end->parent = new_last;
			if (new_last)
			{
				new_last->right = _end;
			}
		}
		_node_alloc.destroy(to_delete);
		_node_alloc.deallocate(to_delete, 1);
		if (y_color == Node<T>::BLACK && !is_null(x))
		{
			fix_delete(x);
		}
	}

	void transplant(Node<T> *spot, Node<T> *sub_tree)
	{
		if (is_null(spot->parent))
			root = sub_tree;
		else if (spot == spot->parent->left)
		{
			spot->parent->left = sub_tree;
		} else
		{
			spot->parent->right = sub_tree;
		}
		if (!is_null(sub_tree))
		{
			sub_tree->parent = spot->parent;
		}
	}

	void print(Node<T> *ptr, const std::string &side,
		   const std::string &depth)
	{
		if (!is_null(ptr))
		{
			print(ptr->right, "RIGHT", (depth + "         "));
			std::cout << depth
				  << (ptr != root ? ptr->parent->data.first : 0)
				  << "->" << side << " [" << ptr->data.first
				  << "] " << (ptr->clr ? "red" : "blk")
				  << std::endl;
			print(ptr->left, "LEFT", (depth + "         "));
		}
	}

	void left_rotate(Node<T> *x)
	{
		Node<T> *y = x->right;
		x->right = y->left;
		if (!is_null(y->left))
		{
			y->left->parent = x;
		}
		y->parent = x->parent;
		if (is_null(x->parent))
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
		if (!is_null(new_base->right))
		{
			new_base->right->parent = old;
		}
		new_base->parent = old->parent;
		if (is_null(old->parent))
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

	bool is_null(const Node<T> *ptr) const
	{
		return (ptr == NULL || ptr == _end);
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

	iterator end() { return iterator(_end); }

	const_iterator end() const { return const_iterator(_end); }

	void swap (RedBlackTree& x)
	{
		node_allocator temp_node_alloc = this->_node_alloc;
		node_pointer temp_root = this->root;
		node_pointer temp_end = this->_end;
		Compare temp_cmp = this->_cmp;

		this->_node_alloc = x._node_alloc;
		this->root = x.root;
		this->_end = x._end;
		this->_cmp = x._cmp;

		x._node_alloc = temp_node_alloc;
		x.root = temp_root;
		x._end = temp_end;
		x._cmp = temp_cmp;
	}

	bool is_last(node_pointer ptr)
	{
		return (!is_null(root) && ptr == maximum(root));
	}
	bool empty() const { return (root == NULL); }
	size_t size() const { return (count(root)); }
	size_t count(node_pointer node) const
	{
		if (node == NULL || node == _end)
			return 0;
		return 1 + count(node->left) + count(node->right);
	}

	// https://42born2code.slack.com/archives/CMX2R5JSW/p1652788063716189
	size_t max_size() const { return (_node_alloc.max_size()); }
};

#endif // __REDBLACKTREE_H__
