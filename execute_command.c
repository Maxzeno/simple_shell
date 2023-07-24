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

	if (strcmp(argv[0], "env") == 0)
		return print_environment();

	if (strcmp(argv[0], "exit") == 0)
	{
		if (argv[1])
			exit(atoi(argv[1]));

		return 0;
	}

	if (strcmp(argv[0], "$$") == 0)
	{
        printf("%u\n", getpid());
        return 1;
    } 

    if (strcmp(argv[0], "$?") == 0)
    {
        printf("%d\n", 0);
        return 1;
    }

	if (access(add_path_to_bin(argv[0]), X_OK) != 0)
	{
		printf("%s: command not found\n", argv[0]);
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
		execvp(argv[0], argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
