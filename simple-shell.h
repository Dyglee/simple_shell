#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void executeCommand(char *const argv[]);
char *_strtok(char *str, const char *delim);
char *find_executable_in_path(const char *command);
char *_getenv(const char *name);
	
#endif /* SIMPLE_SHELL_H */
