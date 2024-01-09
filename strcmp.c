#include "shell.h"

/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: 0 if the strings are equal, positive difference if str1 is greater,
 *         negative difference if str2 is greater.
 */
int _strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str1 == *str2)
    {
        str1++;
        str2++;
    }

    return (*str1 - *str2);
}
