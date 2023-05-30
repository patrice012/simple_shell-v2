#include "header.h"

int _tokenizer(char *strings, char *delim, char **save_buffer)
{
    char *buffer, *token = NULL;
    int id = 0;

    buffer = strdup(strings); /* need to be free */
    token = strtok(buffer, delim);
    while (token != NULL)
    {
        save_buffer[id] = (char *)malloc(sizeof(char) * (strlen(token) + 1));
        strcpy(save_buffer[id], token);
        token = strtok(NULL, delim);
        id++;
    }
    save_buffer[id] =  NULL;
    free(buffer);
    return (id);
}
