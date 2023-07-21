#include "shell.h"

/**
 * main - the function that calls the shell
 * @argc: number of arguments passed
 * @argv: The array of string arguments passed
 * @envp: the environment arguments passed
 *
 * Return: if successful returns 0
 */
int main(int argc, char **argv, char *envp)
{
    char *command;
    int status;

    status = 1;

    while (status) 
    {
        command = readcommand();
        argv = parsecommand(command);
        status = executecommand(argv);
    }

    return (0);
}

