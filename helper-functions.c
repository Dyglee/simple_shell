#include "simple-shell.h"

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 * _strncmp - Compare two strings up to a given number of characters
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if the strings are equal for the first 'n' characters,
 *         an integer greater than 0 if 's1' is greater than 's2',
 *         an integer less than 0 if 's1' is less than 's2'.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    if (n == 0)
        return 0;

    while (*s1 && (*s1 == *s2) && (n > 1))
    {
        s1++;
        s2++;
        n--;
    }

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}


/**
 * print_string - Custom function to print a string followed by a newline
 * @str: The string to print
 *
 * Return: On success, returns the number of characters written.
 *         On error, returns -1 and sets errno.
 */
ssize_t print_string(const char *str)
{
    ssize_t bytes_written = 0;

    if (str == NULL)
        return -1;

    while (str[bytes_written])
    {
        if (write(STDOUT_FILENO, &str[bytes_written], 1) == -1)
            return -1;
        bytes_written++;
    }

    if (write(STDOUT_FILENO,"\n",1) == -1)
        return -1;

    return bytes_written + 1;
}

/**
 * print_prompt - Custom function to print a string followed by a newline
 * @str: The string to print
 *
 * Return: On success, returns the number of characters written.
 *         On error, returns -1 and sets errno.
 */
ssize_t print_prompt(const char *str)
{
    ssize_t bytes_written = 0;

    if (str == NULL)
        return -1;

    while (str[bytes_written])
    {
        if (write(STDOUT_FILENO, &str[bytes_written], 1) == -1)
            return -1;
        bytes_written++;
    }

    if (write(STDOUT_FILENO,"",1) == -1)
        return -1;

    return bytes_written + 1;
}
