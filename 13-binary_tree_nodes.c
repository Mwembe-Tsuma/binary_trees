#include "binary_trees.h"

/**
  *binary_tree_nodes - func that counts number of nodes of a binary tree
  *@tree: Pointer to the node
  *
  *Return: Number of nodes
  */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t No_nodes = 0;

	if (tree)
	{
		No_nodes += (tree->left || tree->right) ? 1 : 0;

		No_nodes += binary_tree_leaves(tree->left);
		No_nodes += binary_tree_leaves(tree->right);
	}

	return (No_nodes);
}
