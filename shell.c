#include "simple-shell.h"


/**
 * main - Entry point for the simple shell
 * Return: 0 on successful execution, or EOF .
 * *
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			free(input);
			break; /* EOF or error */
		}

		handle_command_separator(input);
	}

	return (0);
}
