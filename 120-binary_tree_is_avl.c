#include "binary_trees.h"

/**
 * is_bst - Checks if a tree is a BST
 * @tree: The tree to check
 * @min: The minimum allowed value in the tree
 * @max: The maximum allowed value in the tree
 * Return: 1 if BST, or 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_avl - Checks if a tree is an AVL tree.
 * @tree: The binary tree to check
 * Return: 1 if valid or 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int right_height, left_height;

	if (tree == NULL)
		return (1);

	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
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

