#include "header.h"

/**
 * _setenv - Set the value of an environment variable
 * @name: Argument name
 * @value: argument value
 *
 * Return: Nothing
 */
int _setenv(char **args)
{
	char *name = args[1], *value = args[2];

	if (name == NULL || value == NULL || name[0] == '\0'
		|| strchr(name, '=') != NULL)
	{
		print_stderror("Error: Invalid Arguments!\n");
		return (-1);
	}
	if (setenv(name, value, 1) != 0)
	{
		print_stderror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @name: variable name
 *
 * Return: Nothing
 */
int _unsetenv(char **args)
{
	char *name = args[1];
	
	if (name == NULL)
	{
		print_stderror("Error: Invalid Arguments!\n");
		return (-1);
	}
	if (unsetenv(name) != 0)
		print_stderror("unsetenv");
	return (0);
}
