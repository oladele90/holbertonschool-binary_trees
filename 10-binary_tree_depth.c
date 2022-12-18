#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a  binary tree
 * @tree : pointer to the root node of the tree to measure the depht
 * Return: depth of tree or 0 if tree is null
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	unsigned int i = 0;

	if (!tree)
		return (0);
	if (tree && tree->parent)
		i = 1 + binary_tree_depth(tree->parent);
	return (i);
}
