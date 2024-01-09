#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @nptr: The string to be converted.
 *
 * Description: This function takes a string @nptr and converts it to an integer.
 * It skips leading whitespace characters and considers an optional sign ('+' or '-').
 * The conversion stops when a non-digit character is encountered.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(const char *nptr)
{
    int i = 0;
    int result = 0;
    int sign = 1;

    if (nptr == NULL)
    {
        return (0);
    }

    /* Skip leading whitespaces*/
    while (nptr[i] == ' ')
    {
        i++;
    }

    // Handle optional sign
    if (nptr[i] == '-' || nptr[i] == '+')
    {
        if (nptr[i] == '-')
        {
            sign = -1;
        }
        i++;
    }

    // Convert digits to integer
    while (nptr[i] >= '0' && nptr[i] <= '9')
    {
        result = result * 10 + (nptr[i] - '0');
        i++;
    }

    return (sign * result);
}
