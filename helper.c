#include "header.h"

char *create_abs_path(char *arg1, char *arg2, char *save_buffer)
{
    strcpy(save_buffer, arg1);
    strcat(save_buffer, "/");
    strcat(save_buffer, arg2);
    strcat(save_buffer, "\0");
}
