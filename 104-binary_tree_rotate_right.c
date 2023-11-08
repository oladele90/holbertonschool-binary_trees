#include "binary_trees.h"

/**
* binary_tree_rotate_right - balances tree by rotating right
* @tree: tree to balance
* Return: pointer to tree
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *temp = NULL, *tempr = NULL;

	if (!tree)
		return (tree);
	temp = tree;
	tree = tree->left;
	if (tree->right)
		tempr = tree->right;
	else
		tempr = NULL;
	tree->right = temp;
	temp->parent = tree;
	temp->left = tempr;
	if (tempr)
		tempr->parent = temp;
	tree->parent = NULL;
	return (tree);
}

/**
* avl_tree_rotate_right - balances tree by rotating right
* @tree: tree to balance
* Return: pointer to tree
*/
avl_t *avl_tree_rotate_left(avl_t *tree)
{
	avl_t *old = NULL, *new = NULL;

	if (!tree || !tree->left)
		return (tree);
	old = tree;
	new = tree->left;
	old->parent = new;
	if (!new->right)
	{
		new->right = old;
		new->parent = NULL;
		return (new);
	}
	old->left = new->right;
	old->left->parent = old;
	new->right = old;
	new->parent = NULL;
	return (new);
}