#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char *readcommand(void);
char **parsecommand(char *text);
int executecommand(char **argv);
char *add_path_to_bin(char *originalString);
int print_environment(void);

#endif /* SHELL_H */