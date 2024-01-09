#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: The string to which @src will be appended.
 * @src:  The string to append to @dest.
 * Return: A pointer to @dest.
*/

char *_strcat(char *dest, const char *src)
{
	int i = 0;
	int j = 0;

	while (dest[i])
		i++;
	while (src[j])
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
