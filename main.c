#include "header.h"

int fd, cmd_history;
char *program_name;
int status_code;
char *line;



int main(int argc, char *argv[])
{
    char **cmd_array;
    // extern char *line;
    fd = STDIN_FILENO;
    program_name = argv[0];
    // cmd_history = 0;

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
        if (_is_interactive_mode(fd) == 0) /* False => cancel shell */
            break;
    }
    free_double_pointer(cmd_array);
    free(line);
    return 0;
}
