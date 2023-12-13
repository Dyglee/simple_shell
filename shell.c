#include "simple-shell.h"

/**
 * main - Entry point for the simple shell
 * Return: 0 on successful execution, or EOF .
 *
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		print_prompt("#cisfun$ ");
		read = getline(&input, &len, stdin);
		if (read == -1)
		{
		if (feof(stdin)) {
                print_string("\n");
            	}
			free(input);
			break; 
		}

		handle_command_separator(input);
	}
	return (0);
}
