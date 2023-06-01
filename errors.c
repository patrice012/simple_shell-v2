#include "header.h"

/**
 * permission_denied_error - print error message
 * @cmd: command name
 * Return: 1 for failure and 0 for success
 */
int  permission_denied_error(char *cmd)
{
    print_stdout(program_name);
    print_stdout(": ");
    print_stdout(cmd);
    print_stdout(": ");
    print_stdout("Permission denied\n");
    // exit(0);
}

/**
 * not_found_error - print error message
 * @cmd: command name
 * Return: 1 for failure and 0 for success
 */
int  not_found_error(char *cmd)
{
    print_stdout(cmd);
    print_stdout(": ");
    print_stdout("command not found\n");
}

/**
 * execption_error - print error message
 * @cmd: command name
 * Return: 1 for failure and 0 for success
 */
int  execption_error(void)
{
    /* code */
}
