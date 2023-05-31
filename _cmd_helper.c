#include "header.h"


char *get_cmd_path(char *arg)
{
    char *path = strdup(getenv("PATH")), *delim = ":"; /* free  path*/
    char **array_path = (char **)malloc(sizeof(char) * MAX_NUMBER); /* free */
    char *cmd_path;
    int i = 0;

    if (path ==  NULL)
    {
        perror("Path does not exist");
        return (NULL);
    }
    /* get all path sub-element */
    _tokenizer(path, delim, array_path);
    free(path);
    while(array_path[i])
    {
        /* check if command exist */
        cmd_path = _cmd_exist(arg, array_path[i]);
         if (cmd_path != NULL)
            // break;
            /* need to free cmd_path */
            return (strdup(cmd_path));
        i++;
    }
    if (cmd_path == NULL)
    {
        /* check if it is an executable file */
        if (_is_executable(strdup(arg)) == 0)
        {
            // perror(arg);
            return (NULL);
        }
        else
            return (strdup(arg));
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

/**
 * Return: boolean value 0 for false and 1 for true
 */
int _is_executable(char *arg)
{
    /* arg should be free */
    int found = 0;

    if (access(arg, X_OK) == -1)
        found = 0;
    else
        found = 1;
    free(arg);
    return (found);
}


int _is_interactive_mode(int fd)
{
    if (isatty(fd))
        return (1);
    return (0);
}
