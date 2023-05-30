#include "header.h"

pid_t create_process(void)
{
    pid_t id;

    id = fork();
    if (id == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    return (id);
}
