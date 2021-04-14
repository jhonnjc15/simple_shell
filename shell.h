#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

void child_exec(char **commands, char *buffer
			, struct stat fileStat, char **env, char **argv);
void parent_exec(char **commands, char *buffer);

int num_commands_sep(char *string, char sep);
char **array_of_commands(char *string);

char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);

char **array_env_variables(char *command_0, char **environ);
char *_getenv(char *name, char **environ);
char *_strncpycmd(char *dest, char *src, char *command);

void print_env(char **environ);

void free_double_pointer(char **double_pointer);

void error_message(char **av);

void path_exec(char **commands, char *buffer, char **env, char **argv);


void handler(int num);
#endif /* _SHELL_H_ */
