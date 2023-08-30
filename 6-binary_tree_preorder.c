#include "binary_trees.h"

/**
  *binary_tree_preorder - func that treverse a binary tree in pre-order
  *@tree: Pointer to the node
  *@func: Function to call on each node
  *Return: 1 if node is a root, 0 otherwise
  */

void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);

		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
