#include "shell.h"

/**
 * _strncmp - Compares the first n characters of two strings, s1 and s2.
 * @s1: A pointer to the first string to compare.
 * @s2: A pointer to the second string to compare.
 * @n: The maximum number of characters to compare.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 *         respectively, to be less than, to match, or be greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    while (n > 0)
    {
        if (*s1 != *s2 || *s1 == '\0')
        {
            return (*s1 - *s2);
        }

        s1++;
        s2++;
        n--;
    }

    return 0;
}
