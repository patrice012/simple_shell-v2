#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

extern int fd;

void display_prompt(void);
char *get_input(void);
int _is_valid(char *str);
int get_all_command(char *line);

#endif
