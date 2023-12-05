#include "simple-shell.h"

/**
 * exit_command - Handle the "exit" command with an optional exit status.
 * @arg: The exit status argument (as a string) provided to the "exit" command.
 *
 */
void exit_command(char *arg)
{
	if (arg != NULL)
	{
		int exit_status = atoi(arg);

		exit(exit_status);
	}
	else
	{
		exit(0);
	}
}

