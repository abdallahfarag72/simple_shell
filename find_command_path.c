#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "main.h"

/**
 * find_command_path - finds the command path in environ variable
 * @command_name: command string
 * @environ: environ global variable
 *
 * Return: command path
 */

char *find_command_path(char *command_name, char **environ)
{
	char *path_env_var, *path, *token, *command_path;
	int i;
	struct stat st;

	path_env_var = path = token = command_path = NULL;
	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(environ[i], "PATH=", 5) == 0)
		{
			path_env_var = environ[i];
			break;
		}
	}

	if (path_env_var == NULL)
	{
		perror("Error: PATH environment variable not found.\n");
		return (NULL);
	}

	path = _strdup(path_env_var + 5);
	token = strtok(path, ":");
	while (token != NULL)
	{
		command_path = malloc(_strlen(token) + _strlen(command_name) + 2);
		_strcpy(command_path, token);
		_strcat(command_path, "/");
		_strcat(command_path, command_name);
		if (stat(command_path, &st) == 0 && st.st_mode & S_IXUSR)
		{
			free(path);
			return (command_path);
		}
		free(command_path);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
