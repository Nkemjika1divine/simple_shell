#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

extern char **environ;

/*main.c*/
void prompt(char **argv, char **env);
void exec(char *input, char **argv, char **env);

/*util.c*/
int _putchar(char c);
int is_space(char c);
int spaces(char *input);

#endif
