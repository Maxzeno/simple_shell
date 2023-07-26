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
int shell_exit_status(void);
int print_process_pid(void);
int print_not_found(char *arg);
int _putchar(char c);
char *_strcpy(char *dest, char *src);
void _puts(char *str);
int _atoi(char *text);
void *_realloc(void* ptr, size_t new_size) ;
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void _putpid(pid_t pid);
int _strncmp(const char* str1, const char* str2, size_t n);

#endif /* SHELL_H */
