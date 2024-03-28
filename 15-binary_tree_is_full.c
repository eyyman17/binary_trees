#include "binary_trees.h"
/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree:  pointer to the root node of the tree.
 * Return: 1 if tree is full, 0 if not.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int decision = 1;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
	{
		decision = binary_tree_is_full(tree->left) &
		binary_tree_is_full(tree->right);
	}
	if ((tree->left != NULL && tree->right == NULL) ||
	(tree->right != NULL && tree->left == NULL))
	{
		return (0);
	}
	return (decision);
}
