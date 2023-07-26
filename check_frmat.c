#include "main.h"

/**
* _check_frmt - the function name
* @args: parameter of type va_list *.
* @frmt: parameter of type const char *.
* @x: parameter of type int .
* Return: int .
*/
int _check_frmt(va_list *args, const char *frmt, int x)
{
	int i = 0, j = 0;
	format smformts[] = {
		{"s", _pr_str},
		{"d", _prt_dgt},
		{"i", _prt_dgt},
		{NULL, NULL}
		};

		x++;
		if (frmt[x] == ' ')
		{
			while (frmt[x] == ' ')
			x++;
		}
		if (frmt[x] == '%')
		{
			_putchar('%');
			return (1);
		}
		if (frmt[x] == 'n')
		{
			_putchar('\n');
			return (1);
		}
		while (smformts[i].type != NULL && *(smformts[i].ptr) != frmt[x])
		i++;
		j = smformts[i].type(args);
		return (j);
	}
