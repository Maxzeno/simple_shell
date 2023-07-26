#include "main.h"

/**
* _str_cmp - the function name
* @s1: parameter of type char *.
* @s2: parameter of type char *.
* Return: int .
*/
int _str_cmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] || s2[i])
	{
		if (s1[i] == s2[i])
		{
			s1++;
			s2++;
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
