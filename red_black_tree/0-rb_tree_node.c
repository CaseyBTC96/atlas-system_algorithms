#include "rb_trees.h

/* malloc NULL */
#include <stdlib.h>

/* fprintf */
#include <stdio.h>

/**
 * rb_tree_node - creates a red-black binary tree node of struct `rb_tree_t`
 *
 * @parent: pointer to parent of node created
 * @value: integer stored in new node
 * @color: red-black polarity of new node
 * Return: pointer to new node
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
