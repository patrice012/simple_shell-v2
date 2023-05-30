#include "header.h"


int execute_cmd(char **args)
{
    int i = 0;
    pid_t pid;
    // char **argv;

    // while (args[i])
    // { 
    //     argv[i] = (char *)malloc(sizeof(char) * strlen(args[i]) + 1);
    //     argv[i] = args[i];
    //     i++;
    // }
    // argv[i] = NULL;
    char *path = get_cmd_path(args[0]); /* check if path is null*/
    printf("path:%s\n", path);
    // pid = create_process()
    // if (pid == 1)
    // {
    //     perror("fork");
    //     exit(EXIT_SUCCESS);
    // }
    // if (pid == 0)
    // {
    //     execute_system_cmd()
    // }


}

char *get_cmd_path(char *arg)
{
    char *path = getenv("PATH"), *delim = ":"; /* not need to free  path*/
    char **array_path; /* free */
    int i = 0;

    if (path ==  NULL)
    {
        perror("Path does not exist");
        return (NULL);
    }
    /* get all path */
    _tokenizer(path, delim, array_path);
    while(array_path[i])
    {
        _cmd_exist(arg, array_path[i]);
        i++;
    }
    /* check if command exist */
    return (path);
}


int _cmd_exist(char *arg, char *path)
{
    /* we do +2 for / and NULL terminate */
    char *absolute_path = (char *)malloc(sizeof(char) *  (strlen(arg) + strlen(path)) + 2);

    create_abs_path(path, arg, absolute_path);
}


char *create_abs_path(char *arg1, char *arg2, char *save_buffer);
{
    strcpy(save_buffer, )
}
