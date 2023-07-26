#include "main.h"

/**
  * _chck_if_path - the function name
  * @tokens: parameter of type char **.
  * @cmdnum: parameter of type int .
  * Return: int .
 */
int _chck_if_path(char **tokens, int cmdnum)
{
	int i = 0, isOnPath = -1;
	char *str = NULL, *path = NULL;

	while (environ[i] != NULL && isOnPath != 0)
	{
		if (_str_n_cmp("PATH=", environ[i], 5) == 0)
		{
			path = _strdup(environ[i]);
			my_stritk(path, "=");
			str = my_stritk(NULL, "=");
			isOnPath = _look_in_path(str, tokens, cmdnum);
			break;
		}
		i++;
	}
	free(path);
	return (isOnPath);
}
