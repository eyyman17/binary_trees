#include "binary_trees.h"
/**
 * binary_tree_preorder - goes through a binary tree using pre-order traversal.
 * @tree: Pointer to root node of the binary tree.
 * @func: is a pointer to a function to call for each node.
 * Return: Void.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	if (tree->left != NULL)
		binary_tree_preorder(tree->left, func);
	else
	{
		if (tree->right != NULL)
			binary_tree_preorder(tree->right, func);
	}
	if (tree->right != NULL)
		binary_tree_preorder(tree->right, func);
	else
	{
		if (tree->right != NULL)
			binary_tree_preorder(tree->right, func);
	}
}
