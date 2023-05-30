#include "header.h"

int fd;



int main(int argc, char const *argv[])
{
    char **cmd_array, *line = NULL;
    fd = STDIN_FILENO;
    int l;
   
   while (1)
   {
        display_prompt();
        line = get_input();
        line[strlen(line) - 1] = '\0';
        if (_is_valid(line) == 0)
        {
            perror("Invalid command");
            break;
        }
        /* need to free all array */
        cmd_array = (char **)malloc(sizeof(char *) * (strlen(line) + 1));
        to_array_of_cmds(line, cmd_array);
        process_cmd(line, cmd_array);
    }
    free_double_pointer(cmd_array);
    free(line);
    return 0;
}
