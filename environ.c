#include "shell.h"

/**
 * _myenv - Display the current environment using _myenv.
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
    print_list_str(info->env);
    return (0);
}

/**
 * _getenv - Get the value of an environ variable using _getenv.
 * @info: Structure containing potential arguments. Used to maintain
 *           constant function prototype.
 * @name: Environ variable name.
 * Return: The value of the environ variable.
 */
char *_getenv(info_t *info, const char *name)
{
    list_t *node = info->env;
    char *p;

    while (node)
    {
        p = starts_with(node->str, name);
        if (p && *p)
            return (p);
        node = node->next;
    }
    return (NULL);
}


/**
 * populate_env_list - Populate the linked list with environment variables using populate_env_list.
 * @info: Structure containing potential arguments. Used to maintain
 *                      constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
    list_t *node = NULL;
    size_t i;

    for (i = 0; environ[i]; i++)
        add_node_end(&node, environ[i], 0);
    info->env = node;
    return (0);
}

