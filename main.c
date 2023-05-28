#include "header.h"

int fd;



int main(int argc, char const *argv[])
{
    char *line = NULL;
    fd = STDIN_FILENO;
   
   while (1)
   {
         display_prompt();
        line = get_input();
        line[strlen(line) - 1] = '\0';
        if (_is_valid(line) == 0)
            perror("Invalid command");
        int i = get_all_command(line);
        printf("value of i:%d\n", i);
        /* process input */
    }
    return 0;
}
