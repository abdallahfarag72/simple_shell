#include "main.h"

/**
 * is_path - checks if the input is path
 * @input: input string
 *
 * Return: 0 or 1
 */

int is_path(char *input)
{
	int is_path, i;

	is_path = 0;
	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '/')
		{
			is_path = 1;
			break;
		}
	}
	return (is_path);
}
