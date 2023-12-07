#include "simple-shell.h"

/**
 * handle_command_separator - Processes each command separated by ';'
 * @input: The command line input
 *
 * This function splits the input into separate commands using ';' as a delimiter,
 * and then processes each command individually.
 */
void handle_command_separator(char *input) {
    const char *separator = ";";
    char *command;
    char *rest = input;

    while ((command = strtok_r(rest, separator, &rest))) {
        process_command(command);
    }
}
