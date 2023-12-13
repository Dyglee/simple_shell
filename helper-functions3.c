#include "simple-shell.h"

/**
 * _strcat - Concatenates two strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the resulting string dest
 */
char *_strcat(char *dest, const char *src)
{
    int dest_len = _strlen(dest);
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}

/**
 * _atoi - Convert a string to an integer.
 * @s: The string to be converted
 * Return: The integer value of the string
 */
int _atoi(char *s)
{
    int i = 0, sign = 1, result = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
        i++;

 
    if (s[i] == '-' || s[i] == '+')
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return result * sign;
}
