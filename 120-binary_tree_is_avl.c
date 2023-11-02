#include "binary_trees.h"

/**
* binary_tree_rotate_left - balances tree by rotating left
* @tree: tree to balance
* Return: pointer to tree
*/

int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    if (tree->n <= min || tree->n >= max)
        return 0;

    return is_bst(tree->left, min, tree->n) && is_bst(tree->right, tree->n, max);
}

int binary_tree_is_avl(const binary_tree_t *tree)
{
    int left_height, right_height;
    binary_tree_t *root = (binary_tree_t *)tree;

    if (!is_bst(root, INT_MIN, INT_MAX))
        return (-1);
    if (!tree)
        return (0);
    left_height = binary_tree_is_avl(tree->left);
    right_height = binary_tree_is_avl(tree->right);
    if (left_height == -1 || right_height == -1)
        return (-1);
    if (abs(left_height - right_height) > 1)
        return (-1);
    return ((left_height > right_height) ? left_height + 1 : right_height + 1);
}