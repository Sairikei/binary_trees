#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent:  pointer to the node to insert the left-child in
 * @value: the value to store in the new node
 * Return: pointer to new node or null
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->left = NULL;
	new->right = NULL;
	new->parent = parent;

	if (!parent->left)
	{
		parent->left = new;
		return (new);
	}
	old = parent->left;
	parent->left = new;
	new->left = old;
	old->parent = new;
	return (new);
}
