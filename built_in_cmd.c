#include "header.h"

int _putenv(char *str, char **envp);

/**
 * shell_exit - Implement the exit built-in, that exits the shell
 * @av: exit status code
 * Return: None
 */

/*
 * Usage: exit status
 * Exit the shell with a status code of 0 (success)
 */

void shell_exit(char **av)
{
	/* _exit(0); */
	/* get exit status value */
	char *_status = *(av + 1);
	/* convert into integer */
	int status = _atoi(_status);

	if (status)
		exit(status);
	exit(0);
}

/**
 * shell_env - display the current environment variables in a shell.
 * @envp: env variables
 * Return: None
 */

/*
 * Usage: env
 */


void shell_env(char **envp)
{
	int i = 0;

	while (envp[i] != NULL)
	{
		print_str(envp[i]);
		print_str("\n");
		i++;
	}
}


/**
 * _setenv - Sets the value of an environment variable or
 * creates a new one if it doesn't exist.
 * @variable: The var_name of the environment variable.
 * @value: The value to be assigned to the environment variable.
 * @envp: env variable
 * Return: Returns 0 on success or -1 on failure.
 */

/*
 * Usage: setenv VARIABLE VALUE
 */

int _setenv(char *variable, char *value, char **envp)
{
	int result;
	char *env;

	if (variable == NULL || value == NULL ||
		variable[0] == '\0' || _strchr(variable, '=') != NULL)
	{
		print_error("Error: Invalid arguments\n");
		return (-1);
	}

	/* Update or create the environment variable */
	/* +2 for '=' and '\0' */
	env = malloc(_strlen(variable) + _strlen(value) + 2);
	if (env == NULL)
	{
		print_error("setenv: Memory allocation failed");
		return (-1);
	}

	/* format: variable=value */
	_format(variable, value, env, "=");
	result = _putenv(env, envp);

	if (result != 0)
	{
		print_error("setenv: Failed to set the environment variable\n");
		free(env);
		return (-1);
	}
	return (0);
}

/**
 * _putenv - Sets the variable of an environment
 * @str: The var_name of the environment variable.
 * @envp: env variable
 * Return: Returns 0 on success or -1 on failure.
 */

/*
 * Usage: setenv VARIABLE VALUE
 */

int _putenv(char *str, char **envp)
{
	size_t len, key_len, environ_len, i;
	const char *sep;
	char *copy, **new_environ;
	int found;

	len = _strlen(str), sep = _strchr(str, '=');
	if (sep == NULL)
		return (-1);
	key_len = sep - str;
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (-1);
	_strcpy(copy, str);
	new_environ = NULL, found = 0, environ_len = _get_env_len(envp);
	new_environ = malloc((environ_len + 2) * sizeof(char *));
	if (new_environ == NULL)
	{
		free(copy);
		return (-1);
	}
	for (i = 0; i < environ_len; i++)
	{
		new_environ[i] = envp[i];
		if (_strncmp(envp[i], str, key_len) == 0 && envp[i][key_len] == '=')
		{
			free(envp[i]);
			envp[i] = copy;
			found = 1;
		}
	}
	if (!found)
	{
		/* The variable doesn't exist, add it to the environment */
		new_environ[environ_len] = copy;
		new_environ[environ_len + 1] = NULL;
		envp = new_environ;
	}
	else
		free(new_environ);
	return (0); /* Success */
}


/**
 * _unsetenv - unsets an environmental variable
 *
 * @variable: var_name of variable to be unset.
 * @envp: env variables
 * Return: 0 on success, -1 on fail
 *
 * note: the algorithm unsets by shifting all
 *        successive entries back one element.
 */


int _unsetenv(char *variable, char **envp)
{
	int len;
	char **ep, **sp;

	if (variable == NULL || variable[0] == '\0' || _strchr(variable, '=') != NULL)
	{
		print_error("Error: Invalid Arguments!\n");
		return (-1);
	}

	len = _strlen(variable);

	for (ep = envp; *ep;)
	{
		if (_strncmp(variable, *ep, len) == 0 && (*ep)[len] == '=')
		{
			sp = ep;
			free(*sp);
			for (sp = ep; *sp; sp++)
				*sp = *(sp + 1);
		}
		else
			ep++;
	}
	return (0);
}

/* your code here */
