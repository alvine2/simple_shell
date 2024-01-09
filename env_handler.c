#include "shell.h"

/**
 * print_env - Prints all the environment variables.
 */
void print_env(void)
{
	int i = 0;
/* Loop through the environment variables and print each one */
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
