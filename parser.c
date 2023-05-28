#include "header.h"


int get_all_command(char *line)
{
    char *token, *delim = "&|"; /* "&|;>" */
    int id = 0, i = 1;
    char **arr_cmd = (char **)malloc(sizeof(char) * i);;

    token = strtok(line, delim);
    while (token != NULL)
    {
        arr_cmd[id] = token;
        token = strtok(NULL, delim);
        id++;
        i++;
        arr_cmd = (char **)realloc(arr_cmd, i + 1);
    }
    arr_cmd[id] =  NULL;
    return (id);

}
