#include "header.h"

pid_t create_process(void)
{
    pid_t id;

    id = fork();
    if (id == -1)
        perror("Failed to create new process");
    return (id);
}
