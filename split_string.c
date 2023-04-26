#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * split_string - splits a string into an array of each word
 * @str: string
 *
 * Return: array of strings
 */

char **split_string(char *str, char *separator)
{
	char *token, **words;
	int i;

	words = malloc(100 * sizeof(char*));
	if (words == NULL)
	{
		exit(1);
	}
	
	token = strtok(str, separator);
	i = 0;
	while (token != NULL)
	{
		words[i] = token;
		i++;
		token = strtok(NULL, separator);
	}
	return (words);
	free(words);
}
