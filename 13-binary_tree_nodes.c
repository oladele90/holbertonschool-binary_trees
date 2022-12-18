#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes in a binary tree with at least 1 kid
 * @tree: pointer to the root node of the tree to count the number of nodes
 * Return: number of parents or 0 if tree is null
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int i = 0;

	if (!tree)
		return (0);
	i += binary_tree_nodes(tree->left);
	i += binary_tree_nodes(tree->right);
	if (tree->left || tree->right)
		i += 1;
	return (i);
}
