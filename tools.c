#include "monty.h"
/**
 * integer - check if ascii string is int or not and convert it if it is
 * @ascii_int: string
 * @n: pointer to int for the converted value
 *
 * Return: 0 if false, 1 if true
 */
int integer(char *ascii_int, int *n)
{
	char *ptr = ascii_int;
	int check = 1;

	while (*ptr)
	{
		if (ptr == ascii_int && *ptr == '-')
		{
			ptr++;
			continue;
		}

		if (((*ptr) < '0') || (*ptr > '9'))
		{
			check = 0;
			break;
		}
		ptr++;
	}
	if (check)
	{
		*n = atoi(ascii_int);
	}

	return (check);
}
