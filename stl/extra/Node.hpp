#ifndef __NODE_H__
#define __NODE_H__

// int data will be replaced by ft_pair

template<typename T>
struct Node
{
	T data;
	Node *parent;
	Node *last;
	Node *left;
	Node *right;
	enum Color
	{
		BLACK,
		RED
	};
	Color clr;

	Node(T nbr, Node *parent, Node *last)
    : data(nbr), parent(parent), last(last), left(NULL), right(NULL), clr(RED)
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
		while (ptr->right != NULL)
		{
			ptr = ptr->right;
		}
		return ptr;
	}

	Node<T> *prev()
	{
		if (this->left != NULL)
			return this->left->maximum_subtree();
		Node<T> *ptr = this;
		Node<T> *ptr_parent = ptr->parent;
		while (ptr_parent != NULL && ptr == ptr_parent->left)
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
		if (ptr_parent == NULL)
			return ptr->last;
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
		if (ptr_parent == NULL)
			return ptr->last;
		return ptr_parent;
	}
};

#endif // __NODE_H__