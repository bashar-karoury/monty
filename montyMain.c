#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * main - Entry point of monty program
 * @argc: count of arguments
 * @argv: pointer to arguments string 
 *
 * Return: Exit code of program
 * */
int main(int argc, char **argv)
{
	FILE *fstream;
	char *line = NULL;
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

	line = malloc(sizeof(char) * 100);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);	
	}
	while(fgets(line, 100, fstream))
	{	
		printf("line : %s", line);	
	}
	printf("End of file reached\n");
	free(line);
	return(0);
}
