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
avl_t *avl_tree_rotate_right(avl_t *tree)
{
	avl_t *old = NULL, *new = NULL, *temp = NULL;

	if (!tree || !tree->left)
		return (tree);
	old = tree;
	new = tree->left;
	if (old->parent)
	{
		if (old == old->parent->right)
			old->parent->right = new;
		else
			old->parent->left = new;
		temp = old->parent;
	}
	old->parent = new;
	if (new->right)
	{
		old->left = new->right;
		new->right->parent = old;
	}
	old->left = NULL;
	new->right = old;
	new->parent = temp;
	return (new);
}