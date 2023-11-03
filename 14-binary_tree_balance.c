#include "binary_trees.h"

/**
* binary_tree_balance - gets balance of binary tree
* @tree:  tree to balance
* Return: int rep of balance factor
*/

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height - right_height));
}

/**
 * binary_tree_height - Gets the height of a binary tree
 * @tree: The binary tree
 * Return: Height of the tree or -1
 */

int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}
