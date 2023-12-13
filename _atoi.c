#include "shell.h"

/**
 * interactive - returns true if the shell is in interactive mode
 * @info: a pointer to the info_t struct
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if a character is a delimiter
 * @c: the character to check
 * @delimiter: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delimiter)
{
	while (*delimiter)
		if (*delimiter++ == c)
			return (1);
	return (0);
}

/**
 * is_alpha - checks for an alphabetic character
 * @c: The character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int is_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in the string, the converted number otherwise
 */
int _atoi(char *str)
{
	int index, sign = 1, flag = 0, result = 0;

	for (index = 0;  str[index] != '\0' && flag != 2; index++)
	{
		if (str[index] == '-')
			sign *= -1;

		if (str[index] >= '0' && str[index] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -result;

	return (result);
}

