#include "binary_trees.h"

void free_que(levelorder_queue_t *head);
void print_push(binary_tree_t *node, levelorder_queue_t *head,
		levelorder_queue_t **tail);
void pop_out(levelorder_queue_t **head);
levelorder_queue_t *new_node(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);

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
  *
  */

void print_push(binary_tree_t *node, levelorder_queue_t *head,
		 levelorder_queue_t **tail)
{
	levelorder_queue_t *newNode;

	newNode = new_node(node);
	if (newNode == NULL)
	{
		free_que(head);
		exit(1);
	}
	(*tail)->next = newNode;
	*tail = newNode;
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
  *binary_tree_is_complete - Check if a binary tree is complete
  *@
  *@tree: Pointer to root node
  *Return: Success, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *head, *tail;
	unsigned char flags = 0;

	if (tree == NULL)
		return (0);
	head = tail = new_node((binary_tree_t *)tree);
	if (head == NULL)
		exit(1);

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flags == 1)
			{
				free_que(head);
				return (0);
			}
			print_push(head->node->left, head, &tail);
		}
		else
			flags = 1;

		if (head->node->right != NULL)
		{
			if (flags == 1)
			{
				free_que(head);
				return (0);
			}
			print_push(head->node->right, head, &tail);
		}
		else
			flags = 1;
		pop_out(&head);
	}
	return (1);
}
