#include "main.h"

/**
* _pr_str - the function name
* @args: parameter of type va_list *.
* Return: int .
*/
int _pr_str(va_list *args)
{
	int j = 0;
	char *array;

	array = va_arg(*args, char *);
	while (*array != '\0')
	{
		_putchar(*array);
		j++;
		array++;
	}
	return (j);
}
