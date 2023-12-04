#include "simple-shell.h"

void executeCommand(char *const argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0) {
		if (execve(argv[0], argv, NULL) == -1) {
			perror("execve");
			_exit(EXIT_FAILURE);
		}

	} else if (pid > 0) {
		waitpid(pid, &status, 0);
	} else {
		perror("fork");
	}
}

