#include "header.h"


/**
 * change_directory - changes the directory of the process
 *
 * @dir: string - new directory
 *
 * Return: 0 on sucess, 1 on failure
 */
int change_directory(char **args)
{
	char *dir = args[1];

	char cwd[PATH_MAX];
	char *av1[2] = {"OLDPWD", getenv("PWD")};
	char *av2[2] = {"PWD", getcwd(cwd, sizeof(cwd))};

	if (dir == NULL || *dir == '\0')
	{
		dir = strdup(getenv("HOME"));
		if (dir == NULL)
			dir = strdup(getenv("PWD"));
	}
	else if (strcmp(dir, "-") == 0)
	{
		dir = strdup(getenv("OLDPWD"));
		if (dir == NULL)
			dir = strdup(getenv("PWD"));

		print_stdout(dir);
		print_stdout("\n");
	}
	else
		dir = strdup(dir);
	
	if (_setenv(av1) == -1)
	{
		print_stderror("Failed to update OLDPWD env variable");
		return (2);
	}
	if (chdir(dir) == -1)
	{
		// error_cd(dir);
		// free(dir);
		return (2);
	}
	// free(dir);
	if (_setenv(av2) == -1)
	{
		print_stderror("Failed to update PWD env variable");
		return (2);
	}
	return (0);
}

