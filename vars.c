#include "shell.h"

/**
 * is_chain - Determines if the current character in the buffer is a chain delimiter.
 * @info: The parameter struct.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 *
 * Return: 1 if it's a chain delimiter, 0 otherwise.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
    size_t j = *p;

    if (buf[j] == '|' && buf[j + 1] == '|')
    {
        buf[j] = 0;
        j++;
        info->cmd_buf_type = CMD_OR;
    }
    else if (buf[j] == '&' && buf[j + 1] == '&')
    {
        buf[j] = 0;
        j++;
        info->cmd_buf_type = CMD_AND;
    }
    else if (buf[j] == ';')
    {
        buf[j] = 0;
        info->cmd_buf_type = CMD_CHAIN;
    }
    else
        return (0);
    *p = j;
    return (1);
}

/**
 * check_chain - Checks whether we should continue chaining based on the last status.
 * @info: The parameter struct.
 * @buf: The character buffer.
 * @p: Address of the current position in buf.
 * @i: Starting position in buf.
 * @len: Length of buf.
 *
 * Return: Void.
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
    size_t j = *p;

    if (info->cmd_buf_type == CMD_AND)
    {
        if (info->status)
        {
            buf[i] = 0;
            j = len;
        }
    }
    if (info->cmd_buf_type == CMD_OR)
    {
        if (!info->status)
        {
            buf[i] = 0;
            j = len;
        }
    }

    *p = j;
}

/**
 * replace_string - Replaces a string.
 * @old: Address of the old string.
 * @new: New string.
 *
 * Return: 1 if replaced, 0 otherwise.
 */
int replace_string(char **old, char *new)
{
    free(*old);
    *old = new;
    return (1);
}
