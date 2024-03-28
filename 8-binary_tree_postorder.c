#include "binary_trees.h"
/**
 * binary_tree_postorder - goes through a binary tree using post-order
 * traversal.
 * @tree: Pointer to root node of the binary tree.
 * @func: is a pointer to a function to call for each node.
 * Return: Void.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	if (tree->left != NULL)
		binary_tree_postorder(tree->left, func);
	else
	{
		if (tree->right != NULL)
			binary_tree_postorder(tree->right, func);
	}
	if (tree->right != NULL)
		binary_tree_postorder(tree->right, func);
	else
	{
		if (tree->right != NULL)
			binary_tree_postorder(tree->right, func);
	}
	func(tree->n);
}
