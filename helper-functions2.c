#include "simple-shell.h"

/**
 * _strlen - Custom implementation of strlen
 * @s: String to calculate the length of
 * Return: Length of the string
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length] != '\0')
		length++;

	return (length);
}

/**
 * _strdup - Custom implementation of strdup
 * @s: String to be duplicated
 * Return: Pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	char *dup;
	int i, len = _strlen(s);

	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[len] = '\0';

	return (dup);
}

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
		if (_strchr(delim, ch) == NULL)
		{
			break;
		}
	}
	--str;
	lasts = str + _strcspn(str, delim);
	if (*lasts != '\0')
	{
		*lasts = '\0';
		lasts++;
	}
	return (str);
}

/**
 * _strchr - Locates a character in a string
 * @s: String to search
 * @c: Character to find
 * Return: Pointer to the first occurrence of the character in the string
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

/**
 * _strcspn - Scans a string for the first occurrence of any of the characters in another string
 * @s: String to be scanned
 * @reject: String containing the characters to match
 * Return: Number of characters in the initial segment of s
 */
size_t _strcspn(const char *s, const char *reject)
{
	const char *p, *r;
	size_t count = 0;

	for (p = s; *p != '\0'; ++p)
	{
		for (r = reject; *r != '\0'; ++r)
		{
			if (*p == *r)
				return (count);
		}
		count++;
	}
	return (count);
}

