#include "instruction.h"
#include <stdio.h>
#include "tools.h"
#include "stack_operations.h"
#include <stdlib.h>

/**
 * pall - print all stack
 * @stack: double pointer to head node of stack
 * @line_number: int as line number of execution
 */
void pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
	print_stack(*stack);
}


/**
* push - push to stack
* @stack: double pointer to head node of stack
* @line_number: int as line number of execution
*/
void push(stack_t **stack, unsigned int line_number)
{
	int n = 0;

	if (info.av[1] && integer(info.av[1], &n))
	{
		add_to_end(stack, n);
		info.l_ins_exit_code = 0;
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		info.l_ins_exit_code = EXIT_FAILURE;
	}


}
/**
* pop - pop top of stack
* @stack: double pointer to head node of stack
* @line_number: int as line number of execution
*/

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		pop_from_end(stak);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		info.l_ins_exit_code = EXIT_FAILURE;
	}
}
/**
* pint- print top of stack
* @stack: double pointer to head node of stack
* @line_number: int as line number of execution
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack && *stack)
	{
		print_top_of_stack(*stack);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		info.l_ins_exit_code = EXIT_FAILURE;
	}

}
