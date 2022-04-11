#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

/* Aux Functions */
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s, char *t, int n);
int _putchar(char c);
void _puts(char *str);
char *_itoa(int num, int base);

/* Main functions */
void prompt(void);
char *get_input(void);
int handle_child_process(char **ar, char **av, int cnt);

/* Helper functions */
char **split_string(char *str, char *delim);
char **tokalloc(char *buffer, char *delim, int ctok);
char **_strtok_all(char *buffer, char *delimiter);
int write_exit(char *command);
int write_spaces(char *command);
int write_env(char **ar);
int count_subcommands(char *str);
void free_ar(char **ar);

/* PATH */
char *getenv_PATH(void);
char **get_PATHS(void);
void add_backslash(char **paths);

/* Execution functions*/
int execute_basic_commands(char **ar);

/* Built-ins */
void fprintenv(char **env);

/* Handle Errors */
int print_error(char *programm, int count, char *command);

/* Debug */
void debug(char *line, char **ar);

#endif