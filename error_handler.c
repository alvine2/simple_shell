#include "shell.h"

/**
 * error_printer - Print an error message when a command is not found.
 * @command: The command that was not found.
 * @dataptr: Pointer to the shell_t structure.
 * This function prints an error message to STDERR when a command is not found.
 * It includes the program name, line number, and the command that triggered
 * the error. After printing the error message, the function exits with an
 * exit status of 127.
 */
void error_printer(char *command, shell_t *dataptr)
{
	int num_digits = 0, temp_count = dataptr->line_count;
	char *buffer, *buffer_ptr;
/* Count the number of digits in the line count */
	do {
		num_digits++;
		temp_count /= 10;
	} while (temp_count > 0);

	buffer = malloc(num_digits + 1);
	if (!buffer)
	{
		perror("Malloc failed");
		exit(1);
	}
/* Allocate memory for the buffer */
	buffer[num_digits] = '\0';
	temp_count = dataptr->line_count;
	buffer_ptr = buffer + num_digits - 1;

	while (temp_count > 0)
	{
		*buffer_ptr-- = (temp_count % 10) + '0';
		temp_count /= 10;
	}
/* Set the null terminator for the buffer */
	write(STDERR_FILENO,
	      dataptr->program_name, _strlen(dataptr->program_name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, buffer, _strlen(buffer));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
/* Free allocated memory and exit with status 127 */
	free(buffer);
	exit(127);
}
