#include "binary_trees.h"

/**
 * binary_tree_node - creates binary tree
 * @parent: pointer to the parent node of the node to create
 * @value: data to store in new node
 * Return: pointer to the new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	new->n = value;
	new->right = NULL;
	new->left = NULL;
	if (parent == NULL)
	{
		parent = new;
		return (new);
	}
	if (parent->left == NULL)
	{
		parent->left = new;
		new->parent = parent;
		return (new);
	}
	parent->right = new;
	new->parent = parent;
	return (new);
}
