#include "header.h"

int fd;
const char *program_name;



int main(int argc, char const *argv[])
{
    char **cmd_array, *line = NULL;
    fd = STDIN_FILENO;
    program_name = argv[0];
   
   while (1)
   {
        if (_is_interactive_mode(fd) == 1)
            display_prompt();
        line = get_input();
        line[strlen(line) - 1] = '\0';
        
        if (_is_valid(line) == 1)
        {
            /* need to free all array */
            cmd_array = (char **)malloc(sizeof(char *) * (strlen(line) + 1));
            to_array_of_cmds(line, cmd_array);
            process_cmd(line, cmd_array); 
        }
        else
            continue;/* no input => prompt shell again */
        if (_is_interactive_mode(fd) == 0) /* cancel shell */
            break;
    }
    free_double_pointer(cmd_array);
    free(line);
    return 0;
}
