#include "shell.h"

/**
 * _strcpy - Copies a string to a buffer.
 * @dest: The destination buffer.
 * @src: The source string.
 *
 * Return: A pointer to the destination buffer `dest`.
 */
char *_strcpy(char *dest, const char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    dest[i] = '\0';

    return dest;
}
