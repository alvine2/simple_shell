#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
        return dest;

    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';

    return dest;
}
