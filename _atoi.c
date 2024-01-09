#include "shell.h"

/**
 * _atoi - Converts a string to an integer.
 * @nptr: The string to be converted.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(const char *nptr)
{
	int i = 0;
	int result = 0;
	int sign = 1;

/*check for null pointer */
	if (nptr == NULL)
	{
		return (0);
	}
/*skip leading spaces*/
	while (nptr[i] == ' ')
	{
		i++;
	}
/*handle sign*/
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
/*convert string to integer*/
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}

	return (sign * result);
}
