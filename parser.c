#include "header.h"


int to_array_of_cmds(char *line, char **cmd_array)
{
    char *delim = "&|"; /* "& | ; > >>" */
    int id;
    id = _tokenizer(line, delim, cmd_array);
    // printf("end to_array_of_cmds\n");
    return (id);

}


int process_cmd(char *line_buffer, char **cmd_array)
{
    char **av; /* free needed */
    int i = 0, cmd_status = 0;

    while (cmd_array[i])
    {
        // printf("cmd arr %s\n", cmd_array[i]);
        av = (char **)malloc(sizeof(char *) * (strlen(cmd_array[i]) + 1));
        parse_cmd(cmd_array[i], av);
        i++;
        cmd_status = execute_cmd(av);
        // printf("cmd_history:%d\n", cmd_history);
        // if (cmd_status == 1)
        //     break;
    }
    free_double_pointer(av);
    return (cmd_status);
}


int parse_cmd(char *cmd, char **av)
{
    char *delim = " ";
    int id;
    id = _tokenizer(cmd, delim, av);
    return (id);
}
