#include "shell.h"

/**
 * _strchr - Finds the first occurrence of a specific character in a string.
 * @s: pointer to the given string.
 * @c: The character to find.
 *
 * Return: Pointer to the first occurrence of @c in @s, or NULL if not found.
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);

	s++;
	}
	return (NULL);
}
