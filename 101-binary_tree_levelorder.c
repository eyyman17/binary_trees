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
 * print_actual_level - Prints the node of the actual level.
 * @node: Node to of tree.
 * @height: Height of the node.
 * @func: is a pointer to a function to call for each node.
 * Return: Void.
 */
void traverse_actual_level(const binary_tree_t *node, size_t height,
void (*func)(int))
{
	if (node == NULL)
		return;
	if (height == 1)
		func(node->n);
	if (height > 1)
	{
		traverse_actual_level(node->left, height - 1, func);
		traverse_actual_level(node->right, height - 1, func);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal.
 * @tree: Pointer to root node of the binary tree.
 * @func: is a pointer to a function to call for each node.
 * Return: Void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (tree == NULL || func == NULL)
		return;
	height = binary_tree_height(tree);
	for (i = 1; i <= height + 1; i++)
		traverse_actual_level(tree, i, func);
}
