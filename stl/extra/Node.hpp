#ifndef __NODE_H__
#define __NODE_H__

// int data will be replaced by ft_pair

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
	enum Color
	{
		BLACK,
		RED
	};

	Color clr;
	Node(int nbr, Node *parent);
};

#endif // __NODE_H__