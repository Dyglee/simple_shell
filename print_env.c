#include "simple-shell.h"

/**
 * print_env - Prints the current environment
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
