/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:17:15 by gleal             #+#    #+#             */
/*   Updated: 2022/12/02 23:19:32 by gleal            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __REDBLACKTREE_H__
#define __REDBLACKTREE_H__

#include <cstddef>

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

    Node(int nbr, Node *parent);
};

struct RedBlackTree
{
    RedBlackTree();
    Node *root;
    void add_node(int nbr);
    void print();
};

void test_red_black_tree();

#endif // __REDBLACKTREE_H__

