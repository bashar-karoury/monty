#ifndef _MONTE_H_
#define _MONTE_H_
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct monty_info_s - struct contains info to be used by functions
 * @av: array of instruction words
 * @is_stack: 0 if stack, 1 if queue
 * @l_ins_exit_code: exit code of last instruction
*/
typedef struct monty_info_s
{
	char **av;
	char is_stack;
	char l_ins_exit_code;
} monty_info_t;

#endif
