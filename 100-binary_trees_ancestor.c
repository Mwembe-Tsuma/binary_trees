#include "binary_trees.h"

/**
  *binary_trees_ancestor - check for lowest common ancestor node
  *@first: pointer to the first node to check
  *@second: pointer to second node to check
  *Return: Pointer to ancestor node or NULL otherwise
  */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *pop, *mum;

	if (!first || !second)
		return (NULL);

	if (first == second)
		return ((binary_tree_t *)first);

	mum = first->parent, pop = second->parent;

	if (first == pop || !mum || (!mum->parent && pop))
		return (binary_trees_ancestor(first, pop));

	else if (mum == second || !pop || (!pop->parent && mum))
		return (binary_trees_ancestor(mum, second));
	return (binary_trees_ancestor(mum, pop));
}
