#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "strings.h"
char **av;
void free_av(void);
int parse_line(char *line);
void end_with_null(char *s);
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
	int i = 0;

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
		exit(EXIT_FAILURE);
	}
	av = malloc(sizeof(char *) * 10);

	if (av == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(line);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, 1000, fstream))
	{
		end_with_null(line);
		printf("line : %s\n", line);
		if (parse_line(line) != 0)
		{
			for (i = 0; av[i] != NULL; i++)
				printf("av[%d] = %s\n", i, av[i]);
		}
		free_av();
	}
	printf("DEBUG: EOF\n");
	free(line);
	free(av);
	fclose(fstream);
	return (0);
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
		av[i] = _strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	av[i] = NULL;
	return (i);
}

/**
 * free_av - frees memory of elements in array av
*/
void free_av(void)
{
	int i = 0;

	while (av[i] != NULL)
		free(av[i++]);
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
