#include "binary_trees.h"

void free_que(levelorder_queue_t *head);
void print_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail, void (*func)(int));
void pop_out(levelorder_queue_t **head);
levelorder_queue_t *new_node(binary_tree_t *node);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));


/**
  *new_node - Creates a new node.
  *@node: The node to create
  *
  *Return: New node pointer
  *
  */

levelorder_queue_t *new_node(binary_tree_t *node)
{
	levelorder_queue_t *newNode;

	newNode = malloc(sizeof(levelorder_queue_t));
	if (newNode == NULL)
		return (NULL);

	newNode->node = node;
	newNode->next = NULL;
	return (newNode);
}

/**
  *free_que - free queue
  *@head: Head node
  *
  */

void free_que(levelorder_queue_t *head)
{
	levelorder_queue_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
  *print_push - Pushes children of a tree in level order
  *@node: the node to push
  *@head: the head node
  *@tail: the tail node
  *@func: recursive func to use on each node
  *
  */

void print_push(binary_tree_t *node, levelorder_queue_t *head,
		 levelorder_queue_t **tail, void (*func)(int))
{
	levelorder_queue_t *newNode;

	func(node->n);

	if (node->left != NULL)
	{
		newNode = new_node(node->left);
		if (newNode == NULL)
		{
			free_que(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}

	if (node->right != NULL)
	{
		newNode = new_node(node->right);

		if (newNode == NULL)
		{
			free_que(head);
			exit(1);
		}
		(*tail)->next = newNode;
		*tail = newNode;
	}
}

/**
  *pop_out - pop the head of a queue
  *@head: the hed node
  *
  *
  */

void pop_out(levelorder_queue_t **head)
{
	levelorder_queue_t *temp;

	temp = (*head)->next;
	free(*head);
	*head = temp;
}

/**
  *binary_tree_levelorder - Treverse a binary tree using level order
  *@func: recursive function to use
  *@tree: Pointer to root node
  *Return: Nothing
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	levelorder_queue_t *head, *tail;

	if (tree == NULL || func == NULL)
		return;
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
		return;

	while (head != NULL)
	{
		print_push(head->node, head, &tail, func);
		pop_out(&head);
	}
}
