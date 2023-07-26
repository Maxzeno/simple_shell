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
		_prints("%s\n", *env);
		env++;
	}

	return (1);
}
