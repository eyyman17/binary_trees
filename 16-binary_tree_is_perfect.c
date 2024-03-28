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
/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree:  pointer to the root node of the tree.
 * Return: 1 if tree is full, 0 if not.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int decision = 1;
	size_t height_r = 0, height_l = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL && tree->right != NULL)
		decision = binary_tree_is_perfect(tree->left) &
		binary_tree_is_perfect(tree->right);
	if ((tree->left != NULL && tree->right == NULL) ||
	(tree->right != NULL && tree->left == NULL))
		return (0);
	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	if (height_r != height_l)
		return (0);
	return (decision);
}
