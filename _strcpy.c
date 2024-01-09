#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src to dest
 * @dest: Destination string
 * @src: Source string
 *
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
