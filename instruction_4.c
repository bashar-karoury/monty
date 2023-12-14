#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void rotl(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	int n1;

	if (stack)
	{
		n1 = pop_from_end(stack);
		add_to_start(stack, n1);
	}
}
/**
 * rotr - rotates the stack to the bottom
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void rotr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	int n1;

	if (stack)
	{
		n1 = pop_from_start(stack);
		add_to_end(stack, n1);
	}
}
