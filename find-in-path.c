#include "simple-shell.h"

/**
 *find_executable_in_path - Searches for an executable in the PATH
 *@command: The command to search for
 *Return: Full path to the executable, or NULL if not found
 */

char *find_executable_in_path(const char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *token, *full_path;
	size_t command_len, path_len;

	if (!path || access(command, X_OK) == 0)
	{
		return (_strdup(command));
	}

	path_copy = _strdup(path);
	if (!path_copy)
	{
		return (NULL);
	}

	command_len = _strlen(command);
	token = _strtok(path_copy, ":");

	while (token != NULL)
	{
		path_len = _strlen(token);
		full_path = malloc(path_len + command_len + 2);
		if (full_path)
		{
			_strcat(full_path, token);
           		 _strcat(full_path, "/");
           		 _strcat(full_path, command);

			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

