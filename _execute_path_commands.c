#include "main.h"

/**
* _run_path_command - the function name
* @s: parameter of type char *.
* @tokens: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: void .
*/
void _run_path_command(char *s, char **tokens, int cmdnum)
{
	int x, y;
	char *pthstr = NULL;

	x = _strlen(s);
	y = _strlen(tokens[0]);
	pthstr = malloc(sizeof(char) * (x + y + 2));
	if (pthstr == NULL)
	{
		perror("Error: ");
		exit(0);
	}
	_str_cpy(pthstr, s);
	_str_cat(pthstr, "/");
	_str_cat(pthstr, tokens[0]);
	pthstr[(x + y + 1)] = '\0';
	if (access(pthstr, X_OK) == 0)
	{
		_path_comand_run(pthstr, tokens, cmdnum);
	}
	else
	{
		_print_f("%s: %d: %s: not found\n", tokens[0], cmdnum, tokens[0]);
	}
	free(pthstr);
}
