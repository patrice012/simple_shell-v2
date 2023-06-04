#include "header.h"


int execute_cmd(char **args)
{
    int cmd_status = 1;
    /* try to run builtin command */
    int (*func)(char **str);
    func = select_function(args[0]);
    if (func != NULL)
    {
        cmd_history++;
        cmd_status = func(args);
        return (cmd_status);
    }
    // int i = 0;
    // while (args[i])
    // {
    //     printf("args:%s\n", args[i]);
    //     i++;
    // }

    /* free path after */
    char *path = get_cmd_path(args[0]); /* check if path is null*/
    if (path != NULL)
        /* run system cmd */
        cmd_status = execute_system_cmd(args, path);    
    cmd_history++;
    return (cmd_status); /* 0 for success and 1 for failure */

}



int execute_system_cmd(char **args, char *path)
{
    pid_t child_pid;
    int _status, child_status = -1;

    if (DEBUG)
        printf("path: %s\n", path);

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
