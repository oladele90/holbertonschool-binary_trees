#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
    binary_tree_t *temp = NULL, *templ = NULL;

    temp = tree;
    tree = tree->right;
    if (tree->left)
        templ = tree->left;
    else
        templ = NULL;
    tree->left = temp;
    temp->parent = tree;
    temp->right = templ;
    return(tree);
}