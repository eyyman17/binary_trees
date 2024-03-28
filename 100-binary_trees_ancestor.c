#include "binary_trees.h"
/**
 * binary_tree_depth - measures the depth of a binary tree.
 * @tree: pointer to the root node of the tree.
 * Return: The depth, 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree == NULL)
		return (0);
	if (tree->parent != NULL)
		depth += binary_tree_depth(tree->parent);
	if (tree->parent != NULL)
		depth++;
	return (depth);
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor..
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	binary_tree_t *first_p = (binary_tree_t *)first, *second_p;
	size_t depth_first, depth_second, i;

	if (first == NULL || second == NULL)
		return (NULL);
	second_p = (binary_tree_t *)second;
	depth_first = binary_tree_depth(first);
	depth_second = binary_tree_depth(second);
	if (depth_first < depth_second)
	{
		for (i = 0; i < depth_second - depth_first; i++)
			second_p = second_p->parent;
		while (first_p != second_p && (second_p != NULL || first_p != NULL))
		{
			first_p = first_p->parent;
			second_p = second_p->parent;
		}
	}
	if (depth_first > depth_second)
	{
		for (i = 0; i < depth_first - depth_second; i++)
			first_p = first_p->parent;
		while (first_p != second_p && (second_p != NULL || first_p != NULL))
		{
			first_p = first_p->parent;
			second_p = second_p->parent;
		}
	}
	else
	{
		while (first_p != second_p && (second_p != NULL || first_p != NULL))
		{
			first_p = first_p->parent;
			second_p = second_p->parent;
		}
	}
	if (second_p == first_p)
		return (second_p);
	return (NULL);
}
