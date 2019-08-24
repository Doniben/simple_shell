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

void exec_process(char **argv);
char **path_av(char **argv);
char **parsing_argv(char *line);
char *read_line(void);

int _strlen(char *s);

#endif
