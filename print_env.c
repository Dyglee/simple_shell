#include "simple-shell.h"

/**
 *print_env - Print the current environment
 *
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
