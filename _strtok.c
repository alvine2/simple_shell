#include "shell.h"

/**
 * _strtok -  Split a string into tokens.
 * @str: String to be tokenized.
 * @delim: Delimiter character(s).
 *
 * Return: Pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delim)
{
	static char *next;
	char *token;

	if (str != NULL)
		next = str;

	if (next == NULL)
		return (NULL);

	while (*next != '\0' && _strchr(delim, *next) != NULL)
		next++;

	if (*next == '\0')
	{
		next = NULL;
		return (NULL);
	}
	token = next;

	while (*next != '\0' && _strchr(delim, *next) == NULL)
	{
		next++;
	}
	if (*next != '\0')
		*next++ = '\0';

	return (token);
}
