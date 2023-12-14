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

/**
 * is_ascii - check if int is in range of ascii characters
 * @n: ascii integer
 *
 *Return: 1 if true, 0 if false
 */
int is_ascii(int n)
{
	int result = 1;

	if (n > 127 || n < 0)
		result = 0;
	return (result);
}
