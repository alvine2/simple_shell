#include "shell.h"

/**
 * handle_exit - Handle the 'exit' command with optional exit status.
 * @line: User input containing the 'exit' command and optional status.
 * @dataptr: Pointer to the shell_t structure.
 *
 * Return: The exit status provided in the 'exit' command.
 */
int handle_exit(char *line, shell_t *dataptr)
{
    char buffer[12];
    char *exit_arg = strtok(line, " \n");

    exit_arg = strtok(NULL, " \n");
    if (exit_arg != NULL)
    {
        char *endptr;
        long exit_status = strtol(exit_arg, &endptr, 10);

        if (*endptr == '\0' && exit_status >= 0 && exit_status <= INT_MAX)
        {
            return (int)exit_status;
        }
        else
        {
            int num_digits = 0, temp_count = dataptr->line_count;

            /* Count the number of digits in line_count */
            do
            {
                num_digits++;
                temp_count /= 10;
            } while (temp_count > 0);

            /* Allocate memory for the buffer */
            char *buffer = malloc(num_digits + 1);
            if (!buffer)
            {
                perror("Malloc failed");
                exit(EXIT_FAILURE);
            }

            /* Convert line_count to a string and store it in the buffer */
            buffer[num_digits] = '\0';
            temp_count = dataptr->line_count;
            char *buffer_ptr = buffer + num_digits - 1;

            while (temp_count > 0)
            {
                *buffer_ptr-- = (temp_count % 10) + '0';
                temp_count /= 10;
            }

            /* Print the error message */
            write(STDERR_FILENO, dataptr->program_name, _strlen(dataptr->program_name));
            write(STDERR_FILENO, ": ", 2);
            write(STDERR_FILENO, buffer, _strlen(buffer));
            write(STDERR_FILENO, ": exit: Illegal number: ", 24);
            write(STDERR_FILENO, exit_arg, _strlen(exit_arg));
            write(STDERR_FILENO, "\n", 1);

            /* Free allocated memory and exit */
            free(buffer);
            exit(2);
        }
    }
    return dataptr->last_status;
}
