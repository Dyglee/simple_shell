#include "shell.h"

/**
 * get_history_file - Retrieves the path to the history file.
 * @info: Pointer to the info_t struct.
 *
 * Return: Allocated string containing the history file path or NULL on failure.
 */
char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}



/**
 * build_history_list - Adds an entry to a history linked list.
 * @info: Pointer to the info_t struct.
 * @buf: The command buffer.
 * @linecount: The history linecount (histcount).
 *
 * Return: Always 0.
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - Updates history line numbers after changes.
 * @info: Pointer to the info_t struct.
 *
 * Return: The new histcount.
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->histcount = i);
}

