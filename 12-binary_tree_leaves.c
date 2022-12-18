#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: pointer to the root node of the tree to count the number of leaves
 * Return: number of leaves or 0 if tree is null
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int i = 0;

	if (!tree)
		return (0);
	i += binary_tree_leaves(tree->left);
	i += binary_tree_leaves(tree->right);
	if (!tree->left && !tree->right)
		return (1);
	return (i);
}
