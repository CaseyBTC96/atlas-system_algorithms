#include "rb_trees.h"

/* INT_MIN */
#include <limits.h>


/**
 * max_size_t - finds larger of two size_t values
 *
 * @a: first value to compare
 * @b: second value to compare
 * Return: larger size_t value, or value of both if equal
 */
size_t max_size_t(size_t a, size_t b)
{
	return ((a > b) ? a : b);
}


/**
 * RBT_check_black_height - recursively tests if binary tree has Red-Black Tree
 * property of equal number of black nodes between any leaf and root
 * note: black height of a NULL leaf is defined to be 1
 *
 * @tree: root node from which to measure, starting at 0
 * Return: levels from root, or 0 if `tree` is NULL
 */
size_t RBT_check_black_height(const rb_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->color == BLACK)
		return (1 + max_size_t(RBT_check_black_height(tree->left),
				       RBT_check_black_height(tree->right)));
	else
		return (max_size_t(RBT_check_black_height(tree->left),
				   RBT_check_black_height(tree->right)));
}
