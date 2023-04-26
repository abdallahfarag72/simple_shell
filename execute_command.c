#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_command - executes the shell command using execve
 * @input: input string
 * @file_name: file name for error handling
 * @line_number: line number for error handling
 *
 * Return: nothing
 */

void execute_command(char *input, char *file_name, int line_number)
{
	char **argv, *command_path;
	pid_t pid;

	newline_to_null(input);
	argv = split_string(input, " ");
	if (_strcmp(argv[0], "exit", 5) == 0)
		exit(1);
	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		/*Child Process*/
		if (!is_path(input))
		{
			command_path = find_command_path(argv[0], environ);
			if (command_path == NULL)
			{
				print_string(file_name);
				print_string(": ");
				_putchar(line_number + '0');
				print_string(": ");
				print_string(argv[0]);
				print_string(": command not found\n");
				exit(1);
			}
			argv[0] = command_path;
		}
		execve(argv[0], argv, environ);
		perror("execve() failed");
		exit(1);
	}
	else
	{
		/*Parent process*/
		wait(NULL);
	}
}
