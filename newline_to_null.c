#include <stdio.h>

/**
 * newline_to_null - replace \n to \0
 * @str: string to be changed
 *
 * Return: nothing
 */

void newline_to_null(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '\n')
		{
			if (str[i + 1] == '\0')
			{
				str[i] = '\0';
			}
			break;
		}
	}
}
