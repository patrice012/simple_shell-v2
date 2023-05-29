#include "header.h"


int to_array_of_cmds(char *line, char **cmd_array)
{
    char *token, *delim = "&|"; /* "& | ; > >>" */
    int id = 0;
    token = strtok(line, delim);
    while (token != NULL)
    {
        cmd_array[id] = (char *)malloc(sizeof(char) * strlen(token));
        cmd_array[id] = strdup(token);
        token = strtok(NULL, delim);
        id++;
    }
    cmd_array[id] =  NULL;
    // free(token);
    // free(delim);
    return (id);

}


int process_cmd(char *line_buffer, char **cmd_array)
{
    char **av = (char **)malloc(sizeof(char) * 1);
    int i = 0, j;

    while (cmd_array[i])
    {
        parse_cmd(cmd_array[i], av);
        i++;
        j = 0;
        while (av[j])
        {
            printf("cmd %d:%s\n",i, av[j]);
            j++;
        }
    }
    free_double_pointer(av);
}


int parse_cmd(char *cmd, char **av)
{
    char *delim = " ", *token = NULL;
    int id = 0;

    token = strtok(cmd, delim);
    while(token != NULL)
    {
        av[id] = (char *)malloc(sizeof(char) * strlen(token));
        av[id] = strdup(token);
        token = strtok(NULL, delim);
        id++;
    }
    av[id] = NULL;
}
