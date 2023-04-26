#include "main.h"
/**
 * _strcmp - compares two strings.
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: maximum number of characters to compare
 * Return: int ascii diff
*/
int _strcmp(char *s1, char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] == '\0')
			return (0);
	}
	return (0);
}
