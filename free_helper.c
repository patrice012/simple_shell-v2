#include "header.h"

/**
 * free_pointer - free all pointers
 * @ptr: first pointer to free
 * @...: variable arguments, terminated by a NULL pointer
 * the last argument should be NULL - Mandatory
 * Return: 0 if success and -1 if fail
 */

int free_pointer(char *ptr, ...)
{
    va_list arg;
    char *tmp;

    va_start(arg, ptr);
    tmp = ptr;
    while(tmp != NULL)
    {
        free(tmp);
        tmp = va_arg(arg, char *);
    }
    tmp = NULL;
    va_end(arg);
    return (0);

}

/**
 * free_double_pointer - free all elements in array
 * @av: array to free
 * Return: void
 */

void free_double_pointer(char **av)
{
    int i = 0;

    while (av[i] != NULL)
    {
        free(av[i]);
        i++;
    }
    free(av);
    av = NULL;
}
