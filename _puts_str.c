#include "main.h"

/**
* _puts_stri - the function name
* @smstr: parameter of type char *.
* Return: void .
*/
void _puts_stri(char *smstr)
{
	while (*smstr != '\0')
	{
		write(1, smstr, 1);
		smstr++;
	}
}
