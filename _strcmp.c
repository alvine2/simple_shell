#include "shell.h"

/**
 * _strcmp - compare two strings
 * @str1: The first string.
 * @str2: The second string.
 *
 * Return: 0 if equal, non-zero ASCII value difference if unequal.
 */

int _strcmp(const char *str1, const char *str2)
{
	int i = 0;

	while (str1[i] == str2[i])
	{
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (str1[i] - str2[i]);
}
