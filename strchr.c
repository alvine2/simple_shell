#include "shell.h"

/**
 * _strchr - Locate character in string.
 * @s: The string to search.
 * @c: The character to locate.
 *
 * Return: If c is found - a pointer to the first occurrence.
 *         If c is not found - NULL.
 */
char *_strchr(const char *s, int c)
{
    if (s == NULL)
        return NULL;

    while (*s != '\0')
    {
        if (*s == c)
            return (char *)s;

        s++;
    }

    if (c == '\0')
        return (char *)s;

    return NULL;
}
