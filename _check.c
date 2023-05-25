 #include "header.h"


/**
 * check_for_builtin - checks if the command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_for_builtin(char **args)
{
	if (!args[0])
		return (0);
	if (!_strcmp(args[0], "exit"))
		shell_exit(args);
	else if (!_strcmp(args[0], "env"))
		_env();
	else if (!_strcmp(args[0], "setenv"))
		_setenv(args);
	else if (!_strcmp(args[0], "unsetenv"))
		_unsetenv(args);
	else if (!_strcmp(args[0], "help"))
		_help();
	else if (!_strcmp(args[0], "cd"))
		_cd(args);
	else if (!_strcmp(args[0], "clear"))
		_clear(args);
	else
		return (0);
	return (1);
}
