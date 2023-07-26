#include "shell.h"

/**
 * shell_exit_status - prints pid
 *
 * Return: 1
 */
int shell_exit_status(void)
{
	_puts("0");
	_puts("\n");
	return (1);
}

/**
 * print_process_pid - prints pid
 *
 * Return: 1
 */
int print_process_pid(void)
{
	_putpid(getpid());
	return (1);
}

/**
 * not_found - prints command not found
 * @arg: the command input by user
 *
 * Return: 1
 */
int print_not_found(char *arg)
{
	_puts(arg);
	_puts(": command not found\n");
	return (1);
}

/**
 * cmdexe - this function excecute th parsed input
 * @argv: array of parsed used args with our parsecommand function
 *
 * Return: if successful returns 1
 */
int executecommand(char **argv)
{
	pid_t pid;
	char *envp[] = {NULL};

	if (_strcmp(argv[0], "env") == 0)
		return (print_environment());

	if (_strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(_atoi(argv[1]));
		return (0);
	}

	if (_strcmp(argv[0], "$$") == 0)
		return (print_process_pid());

	if (_strcmp(argv[0], "$?") == 0)
		return (shell_exit_status());

	if (access(add_path_to_bin(argv[0]), X_OK) != 0)
		return (print_not_found(argv[0]));

	pid = fork();
	if (pid < 0)
	{
		perror("Error fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(add_path_to_bin(argv[0]), argv, envp);
		perror("Error execve");
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);

	return (1);
}
