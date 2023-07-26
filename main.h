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
#include <stdint.h>
#include <errno.h>

extern char **environ;

/*main.c*/
void prompt(char **argv, char **env);
void format_str(char *input, char **argv, char **env);
char *checkpath(char *str);
void exec(char *input, char **argv, char **env);

/*util.c*/
int is_space(char c);
int spaces(char *input);
char *newstring(char *array[], int size);
void error_message(char **argv, char *input);
int calculate_length(char *array[], int size);

/*util1.c*/
char *_strcat(char *dest, char *src);
int inputcheck(char *str1, char *str2, int n);
int str_cmp(char *str1, char *str2);
int _putchar(char c);
char *paths(char *command);

/*util2.c*/
char *_strncpy(char *dest, char *src, int n);
char *_strdup(const char *str);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);

/*inbuilt.c*/
void inbuilt(char *input, char **env);
void environment(void);

char *_strtok(char *str, char *delim);

#endif
