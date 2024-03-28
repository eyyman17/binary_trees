#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: The height, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0, height_r = 0, height_l = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		height_l += binary_tree_height(tree->left);
	if (tree->right != NULL)
		height_r += binary_tree_height(tree->right);
	if (tree->left != NULL)
		height_l++;
	if (tree->right != NULL)
		height_r++;
	if (height_r > height_l)
		height = height_r;
	else
		height = height_l;
	return (height);
}
