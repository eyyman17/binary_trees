#include "binary_trees.h"
/**
 * binary_tree_uncle - finds the uncle of a node.
 * @node: pointer to the node to find the uncle.
 * Return: Pointer to the uncle or NULL.
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL ||
	node->parent->parent == NULL)
		return (NULL);
	if (node->parent->parent->right != NULL)
	{
		if (node->parent->parent->right == node->parent)
		{
			if (node->parent->parent->left != NULL)
				return (node->parent->parent->left);
			else
				return (NULL);
		}
	}
	if (node->parent->parent->left != NULL)
	{
		if (node->parent->parent->left == node->parent)
		{
			if (node->parent->parent->right != NULL)
				return (node->parent->parent->right);
			else
				return (NULL);
		}
	}
	return (NULL);
}
