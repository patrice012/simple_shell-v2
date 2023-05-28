#include "header.h"

int fd;



int main(int argc, char const *argv[])
{
    char *line = NULL;

    fd = STDIN_FILENO;
    display_prompt();
    line = get_input();
    line[strlen(line) - 1] = '\0';
    printf("this is line:%s for length: %ld\n", line, strlen(line));
    return 0;
}
