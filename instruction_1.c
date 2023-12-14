#include "instruction.h"
#include <stdio.h>
#include "tools.h"
#include "stack_operations.h"
#include <stdlib.h>
extern monty_info_t info;
void pall(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{ 
	print_stack(*stack);
}
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
void pop(stack_t **stack, unsigned int line_number)
{
	printf("executing pop\n");

}
void pint(stack_t **stack, unsigned int line_number)
{
	printf("executing pint\n");

}
