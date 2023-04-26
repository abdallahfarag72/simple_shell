#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
extern char **environ;
void execute_command(char *input, char *file_name, int line_number);
void print_string(const char *str);
char **split_string(char *str, char *separator);
void newline_to_null(char *str);
char *find_command_path(char *command_name, char **environ);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
int is_path(char *input);
int _putchar(char c);
#endif
