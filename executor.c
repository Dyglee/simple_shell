
#include "simple-shell.h"

/**
 * executeCommand - Executes a command
 * @argv: Null-terminated array of strings
 */
void executeCommand(char *const argv[])
{
    pid_t pid;
    int status;
    char *command = argv[0];
    char *full_path = find_executable_in_path(command);

    if (full_path == NULL)
    {
        perror("Command not found");
        return;
    }

    pid = fork();

    if (pid == 0)
    {
        if (execve(argv[0], argv, NULL) == -1)
{
    perror("execve");
    _exit(EXIT_FAILURE);
}

    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
    }
    else
    {
        perror("fork");
    }

free(full_path);
}

