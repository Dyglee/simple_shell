#include "simple-shell.h"

/**
 * _getenv - Retrieves the value of an environment variable
 * @name: Name of the environment variable
 * Return: Value of the environment variable, or NULL if not found
 */
char *_getenv(const char *name)
{
    int i = 0, j;
    char *env_var, *env_value;

    while (environ[i])
    {
        env_var = environ[i];
        for (j = 0; env_var[j] != '='; j++)
        {
            if (env_var[j] == '\0' || name[j] == '\0' || env_var[j] != name[j])
                break;
        }

        if (env_var[j] == '=' && name[j] == '\0')
        {
            env_value = &env_var[j + 1];
            return env_value;
        }

        i++;
    }

    return NULL;
}

