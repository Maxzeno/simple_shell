#include "shell.h"

/**
 * readcommand - Function reads user input
 *
 * Return: Returns the text user enters
 */
char *readcommand(void)
{
	char *readed;
	size_t buffersize;
	int is_ctrl_d;

	readed = NULL;
	buffersize = 0;
	_puts("$ ");
	is_ctrl_d = getline(&readed, &buffersize, stdin);

	if (is_ctrl_d == -1)
	{
		_puts("\n");
		exit(EXIT_FAILURE);
	}

	return (readed);
}
