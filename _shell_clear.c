#include "header.h"

/**
 * _clear - clears the terminal screen.
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
*/
int _clear(char **args __attribute__((unused)))
{
	print_stdout("\033[2J\033[H");
	return (1);
}
