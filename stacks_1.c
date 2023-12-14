#include <stdlib.h>
#include <stdio.h>
#include "monty.h"


/**
 * add_to_end - add node to end of stack
 * @head: double pointer to head of stack
 * @n: int to be stored in node
 *
 * Return: pointer to added node
 */
stack_t *add_to_end(stack_t **head, int n)
{
	stack_t *new;
	stack_t *trav;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	trav = *head;
	if (trav != NULL)
	{
		while (trav->next != NULL)
		{
			trav = trav->next;
		}
	}
	new->n = n;
	new->prev = trav;
	new->next = NULL;
	if (trav)
		trav->next = new;
	else
		*head = new;
	return (new);
}

/**
 * pop_from_end - get top of stack
 * @head: double pointer to head node of stack
 *
 * Return: int at top of stack
 */
int pop_from_end(stack_t **head)
{
	stack_t *trav, *freed;
	int pop;

	if (head == NULL || *head == NULL)
		return (0);

	trav = *head;
	while (trav->next != NULL)
		trav = trav->next;
	pop = trav->n;
	freed = trav;
	if (trav == *head)
	{
		*head = NULL;
	}
	else
	{
		trav = trav->prev;
		trav->next = NULL;
	}
	free(freed);
	return (pop);
}

/**
 * pop_from_start - get first of stack (top of queue)
 * @head: double pointer to head node of stack
 *
 * Return: int at first node of stack (front of queue)
 */
int pop_from_start(stack_t **head)
{
	int result;
	stack_t *freed;

	if (head == NULL || *head == NULL)
		return (0);
	result = (*head)->n;
	freed = *head;
	*head = (*head)->next;
	free(freed);
	return (result);
}
/**
 * print_stack - print all elements of stack from top
 * @head: pointer to head of stack
 */
void print_stack(stack_t *head)
{
	/* traverse till top of stack*/
	if (!head)
		return;
	while (head->next != NULL)
		head = head->next;
	/*now start printing from top*/
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->prev;
	}
}

/**
 * print_top_of_stack - print value of integer at top of stack
 * @head: pointer to head node of stack
 */
void print_top_of_stack(stack_t *head)
{
	/* traverse till top of stack*/
	if (!head)
		return;
	while (head->next != NULL)
		head = head->next;
	/*now print top*/
	printf("%d\n", head->n);
}
