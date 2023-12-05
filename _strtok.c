#include "simple-shell.h"

/**
 * _strtok - Custom implementation of strtok
 * @str: The string to be tokenized
 * @delim: The delimiter characters
 * Return: Pointer to the next token or NULL if there are no more tokens
 */

char *_strtok(char *str, const char *delim)
{
	static char *lasts;
	int ch;

	if (str == NULL)
	{
		str = lasts;
	}
	while (1)
	{
		ch = *str++;
		if (ch == '\0')
		{
			return (NULL);
		}
		if (strchr(delim, ch) == NULL)
		{
			break;
		}
	}
	--str;
	lasts = str + strcspn(str, delim);
	if (*lasts != '\0')
	{
		*lasts = '\0';
		lasts++;
	}
	return (str);
}
