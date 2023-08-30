#include "binary_trees.h"

int check_if_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level);
const binary_tree_t *getLeaf(const binary_tree_t *tree);
size_t depth(const binary_tree_t *tree);
unsigned char is_leaves(const binary_tree_t *node);

/**
  *check_if_perfect- Recursively check if tree is perfect
  *@tree: The tree node pointer
  *@leaf_depth: leaf depth
  *@level: The level of the tree
  *
  *Return: 1 success 0 otherwise
  */

int check_if_perfect(const binary_tree_t *tree,
		size_t leaf_depth, size_t level)
{
	if (is_leaves(tree))
		return (level == leaf_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (check_if_perfect(tree->left, leaf_depth, level + 1) &&
		check_if_perfect(tree->right, leaf_depth, level + 1));
}

/**
  *binary_tree_t *getLeaf - Get the leaf of a binary tree
  *@tree: the tree node
  *
  *Return: A pointer
  */

const binary_tree_t *getLeaf(const binary_tree_t *tree)
{
	if (is_leaves(tree) == 1)
		return (tree);

	return (tree->left ? getLeaf(tree->left) : getLeaf(tree->right));
}

/**
  *depth - find the depth of a binary tree
  *@tree: the tree node
  *
  *Return: 1 on success 0 otherwise
  */

size_t depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + depth(tree->parent) : 0);
}

/**
  *is_leaves - checks if a node is a leaf
  *@node: the node to check
  *
  *Return: 1 on success 0 otherwise
  */

unsigned char is_leaves(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
  *binary_tree_is_perfect - checks if a binary tree is perfect
  *@tree: The pointer to root node
  *
  *Return: 1 on success 0r 0 otherwise
  */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (check_if_perfect(tree, depth(getLeaf(tree)), 0));
}
