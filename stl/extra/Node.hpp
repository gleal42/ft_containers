#ifndef __NODE_H__
#define __NODE_H__

// int data will be replaced by ft_pair

template<typename T>
struct Node
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
	Node(int nbr, Node *parent)
    : data(nbr), parent(parent), left(NULL), right(NULL), clr(RED)
	{
	}
};

#endif // __NODE_H__