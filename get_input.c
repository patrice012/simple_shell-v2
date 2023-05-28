#include "header.h"


char *get_input(void)
{
    char *line_buffer = NULL;
    size_t line_size = 0;
    ssize_t read;

    read = getline(&line_buffer, &line_size, stdin);
    if (read == -1)
        perror("getline");
    return (line_buffer);
}


int _is_valid(char *str)
{
    if (str[0] == '\0')
        return (0);
    return (1);
}
