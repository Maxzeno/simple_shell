#include "main.h"

/**
* _get_digts - the function name
* @x: parameter of type int .
* Return: void .
*/
void _get_digts(int x)
{
	if (x > 0)
	{
		_get_digts((x / 10));
	}
	if (x != 0)
	{
		_putchar('0' + (x % 10));
	}
}
