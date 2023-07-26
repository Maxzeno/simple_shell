#include "main.h"

/**
* _path_comand_run - the function name
* @pthstr: parameter of type char *.
* @tokens: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: void .
*/
void _path_comand_run(char *pthstr, char **tokens, int cmdnum)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: ");
		free(pthstr);
		free_array(tokens);
		exit(0);
	}
	if (child_pid == 0)
	{
		if (execve(pthstr, tokens, environ) == -1)
		{
			_print_f("%s: %d: %s: not found\n", tokens[0], cmdnum, tokens[0]);
			free(pthstr);
			free_array(tokens);
			_exit(-1);
		}
} else
		{
			while (waitpid(-1, &status, 0) !=  child_pid)
				;
		}
		if (status == 65280)
		{
			errno = 127;
		}
	}
