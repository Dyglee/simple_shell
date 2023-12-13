#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 100

extern char **environ;
void process_command(char *input);
void print_env(void);
void executeCommand(char *const argv[]);
char *_strtok(char *str, const char *delim);
char *find_executable_in_path(const char *command);
char *_getenv(const char *name);
void exit_command(char *arg);
void setenv_command(const char *variable, const char *value);
void unsetenv_command(const char *variable);
void cd_command(char **args);
void handle_command_separator(char *input);
void execute_command(char **args);


#endif /* SIMPLE_SHELL_H */
