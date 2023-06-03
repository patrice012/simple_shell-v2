#include "header.h"

#define MAX_ARG 100

void _error(char *str1, ...)
{
    char *temp, **args_array;
    int len, i = 0, j = 0;
    va_list ptr;

    va_start(ptr, str1);

    args_array = (char **)malloc(sizeof(char) * MAX_ARG);

    /* store the first arg into args_array */
    args_array[i] = (char *)malloc(sizeof(char) * strlen(str1) + 1);
    strcpy(args_array[i], str1);

    /* get and copy all optionals args */
    temp = va_arg(ptr, char *);
    i++;

    while (temp)
    {

        args_array[i] = (char *)malloc(sizeof(char) * strlen(temp) + 1);
        strcpy(args_array[i], temp);
        temp = va_arg(ptr, char *);
        i++;
    }
    /* add NULL ending character */
    args_array[i] = NULL;

    /* print args */
    while (args_array[j])
        print_stdout(args_array[j++]);
}

/**
 * permission_denied_error - print error message
 * @cmd: command name
 * Return: 1 for failure and 0 for success
 */
int  permission_denied_error(char *cmd)
{
    char *sep, *msg, *hist;
    sep = ": ";
    msg = "Permission denied\n";
    hist = _itoa(cmd_history);

    _error(program_name, sep, hist, sep, cmd, sep, msg, NULL);
}

/**
 * not_found_error - print error message
 * @cmd: command name
 * Return: 1 for failure and 0 for success
 */
int  not_found_error(char *cmd)
{
    char *sep, *msg, *hist;
    sep = ": ";
    msg = "command not found\n";
    hist = _itoa(cmd_history);

    _error(program_name, sep, hist, sep, cmd, sep, msg, NULL);
    // print_stdout(cmd);
    // print_stdout(": ");
    // print_stdout("command not found\n");
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
