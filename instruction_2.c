#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * swap - swap two top elements of stack
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int len;
	stack_t *n1, *n2;
	int temp = 0;

	if (stack)
	{
		len = get_len(*stack);
		if (len >= 2)
		{
			n1 = get_dnodeint_at_index(*stack, len - 1);
			n2 = get_dnodeint_at_index(*stack, len - 2);
			temp = n1->n;
			n1->n = n2->n;
			n2->n = temp;
		}
		else
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
			info.l_ins_exit_code = EXIT_FAILURE;

		}
	}
}
/**
 * add - add two top elements of stack and store the result in second top node
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void add(stack_t **stack, unsigned int line_number)
{
	int len;
	stack_t *n1, *n2;

	if (stack)
	{
		len = get_len(*stack);
		if (len >= 2)
		{
			n1 = get_dnodeint_at_index(*stack, len - 1);
			n2 = get_dnodeint_at_index(*stack, len - 2);
			n1->n = n2->n;
			n2->n = n1->n + n2->n;
			pop_from_end(stack);
		}
		else
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			info.l_ins_exit_code = EXIT_FAILURE;

		}
	}
}
/**
 * nop - No operation
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */


void nop(__attribute__ ((unused)) stack_t **stack,
		__attribute__ ((unused))  unsigned int line_number)
{

}
