#include "shell.h"

/**
 * _strncmp - Compare the first n characters of two strings.
 * @s1: First string  to compare.
 * @s2: Second string to compare.
 * @n:  Number of characters to compare.
 *
 * Return:  Integer value based on the comparison.
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}

		if (*s1 == '\0')
		{
			return (0);
		}

		s1++;
		s2++;
		n--;
	}

	return (0);
}
