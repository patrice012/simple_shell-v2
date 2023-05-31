#include "header.h"


int execute_cmd(char **args)
{
    int cmd_status = 1;

    /* free path after */
    char *path = get_cmd_path(args[0]); /* check if path is null*/
    if (path == NULL)
    {
        /* display command not found error message */
        perror(program_name);
        return (cmd_status); /* 0 for success and 1 for failure */
    }
    /* run system cmd */
    cmd_status = execute_system_cmd(args, path);
    cmd_history++;
    return (cmd_status);

}



int execute_system_cmd(char **args, char *path)
{
    pid_t child_pid;
    int _status, child_status = -1;

    child_pid = create_process();
    /* create argv and envp array */
    if (child_pid == 0)
    {
        _status = execve(path, args, environ);
        if (_status == -1)
        {
            perror(program_name);
            exit(EXIT_FAILURE);
        }
    }
    else if (child_pid > 0)
        wait(&child_status);
    return (child_status / 256);
}
