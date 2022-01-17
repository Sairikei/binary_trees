#include "binary_trees.h"
/**
*Deletes an entire binary tree
*@tree is a pointer to the root node of the tree to delete
*if tree is NULL, do nothing
*/
void binary_tree_delete(binary_tree_t *tree);
{
if (tree == NULL)
return;
binary_tree_delete(tree->right);
binary_tree_delete(tree->left);
free(tree);
}
