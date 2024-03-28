#include "binary_trees.h"
/**
 * binary_tree_sibling - finds the sibling of a node.
 * @node: pointer to the node to find the sibling
 * Return: Pointer to the sibling or NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);
	if (node->parent->right != NULL)
	{
		if (node->parent->right == node)
		{
			if (node->parent->left != NULL)
				return (node->parent->left);
			else
				return (NULL);
		}
	}
	if (node->parent->left != NULL)
	{
		if (node->parent->left == node)
		{
			if (node->parent->right != NULL)
				return (node->parent->right);
			else
				return (NULL);
		}
	}
	return (NULL);
}
