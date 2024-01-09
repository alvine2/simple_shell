#include "shell.h"

/**
 * read_line - Read a line of input from the user.
 * @line: A pointer to the buffer for the line.
 * @len: A pointer to the size of the buffer.
 * This function reads a line of input from the user and stores it in the
 * provided buffer. The buffer should be pre-allocated, and the size of the
 * buffer should be provided via the len parameter. The function reads input
 * until a newline character is encountered or the buffer is full. It null-
 * terminates the string and updates the len parameter with the number of
 * characters read.
 */
void read_line(char **line, size_t *len)
{
	ssize_t nread = getline(line, len, stdin);

	if (nread == -1)
	{
		if (*line)
		{
			free(*line);
			*line = NULL;
		}

		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}

		exit(0);
	}

}

/**
 * check_exit_command - Check if the user entered an "exit" command.
 * @line: The input line to check.
 * @dataptr: A pointer to the shell data.
 *
 * This function checks if the given input line corresponds to the "exit"
 * command. If the command is "exit," it returns 1; otherwise, it returns 0.
 * Return: 1 if the command is "exit," otherwise 0.
 */
int check_exit_command(char *line, shell_t *dataptr)
{
	int exit_status;

	if (strncmp(line, "exit", 4) == 0)
	{
		exit_status = handle_exit(line, dataptr);
		free(line);
		exit(exit_status);
	}
	return (0);
}

/**
 * execute_command - Execute a command in a new process.
 * @args: An array of command arguments.
 * @full_path: The full path to the executable.
 *
 * This function takes an array of command arguments @args and the full path
 * to the executable @full_path, then executes the command in a new process.
 * It returns the exit status of the command.
 *
 * Return: The exit status of the command.
 */
int execute_command(char **args, char *full_path)
{
	int status;
	pid_t pid = fork();

	if (pid == 0)
	{
		execve(full_path, args, environ);
		free(full_path);
		free(args);
		exit(1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			return (WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			return (WTERMSIG(status) + 128);
		}
	}
	return (0);
}

/**
 * handle_input - Handle user input.
 * @dataptr: A pointer to the shell data.
 * @line: The input line.
 * @arg_count: The maximum number of parse.
 * This function takes user input @line and processes it within the context of
 * the shell, using the provided shell data @dataptr. It also specifies the
 * maximum number of arguments to parse with @arg_count. The function performs
 * necessary actions such as parsing, executing, and handling commands based
 * on the user input.
 */
void handle_input(shell_t *dataptr, char *line, int arg_count)
{
	char *full_path;
	char **args = parse_input(line, arg_count);
	int last_status = 0;

	if (args[0] != NULL)
	{
		if (strcmp(args[0], "env") == 0)
		{
			print_env();
		}
		else
		{
			full_path = search_path(args[0], dataptr);
			if (full_path != NULL)
			{
				last_status = execute_command(args, full_path);
				free(full_path);
			}
			else
			{
				error_printer(args[0], dataptr);
			}
		}
	}

	free(args);
	dataptr->last_status = last_status;
}
