#include "simple-shell.h"

/**
 * process_command - Processes and executes a given command
 * @input: The command line input
 *
 */



void process_command(char *input)
{
	char *args[MAX_ARGS];
	char *token;
	const char *delim = " \t\n";
	int i = 0;

	token = _strtok(input, delim);

	while (token != NULL && i < MAX_ARGS - 1)
	{
		args[i++] = token;
		token = _strtok(NULL, delim);
	}
	args[i] = NULL;

	if (args[0] != NULL)
	{
		if (strcmp(args[0], "exit") == 0)
		{
		exit_command(args[1]);
		}
		if (strcmp(args[0], "env") == 0)
		{
			print_env();
			return;
		}
		if (strcmp(args[0], "cd") == 0)
		{
			cd_command(args);
		}
		else
		{	
			 execute_command(args);
		}
	}
}

