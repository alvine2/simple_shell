#include "shell.h"

/**
 * print_env - Prints all the environment variables.
 */
void print_env(void)
{
    int i = 0;

    while (environ[i] != NULL)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
