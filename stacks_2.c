#include "stack_operations.h"
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
