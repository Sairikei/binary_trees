#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - deletes an entire binary tree
 * @tree: is a pointer to the root node of the tree to delete
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}

/**
 * delete_helper - can be used in above function to delete nodes
 * Just another way of implementing a deletion
 * @tree: pointer to root node
 * Return: void
 */
void delete_helper(binary_tree_t *tree)
{
	if (tree->left)
	{
		delete_helper(tree->left);
		free(tree->left);
	}
	if (tree->right)
	{
		delete_helper(tree->right);
		free(tree->right);
	}
}
