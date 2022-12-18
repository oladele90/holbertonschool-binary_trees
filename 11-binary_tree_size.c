#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 * Return: size of tree or 0 if tree is null
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int i = 1;

	if (!tree)
		return (0);
	if (tree)
	{
		if (tree->left)
			i += binary_tree_size(tree->left);
		if (tree->right)
			i += binary_tree_size(tree->right);
	}
	return (i);
}
