#include "header.h"

/**
 * exit_shell - clears all allocated memory and
 * exits the shell
 *
 * @line_buffer: the buffer that contains the command and it's arguments
 * @argv: array of strings
 *
 * Return: 0 on sucess, 2 on failure
 */
int exit_shell(char **args)
{
	char *line_buffer = line;
	char **argv  = args;
	
	int status = 0;

	if (argv[1] == NULL)
		status = status_code;
	else if (!is_numeric(argv[1]))
	{
		// error_exit(argv[1]);
		return (2);
	}
	else
	{
		status = atoi(argv[1]);
		if (status < 0)
		{
			// error_exit(argv[1]);
			return (2);
		}
		status %= 256;
	}
	free_double_pointer(argv);
	// free_env();
	free(line_buffer);

	exit(status);
	return (0);
}
