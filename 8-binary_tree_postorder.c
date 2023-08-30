#include "binary_trees.h"

/**
  *binary_tree_postorder - func that treverse a binary tree in postorder
  *@tree: Pointer to the node
  *@func: Function to call on each node
  *Return: 1 if node is a root, 0 otherwise
  */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);

		binary_tree_postorder(tree->right, func);

		func(tree->n);
	}
}
