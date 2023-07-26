#include "main.h"

/**
* interactive_mode - the function name
* @argv: parameter of type char **.
* Return: int .
*/
int interactive_mode(char **argv)
{
	char *line = NULL;
	size_t str_len = BUFF_SIZE;
	ssize_t x;
	int tokencount = 0, cmdnum = 1;

	while (1)
	{
		write(1, "$ ", 2);
		tokencount = 0;
		x = my_getline(&line, &str_len, STDIN_FILENO);
		if (x < 0)
		{
			write(1, "\n", 1);
			free(line);
			break;
		}
		tokencount = _count_token(line);
		handle_line(line, tokencount, argv, cmdnum);
		cmdnum++;
		free(line);
		line = NULL;
		str_len = BUFF_SIZE;
	}
	return (EXIT_SUCCESS);
}
