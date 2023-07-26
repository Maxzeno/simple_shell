#include "main.h"

/**
* _look_in_path - the function name
* @str: parameter of type char *.
* @tokens: parameter of type char **.
* @cmdnum: parameter of type int .
* Return: int .
*/
int _look_in_path(char *str, char **tokens, int cmdnum)
{
	struct dirent *fldr;

	DIR *mydir;
	int dest = 0, isOnPath = -1;

	str = my_stritk(str, ":");
	while (str != NULL  && dest != 1)
	{
		mydir = opendir(str);
		if (mydir == NULL)
		{
			return (0);
		}
		for (fldr = readdir(mydir); fldr != NULL; fldr = readdir(mydir))
		{
			if (_str_cmp(fldr->d_name, tokens[0]) == 0)
			{
				_run_path_command(str, tokens, cmdnum);
				isOnPath = 0;
				dest = 1;
				break;
			}
		}
		closedir(mydir);
		if (dest == 0)
		{
			str = my_stritk(NULL, ":");
		}
	}
	return (isOnPath);
}
