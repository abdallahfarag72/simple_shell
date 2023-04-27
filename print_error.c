#include "main.h"

/**
 * print_error - prints command error message
 * @file_name: name of running file
 * @command: not found command
 * @line_number: number of error line
 *
 * Return: nothing
 */

void print_error(char *file_name, char *command, int line_number)
{
	print_string(file_name);
	print_string(": ");
	_putchar(line_number + '0');
	print_string(": ");
	print_string(command);
	print_string(": not found\n");
}
