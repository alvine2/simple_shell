#include "shell.h"

/**
 * main - The main entry point of the shell.
 * @argc: The argument count.
 * @argv: An array of argument strings.
 * Return: Always 0.
 */
int main(int argc __attribute__((unused)), char **argv)
{
	shell_t data;
	shell_t *dataptr = &data;
	char *line = NULL;
	size_t len = 0;
	int interactive = isatty(STDIN_FILENO);
	int arg_count = 10;

	setup_shell(dataptr, argv);

	while (1)
	{
		dataptr->line_count++;

		prompt_user(interactive);
		read_line(&line, &len);
		check_exit_command(line, dataptr);
		handle_input(dataptr, line, arg_count);

		free(line);
		line = NULL;
		len = 0;
	}

	return (0);
}
