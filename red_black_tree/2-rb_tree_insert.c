#include "rb_trees.h"


/**
 * rb_tree_get_uncle - retrieves sibling of node parent in RBT
 *
 * @n: starting node
 * Return: pointer to uncle node, or NULL if parent or grandparent missing
 */
rb_tree_t *rb_tree_get_uncle(rb_tree_t *n)
{
	rb_tree_t *p = n ? n->parent : NULL;

	/* No parent or grandparent means no uncle */
	if (!p || !p->parent)
		return (NULL);

	if (p == p->parent->left)
		return (p->parent->right);

	return (p->parent->left);
}

/**
 * rb_tree_rotate_left - left child of root becomes new root, tree rotated
 * so it retains BST ordering of values (in-order traversal of leaves is same)
 *
 * @tree: tree to left rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *tree)
{
	rb_tree_t *pivot = NULL;

	if (!tree)
		return (NULL);

	/* pivot will become new root */
	pivot = tree->right;

	/* migrate children to keep BST order */
	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	/* handle upstream connections if `tree` is a subtree */
	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->left)
			tree->parent->left = pivot;
		else
			tree->parent->right = pivot;
	}

	/* finally rotate pivot into root postion */
	pivot->left = tree;
	tree->parent = pivot;

	return (pivot);
}


/**
 * rb_tree_rotate_right - R child of root becomes new root, tree rotated
 * so it retains BST ordering of values (in-order traversal of leaves is same)
 *
 * @tree: tree to right rotate
 * Return: pointer to new root node, or NULL if `root` is NULL
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *tree)
{
	rb_tree_t *pivot = NULL;

	if (!tree)
		return (NULL);

	/* pivot will become new root */
	pivot = tree->left;

	/* migrate children to keep BST order */
	tree->left = pivot->right;
	if (pivot->right)
		pivot->right->parent = tree;

	/* handle upstream connections if `tree` is a subtree */
	pivot->parent = tree->parent;
	if (tree->parent)
	{
		if (tree == tree->parent->right)
			tree->parent->right = pivot;
		else
			tree->parent->left = pivot;
	}

	/* finally rotate pivot into root postion */
	pivot->right = tree;
	tree->parent = pivot;

	return (pivot);
}

