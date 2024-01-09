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

    /* Initialize the shell data */
    setup_shell(dataptr, argv);

    /* Main shell loop */
    while (1)
    {
        dataptr->line_count++;

        /* Display prompt and read user input */
        prompt_user(interactive);
        read_line(&line, &len);

        /* Check for exit command */
        check_exit_command(line, dataptr);

        /* Process user input */
        handle_input(dataptr, line, arg_count);

        /* Free allocated memory */
        free(line);
        line = NULL;
        len = 0;
    }

    return (0);
}
