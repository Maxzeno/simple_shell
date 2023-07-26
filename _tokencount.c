#include "main.h"

/**
* _count_token - the function name
* @line: parameter of type char *.
* Return: int .
*/
int _count_token(char *line)
{
	int count = 0, isSpace = 1, x;

	for (x = 0; line[x]; x++)
	{
		if (line[x] == '\n' || line[x] == '\t' || line[x] == ' ')
		{
			isSpace = 1;
		}
		else if (isSpace == 1)
		{
			isSpace = 0;
			++count;
		}
	}
	return (count);
}
