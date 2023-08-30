#include "binary_trees.h"

/**
  *binary_tree_height - func that measures the height of a binary tree
  *@tree: Pointer to the node
  *
  *Return: 1 if node is a root, 0 otherwise
  */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_tree = 0;
	size_t right_tree = 0;

	if (tree)
	{
		left_tree = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		riht_tree = tree->right ? 1 + binary_tree_height(tree->right) : 0;

		return ((left_tree > right_tree) ?
			(left_tree) : (right_tree));
	}

	return (0);
}
