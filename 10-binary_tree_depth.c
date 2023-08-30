#include "binary_trees.h"

/**
  *binary_tree_depth - func that measures the depth of a binary tree
  *@tree: Pointer to the node
  *
  *Return: The depth, 0 otherwise
  */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth
			(tree->parent) : 0);
}
