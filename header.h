#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>

extern int fd;

void display_prompt(void);
char *get_input(void);
int _is_valid(char *str);
int to_array_of_cmds(char *line, char **cmd_array);
int parse_cmd(char *cmd, char **av);
int process_cmd(char *line_buffer, char **cmd_array);


int free_pointer(char *ptr, ...);
void free_double_pointer(char **av);

#endif
