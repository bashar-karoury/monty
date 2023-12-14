#ifndef _MONTE_H_
#define _MONTE_H_
#include <stdio.h>
#include <stdlib.h>

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
extern monty_info_t info;

/* Instructions functions definitions */
#define NO_INS 13

void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
/* Stack operations*/
stack_t *add_to_end(stack_t **head, int n);
int pop_from_end(stack_t **head);
int pop_from_start(stack_t **head);
int get_len(stack_t *head);
void print_stack(stack_t *head);
void print_top_of_stack(stack_t *head);
void free_stack(stack_t **head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);

/* Strings helper functiona*/

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _putchar(char c);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strtok(char *str, const char *delim);
void print_str(char *str);
void print_error(char *str);
int _atoi(char *s);
int is_number(char *str);

/* tools */

int integer(char *ascii_int, int *n);
int is_ascii(int n);
#endif
