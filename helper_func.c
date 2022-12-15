#include "binary_trees.h"

/**
 * set_tree- initializes new node to set value
 * @new: pointer to new node
 * @value: value to store in new node
 * Return: new node
 */

binary_tree_t *set_tree(binary_tree_t *new, int value)
{
	new = malloc(sizeof(binary_tree_t));
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
