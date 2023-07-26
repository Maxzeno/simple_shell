#include "main.h"

/**
* _str_cpy - function that copies the string pointed to by src,
* @dest: parameter of type char *.
* @src: parameter of type char *.
* Return: char *.
*/
char *_str_cpy(char *dest, char *src)
{
	int i = 0;
	int leng = 0;

	while (*(src + leng) != '\0')
	{
		leng++;
	}
	for (i = 0; i <= leng; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
