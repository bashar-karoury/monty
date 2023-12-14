#ifndef _STACK_OP_H_
#define _STACK_OP_H_
#include "monty.h"

stack_t *add_to_end(stack_t **head, int n);
int pop_from_end(stack_t **head);
int pop_from_start(stack_t **head);
int get_len(stack_t *head);
void print_stack(stack_t *head);
void print_top_of_stack(stack_t *head);
void free_stack(stack_t **head);
#endif
