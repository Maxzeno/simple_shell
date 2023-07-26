#include "main.h"

int _executor(char **array, char **argv,
int cmdnum, struct stat *st)
{
	pid_t child_pid;
	int status = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		free(st);
		free_array(array);
		return (0);
	}
	if (child_pid == 0)
	{
		if (execve(array[0], array, environ) == -1)
		{
			free(st);
			_print_f("%s: %d: %s: not found\n", argv[0], cmdnum, array[0]);
			free_array(array);
			_exit(-1);
		}
	}
	else
	{
	while (waitpid(-1, &status, 0) != child_pid)
		;
	}
if (status == 0)
	errno = 0;
if (status == 512)
	errno = 2;
if (status == 65280)
	errno = 127;
return (errno);
}
