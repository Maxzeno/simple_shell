#include "shell.h"

/**
 * print_environment - Function prints env
 *
 * Return: Returns 1 if okay
 */
int print_environment(void)
{
	char **env;

	env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return (1);
}
