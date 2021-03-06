#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: tree to be inserted
 * @value: value to be inserted
 *
 * Return: tree inserted
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	avl_t *node;

	if (tree != NULL)
	{
		if (value == (*tree)->n)
			return (NULL);
		if (value < (*tree)->n)
		{
			if ((*tree)->left == NULL)
			{
				(*tree)->left = binary_tree_node(*tree, value);
				return ((*tree)->left);
			}
			else
			{
				node = bst_insert(&((*tree)->left), value);
				if (node)
					Cbalance(tree, value);
				return (node);
			}
		}
		else
		{
			if ((*tree)->right == NULL)
			{
				(*tree)->right = binary_tree_node(*tree, value);
				return ((*tree)->right);
			}
			else
			{
				node = bst_insert(&((*tree)->right), value);
				if (node)
					Cbalance(tree, value);
				return (node);
			}
		}
	}
	return (NULL);
}

/**
 * avl_insert - insert node to make avl
 * @tree: tree to be checked
 * @value: value to be inserted
 *
 * Return: tree after insertion
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		(*tree) = binary_tree_node(*tree, value);
		return (*tree);
	}
	node = bst_insert(tree, value);
	return (node);
}

/**
 * Cbalance - check the balance
 * @tree: node to be check
 * @value: value to be checked
 *
 * Return: void function
 */

void Cbalance(avl_t **tree, int value)
{
	int balance_n;

	balance_n = binary_tree_balance(*tree);

	if ((balance_n > 1) && (value < (*tree)->left->n))
	{
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if ((balance_n > 1) && (value > (*tree)->left->n))
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
		return;
	}
	if ((balance_n < -1) && (value > (*tree)->right->n))
	{
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
	if ((balance_n < -1) && (value < (*tree)->right->n))
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
		return;
	}
	if (((*tree)->left) != NULL)
	{
		Cbalance(&((*tree)->left), value);
	}
	if (((*tree)->right) != NULL)
	{
		Cbalance(&((*tree)->right), value);
	}
}
