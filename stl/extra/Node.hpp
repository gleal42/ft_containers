#ifndef __NODE_H__
#define __NODE_H__

// int data will be replaced by ft_pair
template <typename T> struct Node
{
	T data;
	Node *parent;
	Node *left;
	Node *right;
	enum Color
	{
		BLACK,
		RED
	};
	Color clr;

	Node(T nbr, Node *parent)
	    : data(nbr), parent(parent), left(NULL), right(NULL), clr(RED)
	{
	}

	Node<T> *minimum_subtree()
	{
		Node<T> *ptr = this;
		while (ptr->left != NULL)
		{
			ptr = ptr->left;
		}
		return ptr;
	}

	Node<T> *maximum_subtree()
	{
		Node<T> *ptr = this;
		bool has_end = is_far_right(ptr);
		if (ptr->right == NULL)
			return ptr;
		if (has_end)
		{
			while (ptr->right->right != NULL)
			{
				ptr = ptr->right;
			}
		} else
		{
			while (ptr->right != NULL)
			{
				ptr = ptr->right;
			}
		}
		return ptr;
	}
	
	bool is_far_right(Node<T> *ptr)
	{
		while (ptr->parent != NULL)
		{
			if (ptr == ptr->parent->left)
				return false;
			ptr = ptr->parent;
		}
		return true;
	}

	Node<T> *prev()
	{
		if (this->left != NULL)
			return this->left->maximum_subtree();
		Node<T> *ptr = this;
		Node<T> *ptr_parent = ptr->parent;
		while (ptr_parent != NULL &&
		       ptr == ptr_parent->left)
		{
			ptr = ptr_parent;
			ptr_parent = ptr->parent;
		}
		return parent;
	}

	const Node<T> *const_prev() const
	{
		if (this->left != NULL)
			return this->left->maximum_subtree();
		const Node<T> *ptr = this;
		const Node<T> *ptr_parent = ptr->parent;
		while (ptr_parent != NULL &&
		       ptr == ptr_parent->left)
		{
			ptr = ptr_parent;
			ptr_parent = ptr->parent;
		}
		return parent;
	}

	Node<T> *next()
	{
		if (this->right != NULL)
			return this->right->minimum_subtree();
		Node<T> *ptr = this;
		Node<T> *ptr_parent = ptr->parent;
		while (ptr_parent != NULL && ptr == ptr_parent->right)
		{
			ptr = ptr_parent;
			ptr_parent = ptr->parent;
		}
		return ptr_parent;
	}
	const Node<T> *const_next() const
	{
		if (this->right != NULL)
			return this->right->minimum_subtree();
		const Node<T> *ptr = this;
		const Node<T> *ptr_parent = ptr->parent;
		while (ptr_parent != NULL && ptr == ptr_parent->right)
		{
			ptr = ptr_parent;
			ptr_parent = ptr->parent;
		}
		return ptr_parent;
	}
};

#endif // __NODE_H__