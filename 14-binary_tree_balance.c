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
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: The balance factor, 0 if tree is NULL.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance_f = 0;
	size_t height_l = 0, height_r = 0;

	if (tree == NULL)
		return (0);
	height_l = binary_tree_height(tree->left);
	if (tree->left != NULL)
		height_l++;
	height_r = binary_tree_height(tree->right);
	if (tree->right != NULL)
		height_r++;
	balance_f = height_l - height_r;
	return (balance_f);
}
