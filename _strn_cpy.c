#include "main.h"

/**
  * _str_n_cpy - the function name
  * @dest: parameter of type char *.
  * @src: parameter of type const char *.
  * @n: parameter of type size_t .
  * Return: char * .
 */
char *_str_n_cpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	dest[i] = src[i];
	for (; i < n; i++)
	dest[i] = '\0';
	return (dest);
}
