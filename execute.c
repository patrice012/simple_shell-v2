#include "header.h"


int execute_cmd(char **args)
{
    int i = 0;
    pid_t pid;

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
    char *path = strdup(getenv("PATH")), *delim = ":"; /* not need to free  path*/
    char **array_path = (char **)malloc(sizeof(char) * MAX_NUMBER); /* free */
    char *cmd_path;
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
        /* check if command exist */
        cmd_path = _cmd_exist(arg, array_path[i]);
         if (cmd_path != NULL)
            break;
        i++;
    }
    if (cmd_path == NULL)
    {
        /* check if it is executable */
        if (access(arg, X_OK) == -1)
        {
            perror(arg);
            return (NULL);
        }
        else
            return (arg);
    }
    return (strdup(cmd_path));
}


char *_cmd_exist(char *arg, char *path)
{
    struct stat st;
    /* we do +2 for / and NULL terminate */
    char *absolute_path = (char *)malloc(sizeof(char) *  (strlen(arg) + strlen(path)) + 2);

    create_abs_path(path, arg, absolute_path);
    if (stat(absolute_path, &st) == 0)
        return (absolute_path);
    return (NULL);

}


char *create_abs_path(char *arg1, char *arg2, char *save_buffer)
{
    strcpy(save_buffer, arg1);
    strcat(save_buffer, "/");
    strcat(save_buffer, arg2);
    strcat(save_buffer, "\0");
}
