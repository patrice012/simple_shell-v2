#include "header.h"

/**
 * _write - writte string to fd
 * @str: string to writte
 * @fd: file descriptor to use
 * Return: number of bytes written
 */
int _write(char *str, int fd)
{
    return (write(fd, str, strlen(str)));
}


/**
 * print_stdout - writte string into the standart output
 * @str: string to writte
 */
void print_stdout(char *str)
{
    _write(str, 1);
}


/**
 * print_strerror - writte string into the standart error output
 * @str: string to writte
 */
void print_stderror(char *str)
{
    _write(str, 2);
}

