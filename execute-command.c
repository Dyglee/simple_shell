#include "simple-shell.h"


/**
 * execute_command - Executes a given command
 * @args: An array of arguments where args[0] is the command
 *
 */

void execute_command(char **args)
{
	char *executable_path;

	executable_path = find_executable_in_path(args[0]);
	if (executable_path)
	{
		args[0] = executable_path;
		executeCommand(args);
		free(executable_path);
	}
	else
	{
	print_string(args[0]);
        print_string(": command not found\n");
	}
}
