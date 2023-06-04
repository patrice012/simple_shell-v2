#include "header.h"

/**
 * _env - prints all environmental variables.
 */
int _env(char **args __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		if (!environ[i])
			return (1);
		print_stdout(environ[i]);
		print_stdout("\n");
	}
	return (0);
}
