#include "binary_trees.h"

/**
 * find_depth - finds depths of left most node
 * @tree: pointer to a node
 * Return: depth
 */
int find_depth(const binary_tree_t *tree)
{
	int d = 0;

	while (tree)
	{
		d++;
		tree = tree->left;
	}
	return (d);
}
/**
 * helper - helper for function below
 * @tree: pointer to root
 * @d: the depth
 * @level: level of node in the tree
 * Return: 1 else 0
 */
int helper(const binary_tree_t *tree, int d, int level)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (d == level + 1);
	if (!tree->left || !tree->right)
		return (0);
	return (helper(tree->left, d, level + 1) &&
			helper(tree->right, d, level + 1));
}
/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if true else 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d;

	if (!tree)
		return (0);
	d = find_depth(tree);
	return (helper(tree, d, 0));
}
