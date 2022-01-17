#include "binary_trees.h"

/**
 * balance - helper for function below
 * @tree: pointer to root
 * Return: difference between left and right sub tree
 */
int balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (balance(tree->left) - balance(tree->right) + 1);
}
/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (balance(tree) - 1);
}
