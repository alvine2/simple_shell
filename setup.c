#include "shell.h"

/**
 * prompt_user - Display a shell prompt for interactive mode.
 * @interactive:  Flag for interactive shell mode.
 */
void prompt_user(int interactive)
{
	if (interactive)
	{
		write(STDOUT_FILENO, "#SimpleShell$ ", 14);
		fflush(stdout);
	}
}

/**
 * handle_exit - Handle the 'exit' command with optional exit status.
 * @line: User input containing the 'exit' command and optional status.
 * @dataptr: Pointer to the shell_t structure.
 *
 * Return: Exit status provided in 'exit' command.
 */
int handle_exit(char *line, shell_t *dataptr)
{
	char buffer[12], *buffer_ptr = buffer, *exit_arg = strtok(line, " \n");

	exit_arg = strtok(NULL, " \n");
	if (exit_arg != NULL)
	{
		char *endptr;
		long exit_status = strtol(exit_arg, &endptr, 10);

		if (*endptr == '\0' && exit_status >= 0 && exit_status
		    <= INT_MAX)
		{
			return ((int)exit_status);
		}
		else
		{
			int num_digits = 0, temp_count = dataptr->line_count;

			do {
				num_digits++;
				temp_count /= 10;
			} while (temp_count > 0);
			buffer_ptr += num_digits;
			*buffer_ptr-- = '\0';
			temp_count = dataptr->line_count;
			while (temp_count > 0)
			{
				*buffer_ptr-- = (temp_count % 10) + '0';
				temp_count /= 10;
			}
			write(STDERR_FILENO, dataptr->program_name,
			      strlen(dataptr->program_name));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, buffer, strlen(buffer));
			write(STDERR_FILENO, ": exit: Illegal number: ", 24);
			write(STDERR_FILENO, exit_arg, strlen(exit_arg));
			write(STDERR_FILENO, "\n", 1);
			return (2);
		}
	}
	return (dataptr->last_status);
}

/**
 * parse_input - Tokenize input line into an array of arguments.
 * @line: Input to tokenize.
 * @arg_count: Maximum number of arguments.
 *
 * Return: An array of pointers to argument strings.
 */
char **parse_input(char *line, int arg_count)
{
	int i = 0;
	char *token;
	char **args = malloc(arg_count * sizeof(char *));

	if (args == NULL)
	{
		perror("Unable to allocate memory for args");
		free(line);
		exit(1);
	}

	token = strtok(line, " \n");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * search_path - Search for the full path of a command in the PATH environment.
 * @command:  command to search for.
 * @dataptr: Pointer to the shell_t structure.
 *
 * Return:  full path of the command if found, or NULL if not found.
 */
char *search_path(char *command, shell_t *dataptr)
{
	char *path_copy;
	char *tok;
	char *full_path;

	if (strchr(command, '/') != NULL && access(command, X_OK) == 0)
		return (strdup(command));
	if (dataptr->path == NULL)
		return (NULL);
	path_copy = strdup(dataptr->path);
	if (!path_copy)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	full_path = NULL;
	tok = strtok(path_copy, ":");
	while (tok != NULL)
	{
		full_path = malloc(strlen(tok) + strlen(command) + 2);
		if (!full_path)
		{
			perror("Memory allocation failed");
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, tok);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		tok = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

/**
 * setup_shell - Initialize shell_t structure and set up signal handler.
 * @dataptr: Pointer to the shell_t structure to initialize.
 * @argv: Command-line arguments.
 */
void setup_shell(shell_t *dataptr, char **argv)
{
	dataptr->program_name = argv[0];
	dataptr->line_count = 0;
	dataptr->path = getenv("PATH");
	dataptr->last_status = 0;
	signal(SIGINT, sigint_handler);
}
