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

