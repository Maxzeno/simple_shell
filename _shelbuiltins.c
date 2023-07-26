#include "main.h"

/**
* _handle_shell_inbuilt - the function name
* @line: parameter of type char *.
* @array: parameter of type char **.
* Return: int .
*/
int _handle_shell_inbuilt(char *line, char **array)
{
	char **p;

	if (_str_cmp(array[0], "exit") == 0)
	{
		free_array(array);
		free(line);
		exit(0);
	}
	if (_str_cmp(array[0], "env") == 0)
	{
		p = environ;
		while (*p)
		{
			_puts_stri(*p++);
			write(1, "\n", 1);
		}
		return (2);
	}
	return (0);
}
