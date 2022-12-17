#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree : pointer to the root node of the tree to measure the height
 * Return: height of tree or 0 if tree is null
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	unsigned int i = 0, j = 0;

	if (!tree)
		return (0);
	if (tree)
	{
		if (tree->left)
			i = 1 + binary_tree_height(tree->left);
		if (tree->right)
			j = 1 + binary_tree_height(tree->right);
		if (i >= j)
			return (i);
		return (j);
	}
	return (i);
}
