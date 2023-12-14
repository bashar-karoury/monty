#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
/**
 * mul - multiply two top elements of stack and store the result
 * in second top node
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void mul(stack_t **stack, unsigned int line_number)
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
			n2->n = n2->n * n1->n;
			pop_from_end(stack);
		}
		else
		{
			fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
			info.l_ins_exit_code = EXIT_FAILURE;

		}
	}
}
/**
 * mod - Compute the modulus of  two top elements of stack and
 * store the result in second top node
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void mod(stack_t **stack, unsigned int line_number)
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
			if (n1->n == 0)
			{
				fprintf(stderr, "L%d: division by zero\n", line_number);
				info.l_ins_exit_code = EXIT_FAILURE;

			}
			else
			{
				n2->n = (n2->n) % (n1->n);
				pop_from_end(stack);
			}
		}
		else
		{
			fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
			info.l_ins_exit_code = EXIT_FAILURE;

		}
	}
}


/**
 * pchar -  prints the char at the top of the stack
 * @stack: double pointer to head node of stack
 * @line_number: line number of executions
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int len;
	stack_t *node;

	if (stack)
	{
		if (*stack)
		{	len =  get_len(*stack);
			node = get_dnodeint_at_index(*stack, len - 1);
			if (is_ascii(node->n))
			{
				printf("%c\n", (char)node->n);
			}
			else
			{
				fprintf(stderr, "L%d: can't pchar, value out of range\n",
														line_number);
				info.l_ins_exit_code = EXIT_FAILURE;
			}
		}
		else
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
			info.l_ins_exit_code = EXIT_FAILURE;

		}
	}
}
