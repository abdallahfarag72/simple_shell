#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
/**
 * main - executes the program
 * @argc: number of args
 * @argv: array of args
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *input;
	size_t input_size;
	int line_number;
	(void)argc;
	input = NULL;
	input_size = 0;
	line_number = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			print_string("# ");
		if (getline(&input, &input_size, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		line_number++;
		execute_command(input, argv[0], line_number);
	}
	free(input);
	return (0);
}
