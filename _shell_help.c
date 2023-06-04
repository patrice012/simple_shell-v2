#include "header.h"

/**
 * _help - displays help information for built-in commands
 * Return: 0 for success and 1 for failure
 */
int _help(char **args __attribute__((unused)))
{
	print_stdout("\nALX Simple Shell\n\n");
	print_stdout("Usage: ./hsh for interactive mode\n\n");
	print_stdout("Usage: commands | ./hsh for non-interactive mode\n\n");
	print_stdout("Shell built-in commands:\n\n");
	print_stdout("help\t\tDisplay this help information\n\n");
	print_stdout("cd [dir]\tChange the current working directory\n\n");
	print_stdout("env\t\tDisplay the environment variables\n\n");
	print_stdout("setenv\t\tSet an environment variable\n\n");
	print_stdout("unsetenv\tUnset an environment variable\n\n");
	print_stdout("exit\t\tExit the shell\n\n");
	return (0);
}
