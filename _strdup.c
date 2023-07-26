#include "main.h"

/**
* _strdup - the function name
* @str: parameter of type char *.
* Return: char * .
*/
char *_strdup(char *str)
{
	char *dup;
	int i = 0;
	int len = 0;

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < len; i++)
	{
		dup[i] = str[i];
	}
	dup[i] = '\0';
	return (dup);
}
