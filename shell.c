#include "simple-shell.h"

#define MAX_ARGS 64

extern char **environ;

/**
 * main - Entry point for the simple shell
 * Return: 0 on successful execution
 */
int main(void)
{
	char input[100];
	char *args[MAX_ARGS];
	char *token;
	const char *delim = " \t\n";
	char *executable_path;
	int i;
	int j;
	while (1) {
		printf("#cisfun$ ");
		if (fgets(input, sizeof(input), stdin) == NULL)
			break;
	i = 0;

		token = _strtok(input, delim);
		while (token != NULL && i < MAX_ARGS - 1) {
			args[i++] = token;
			token = _strtok(NULL, delim);
		}
		args[i] = NULL;

		    if (args[0] != NULL) {
        if (strcmp(args[0], "exit") == 0)
            break;
	            if (strcmp(args[0], "env") == 0) {
                for (j = 0; environ[j] != NULL; j++) {
                    printf("%s\n", environ[j]);
                }
                continue;
            }
        executable_path = find_executable_in_path(args[0]);
        if (executable_path) {
            args[0] = executable_path;
            executeCommand(args);
            free(executable_path);
        } else {
            fprintf(stderr, "%s: command not found\n", args[0]);
        }
    }
	}
	return (0);
}
