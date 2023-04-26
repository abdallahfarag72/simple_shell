#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * split_string - splits a string into an array of each word
 * @str: string
 * @separator: string separator
 *
 * Return: array of strings
 */

char **split_string(char *str, char *separator)
{
	char *token, **words;
	int i, count;

	count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == separator[0])
		{
			count++;
		}
	}
	count++;
	words = malloc(count * sizeof(char *));
	if (words == NULL)
	{
		exit(1);
	}

	token = strtok(str, separator);
	i = 0;
	while (token != NULL && i < count)
	{
		words[i] = token;
		i++;
		token = strtok(NULL, separator);
	}
	return (words);
}
