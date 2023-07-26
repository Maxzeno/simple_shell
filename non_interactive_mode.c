#include "main.h"

/**
* non_interactive_mode - the function name
* @argv: parameter of type char **.
* Return: int .
*/
int non_interactive_mode(char **argv)
{
	char *line = NULL;
	size_t str_len = BUFF_SIZE;
	ssize_t y;
	int status, tokencount = 0, cmdnum = 1;

	while ((y = my_getline(&line, &str_len, STDIN_FILENO)) > 0)
	{
		tokencount = _count_token(line);
		status = handle_line(line, tokencount, argv, cmdnum);
		if (status != 0)
		{
			free(line);
			exit(status);
		}
	}
	free(line);
	return (status);
}
