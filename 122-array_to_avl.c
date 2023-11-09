#include "binary_trees.h"

/**
* array_to_avl - inserts array of ints to an avl tree
* @array: array of ints
* @size: size of array
* Return: root of tree
*/
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
