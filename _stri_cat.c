#include "main.h"

/**
* _str_cat - the function name
* @dest: parameter of type char *.
* @src: parameter of type char *.
* Return: char *.
*/
char *_str_cat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
	{
		++i;
	}
	while (src[j])
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	return (dest);
}
