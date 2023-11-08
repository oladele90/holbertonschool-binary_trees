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

/**
* avl_tree_rotate_left - balances tree by rotating left
* @tree: tree to balance
* Return: pointer to tree
*/
avl_t *avl_tree_rotate_left(avl_t *tree)
{
	avl_t *old = NULL, *new = NULL;

	if (!tree || !tree->right)
		return (tree);
	old = tree;
	new = tree->right;
	old->parent = new;
	if (!new->left)
	{
		new->left = old;
		new->parent = NULL;
		return (new);
	}
	old->right = new->left;
	old->right->parent = old;
	new->left = old;
	new->parent = NULL;
	return (new);
}

