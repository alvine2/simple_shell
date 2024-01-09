#include "shell.h"

/**
 * _strlen - Returns the length of a string
 * @str: String
 *
 * Return: Length of string
 */

size_t _strlen(const char *str)
{
	size_t l = 0;

	while (*str != '\0')
	{
		l++;
		str++;
	}
	return (l);
}
