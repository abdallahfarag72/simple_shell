#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * execute_command - executes the shell command using execve
 * @input: input string
 *
 * Return: nothing
 */

void execute_command(char *input)
{
	char **argv;
	pid_t pid;
	extern char **environ;
	
	newline_to_null(input);
	argv = split_string(input);

	pid = fork();
	if (pid < 0)
	{
		perror("Fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		/*Child Process*/
		if (execve(argv[0], argv, environ) == -1)
		{
			print_string(argv[0]);
			print_string(": command not found\n");
			exit(1);
		}
	}
	else
	{
		/*Parent process*/
		wait(NULL);
	}
}
