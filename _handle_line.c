#include "main.h"
/**
* handle_line - the function name
* @line: parameter of type char *.
* @num_tokens: parameter of type int .
* @argv: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: int .
*/
int handle_line(char *line, int num_tokens, char **argv, int cmdnum)
{
	char **array2 = NULL;
	int status, isBuiltin;

	array2 = create_array_from_line(line, num_tokens);
	if (array2 == NULL)
	{
		return (0);
	}
	isBuiltin = _handle_shell_inbuilt(line, array2);
	if (isBuiltin == 0)
	{
		status = execute_external_command(array2, argv, cmdnum);
		free_array(array2);
		return (status);
	}
	else
	{
		free_array(array2);
		return (0);
	}
}
