#include <unistd.h>
/**
 * print_string - prints a string to stdout
 * @str: input string
 *
 * Return: nothing
 */

void print_string(const char *str)
{
	unsigned int len;

	len = 0;
	while (str[0])
	{
		len++;
	}
	write(STDOUT_FILENO, str, len);
}
