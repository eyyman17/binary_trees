#include "binary_trees.h"
/**
 * binary_tree_nodes - measures the number of nodes with at least one child.
 * @tree: pointer to the root node of the tree.
 * Return: The number of nodes with at least 1 child, 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		nodes += binary_tree_nodes(tree->left);
	if (tree->right != NULL)
		nodes += binary_tree_nodes(tree->right);
	if (tree->left != NULL || tree->right != NULL)
		nodes++;
	return (nodes);
}
