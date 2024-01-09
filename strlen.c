#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @str: The string to find the length of.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
    size_t length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}
