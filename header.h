#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL
#define BUFSIZE 1024

#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <sys/resource.h>

extern char **environ;

void exec_process(char **path);
char **parsing_arg(char *line);
char *read_line(void);

char **path_av(char **arg);
char **ph_to_dp(char *token_cp);
int number_of_dir(char *ph);
char **conc_slash(char **p);

void _environment(void);
void _ext(void);

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _putchar(char c);

#endif
