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
#define PATH_MAX 4096

extern int status_code;
extern int fd;
extern char **environ, *line;
extern int cmd_history;
extern char *program_name;


/**
 * struct argsList - structure for our format and the corresponding function
 * @ch: pointer to a character
 * @f: pointer to a function
 */

 typedef struct builtin_function
 {
    char *cmd_name;
    int (*func)(char **str);
    
 } b_func;



void display_prompt(void);
char *get_input();
int _is_valid(char *str);
int to_array_of_cmds(char *line, char **cmd_array);
int parse_cmd(char *cmd, char **av);
int process_cmd(char *line_buffer, char **cmd_array);
int execute_cmd(char **arg);
char *get_cmd_path(char *arg);
int execute_system_cmd(char **args, char *path);


/* Built-in shell functions */
int exit_shell(char **args);
int _env(char **args);
// char *format_cmd_line(char *str);
int change_directory(char **args);
// int alias(char **args);
int _setenv(char **args);
int _unsetenv(char **args);
int _help(char **args __attribute__((unused)));

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


// int select_function(char *c);
int (*select_function(char *c))(char **str);

/* str helper */
char *_itoa(int num);
int is_numeric(char *s);
#endif
