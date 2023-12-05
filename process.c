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
	char *executable_path;
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

		executable_path = find_executable_in_path(args[0]);
		if (executable_path)
		{
			args[0] = executable_path;
			executeCommand(args);
			free(executable_path);
		}
		else
		{
			fprintf(stderr, "%s: command not found\n", args[0]);
		}
	}
}

