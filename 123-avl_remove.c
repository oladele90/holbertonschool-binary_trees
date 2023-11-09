#include "binary_trees.h"

/**
* avl_tree_balance - gets balance of binary tree
* @tree:  tree to balance
* Return: int rep of balance factor
*/
static int avl_tree_balance(const avl_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height - right_height));
}

/**
 * bst_remove - Removes a node from a binary search tree
 * @root: Pointer to the root of the BST
 * @value: Value to remove from the BST
 * Return: New root of the BST after removal
 */
static avl_t *bst_remove(avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = root->right;
		while (temp->left)
			temp = temp->left;
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	balance = avl_tree_balance(root);
	if (balance > 1)
	{
		if (avl_tree_balance(root->left) >= 0)
			return (avl_tree_rotate_right(root));
		root->left = avl_tree_rotate_left(root->left);
		return (avl_tree_rotate_right(root));
	}
	if (balance < -1)
	{
		if (avl_tree_balance(root->right) <= 0)
			return (avl_tree_rotate_left(root));
		root->right = avl_tree_rotate_right(root->right);
		return (avl_tree_rotate_left(root));
	}
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: root of the AVL tree
 * @value: value to remove
 * Return: new root of the AVL tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);

	root = bst_remove(root, value);

	return (root);
}
