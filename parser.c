#include "header.h"


int to_array_of_cmds(char *line, char **cmd_array)
{
    char *delim = "&|"; /* "& | ; > >>" */
    int id;
    id = _tokenizer(line, delim, cmd_array);
    return (id);

}


int process_cmd(char *line_buffer, char **cmd_array)
{
    char **av; /* free needed */
    int i = 0, j;

    while (cmd_array[i])
    {
        printf("cmd arr %s\n", cmd_array[i]);
        av = (char **)malloc(sizeof(char *) * (strlen(cmd_array[i]) + 1));
        parse_cmd(cmd_array[i], av);
        i++;
        execute_cmd(av);
    }
    free_double_pointer(av);
}


int parse_cmd(char *cmd, char **av)
{
    char *delim = " ";
    int id;
    id = _tokenizer(cmd, delim, av);
    return (id);
}
