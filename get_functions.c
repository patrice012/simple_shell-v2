#include "header.h"

/**
  * get_len - return the length of array
  * @arr_size: array of element
  * @f: base data type of the element
  * Return: int
  */


int get_len(size_t arr_size, b_func f)
{
    return (arr_size / sizeof(f));
}


/**
 * get_function - get the builtin command function
 * @c: command name
 * Return: pointer to the right fonction
 */

int (*select_function(char *c))(char **str)
{
  int i, len;

    b_func func[] = {
        {"exit", exit_shell},
        {"env", _env},
        {"setenv", _setenv},
        {"unsetenv", _unsetenv},
        {"cd", change_directory},
        // {"alias", alias},
        {"help", _help},
    };

    len = get_len(sizeof(func), func[0]);
    for (i = 0; i < len && func[i].cmd_name; i++)
    {
        if (strcmp(func[i].cmd_name, c) == 0)
            return (func[i].func);
    }
    return (NULL);
}
