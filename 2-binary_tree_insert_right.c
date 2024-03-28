#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: Pointer to the parent node of the new node.
 * @value: The value to put in the new node.
 * Return: Pointer to the new node or NULL.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *old_right_child;

	if (parent == NULL)
		return (NULL);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	if (parent->right != NULL)
	{
		old_right_child = parent->right;
		parent->right = new_node;
		old_right_child->parent = new_node;
		new_node->right = old_right_child;
		return (new_node);
	}
	parent->right = new_node;
	new_node->right = NULL;
	return (new_node);
}
