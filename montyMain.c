#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
monty_info_t info = {
	NULL,
	0,
	0
};
void free_av(void);
int parse_line(char *line);
void end_with_null(char *s);
void handle_instruction(stack_t **stack, unsigned int line_number);
/**
 * main - Entry point of monty program
 * @argc: count of arguments
 * @argv: pointer to arguments string
 *
 * Return: Exit code of program
 */
int main(int argc, char **argv)
{
	FILE *fstream;
	char *line = NULL;
	/*	int result = 0; */
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fstream = fopen(argv[1], "r");
	if (fstream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * 1000);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(fstream);
		exit(EXIT_FAILURE);
	}
	info.av = malloc(sizeof(char *) * 10);

	if (info.av == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		fclose(fstream);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, 1000, fstream) && (info.l_ins_exit_code == 0))
	{
		end_with_null(line);
		if (parse_line(line) != 0)
		{
			handle_instruction(&stack, line_number);
		}
		free_av();
		line_number++;
	}
	free(line);
	free(info.av);
	free_stack(&stack);
	fclose(fstream);
	return (info.l_ins_exit_code);
}

/**
 * parse_line - tokenize words separated by spaces
 * @line: string to be tokenized
 *
 * Return: Number of words
 */
int	parse_line(char *line)
{
	char *token = NULL;
	int i = 0;

	token = strtok(line, " ");
	while (token)
	{
		(info.av)[i] = _strdup(token);
		if (((info.av)[i])[0] == '#')
		{
			free(((info.av)[i]));
			break;
		}
		token = strtok(NULL, " ");
		/* May check malloc result after strdupping*/
		i++;
	}
	(info.av)[i] = NULL;
	return (i);
}

/**
 * free_av - frees memory of elements in array av
 */
void free_av(void)
{
	int i = 0;

	while ((info.av)[i] != NULL)
		free((info.av)[i++]);
}

/**
 * end_with_null - end string with null terminator instead of newline
 * @s: string
 */
void end_with_null(char *s)
{
	while (*s != '\0')
		s++;
	if (*(--s) == '\n')
		*(s) = '\0';
}


/**
 * handle_instruction - handle instruction and process it appriopriately
 * @stack: double pointer to stack
 * @line_number: number of instruction to be execute
 */
void handle_instruction(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	int found = 0;
	const instruction_t array_of_ins[NO_INS] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add}, {"nop", nop},
		{"sub", sub}, {"div", divide}, {"mul", mul}, {"mod", mod},
		{"pchar", pchar}, {"pstr", pstr}, {"rotl", rotl},  {"rotr", rotr}};

	/*check if instruction is valid*/
	for (i = 0; i < NO_INS; i++)
	{
		if (strcmp(array_of_ins[i].opcode, (info.av[0])) == 0)
		{
			(array_of_ins[i].f)(stack, line_number);
			found = 1;
			break;
		}
	}

	if (!(found))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, info.av[0]);
		info.l_ins_exit_code = EXIT_FAILURE;
	}

}
