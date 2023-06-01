#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>


#define  MAX_NUMBER 1024
#define DEBUG 0

extern int fd;
extern char **environ;
extern int cmd_history;
extern char *program_name;

void display_prompt(void);
char *get_input();
int _is_valid(char *str);
int to_array_of_cmds(char *line, char **cmd_array);
int parse_cmd(char *cmd, char **av);
int process_cmd(char *line_buffer, char **cmd_array);
int execute_cmd(char **arg);
char *get_cmd_path(char *arg);
int execute_system_cmd(char **args, char *path);

/** erros functions */
int  permission_denied_error(char *cmd);
int  not_found_error(char *cmd);



/* helper functions */
int _tokenizer(char *strings, char *delim, char **save_buffer);
char *create_abs_path(char *arg1, char *arg2, char *save_buffer);
char *_cmd_exist(char *arg, char *path);
int _is_executable(char *arg);
pid_t create_process(void);
int _is_interactive_mode(int fd);


int free_pointer(char *ptr, ...);
void free_double_pointer(char **av);
void print_stdout(char *str);
void print_stderror(char *str);

#endif
