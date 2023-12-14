#include "monty.h"
#include <stdlib.h>
/**
 * get_len - get length of stack
 * @head: pointer to head node of stack
 *
 * Return: length of stack
 */
int get_len(stack_t *head)
{
	int result = 0;

	if (head == NULL)
		return (result);

	while (head != NULL)
	{
		head = head->next;
		result++;
	}
	return (result);
}
/**
 * free_stack - frees memory occupied by stack
 * @head: double pointer to stack
 */
void free_stack(stack_t **head)
{
	stack_t *freed, *trav;

	if (head != NULL)
	{
		trav = *head;
		while (trav != NULL)
		{
			freed = trav;
			trav = trav->next;
			free(freed);
		}
		*head = NULL;
	}
}


/**
 * get_dnodeint_at_index - returns the nth node of double linked list
 * @head: head pointer to list
 * @index: index of node to be returned
 *
 * Return: pointer to returned node, NULL if no node found at that index
 */
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL && i < index)
	{
		head = head->next;
		i++;
	}

	if (head == NULL)
		return (NULL);
	else
		return (head);
}
