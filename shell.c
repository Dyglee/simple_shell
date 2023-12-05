#include "simple-shell.h"


/**
 * main - Entry point for the simple shell
 * Return: 0 on successful execution
 *
 */

int main(void)
{
        char input[100];

        while (1)
        {
                printf("#cisfun$ ");
                if (fgets(input, sizeof(input), stdin) == NULL)
                {
                        break;
                }
                process_command(input);
        }
        return (0);
}
