#include "main.h"

/**
* _putchar - using this to redirect stderr
* @c: parameter of type char .
* Return: int .
*/
int _putchar(char c)
{
	return (write(2, &c, 1));
}
