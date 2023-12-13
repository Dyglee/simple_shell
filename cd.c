#include "simple-shell.h"

/**
 * cd_command - Changes the current directory of the process
 * @args: Arguments array where args[0] is "cd" and args[1] is the directory
 *
 *
 */

void cd_command(char **args)
{
	char *new_dir = args[1];
	char old_dir[1024];
	char *home_dir = getenv("HOME");
	char *prev_dir = getenv("OLDPWD");
	char new_pwd[1024];

	if (!getcwd(old_dir, sizeof(old_dir)))
	{
		perror("getcwd error");
		return;
	}

	if (new_dir == NULL)
	{
		new_dir = home_dir;
	}
	else if (_strcmp(new_dir, "-") == 0)
	{
		new_dir = prev_dir;
		printf("%s\n", new_dir);
	}

	if (chdir(new_dir) != 0)
	{
		perror("cd error");
		return;
	}

	if (!getcwd(new_pwd, sizeof(new_pwd)))
	{
		perror("getcwd error");
		return;
	}

	setenv("OLDPWD", old_dir, 1);
	setenv("PWD", new_pwd, 1);
}
