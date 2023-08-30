#include "binary_trees.h"

/**
  *binary_tree_leaves - func that counts number of leaves of a binary tree
  *@tree: Pointer to the node
  *
  *Return: Number, 0 otherwise
  */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaf = 0;

	if (tree)
	{
		leaf += (!tree->left && !tree->right) ? 1 : 0;

		leaf += binary_tree_leaves(tree->left);
		leaf += binary_tree_leaves(tree->right);
	}

	return (leaf);
}
