#include "binary_trees.h"

/**
* binary_tree_rotate_left - balances tree by rotating left
* @tree: tree to balance
* Return: pointer to tree
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *templ = NULL;

	if (!tree)
		return (tree);
	temp = tree;
	tree = tree->right;
	if (tree->left)
		templ = tree->left;
	else
		templ = NULL;
	tree->left = temp;
	temp->parent = tree;
	temp->right = templ;
	if (templ)
		templ->parent = temp;
	tree->parent = NULL;
	return (tree);
}
