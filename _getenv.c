#include "simple-shell.h"

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the environment variable, or NULL if not found
 *
 */

char *_getenv(const char *name)
{
	int i = 0;
	char *entry;
	char *delimiter;

	while ((entry = environ[i]) != NULL)
	{
		delimiter = strchr(entry, '=');
		if (delimiter != NULL)
		{
			int name_length = delimiter - entry;

			if (strncmp(entry, name, name_length) == 0 && name[name_length] == '\0')
			{
				return (delimiter + 1);
			}
		}
		i++;
	}
	return (NULL);
}

