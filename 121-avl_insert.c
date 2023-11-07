#include "binary_trees.h"

/**
* binary_tree_balance - gets balance of binary tree
* @tree:  tree to balance
* Return: int rep of balance factor
*/
int avl_tree_balance(const avl_t *tree)
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
int avl_tree_height(const avl_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (-1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}


avl_t *bst_insert(avl_t *root, avl_t *new, int value)
{
    int balance;
	if(!new)
		return (NULL);
	if (!root)
	{
		root = new;
		return (root);
	}
	new->parent = root;
	if (new->n > root->n)
		root->right = bst_insert(root->right, new, value);
	if (new->n < root->n)
		root->left = bst_insert(root->left, new, value);
    balance = avl_tree_balance(root);

    /* Left Left Case */
    if (balance > 1 && value < root->left->n) 
        return(avl_tree_rotate_right(root)); 
  
    /* Right Right Case */
    if (balance < -1 && value > root->right->n) 
        return(avl_tree_rotate_left(root)); 
  
    /* Left Right Case */
    if (balance > 1 && value > root->left->n) 
    { 
        root->left = avl_tree_rotate_left(root->left); 
        return(avl_tree_rotate_right(root)); 
    } 
  
    /*Right Left Case*/ 
    if (balance < -1 && value < root->right->n) 
    { 
        root->right = avl_tree_rotate_right(root->right); 
        return(avl_tree_rotate_left(root)); 
    } 
	return (root);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A pointer to the root of the AVL tree.
 * @value: The value to insert.
 * Return: A pointer to the new node, or NULL on failure.
 */

avl_t *avl_insert(avl_t **tree, int value)
{
    binary_tree_t *new_node;

    new_node = binary_tree_node(NULL, value);
    if (!*tree)
    {
        if (!new_node)
            return (NULL);
        *tree = new_node;
        return (*tree);
    }
    else
        bst_insert(*tree, new_node, value);
    return (new_node);
}

