#include "binary_trees.h"
#include <stdio.h>
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: 0 if fail else size_t height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (height(tree) - 1);
}

/**
 * height - calculate height of a binary tree
 * @tree: pointer to root
 * Return: height
 */
size_t height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (max(height(tree->left), height(tree->right)) + 1);
}
/**
 * max - finds greater number of two
 * @a: first number
 * @b: second number
 * Return: greatest number
 */
size_t max(size_t a, size_t b)
{
	if (a >= b)
		return (a);
	return (b);
}
