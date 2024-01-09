#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * struct shell_data - Data structure for the custom shell.
 * @program_name: The name of the program (shell).
 * @line_count: The current line number in the shell session.
 * @line: The line input from the user.
 * @path: The PATH environment variable.
 * @args: The parsed arguments from the user input.
 */
typedef struct shell_data
{
	const char *program_name;
	int line_count;
	char *line;
	char *path;
	char **args;
	int last_status;
} shell_t;

extern shell_t data;
extern shell_t *dataptr;
extern char **environ;

void print_env(void);
void sigint_handler(int signo);
void error_printer(char *command, shell_t *dataptr);
char *search_path(char *command, shell_t *dataptr);
void setup_shell(shell_t *dataptr, char **argv);
void prompt_user(int interactive);
int handle_exit(char *line, shell_t *dataptr);
char **parse_input(char *line, int arg_count);
void read_line(char **line, size_t *len);
int check_exit_command(char *line, shell_t *dataptr);
int execute_command(char **args, char *full_path);
void handle_input(shell_t *dataptr, char *line, int arg_count);

int _atoi(const char *nptr);
size_t _strlen(const char *s);
char *_strchr(const char *s, int c);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strtok(char *str, const char *delim);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif /* SHELL_H */
