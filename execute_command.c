#include "shell.h"

/**
 * cmdexe - this function excecute th parsed input
 * @argv: array of parsed used args with our parsecommand function
 *
 * Return: if successful returns 1
 */
int executecommand(char **argv)
{
	pid_t pid;
	char *env;

	env = "/bin/env";

	if (argv[0] == env)
	{
		return print_environment();
	}

	if (access(argv[0], X_OK) != 0)
	{
		printf("%s: command not found\n", argv[0]+5);
		return (1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
