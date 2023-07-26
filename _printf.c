#include "main.h"
/**
*_print_f - function that mimicks printf
*@frmt: pointer t format of passed value
*Return: int
*/
int _print_f(const char *frmt, ...)
{
	int x = 0, count = 0, j = 0;
	va_list args;

format  frmtarr[] = {
{"%", _check_frmt},
{"\\", _check_frmt},
{NULL, NULL}
		};
		va_start(args, frmt);
		while (frmt != NULL && frmt[x] != '\0')
		{
			if (frmt[x] == *(frmtarr[0].ptr))
			{
				count += frmtarr[0].type(&args, frmt, x);
				if (count == -1)
				{
					return (-1);
				}
				j += count;
				x++;
				while (frmt[x] == ' ')
				x++;
				count = 1;
			}
			if (count == 0)
			{
				_putchar(frmt[x]);
				j++;
			}
			count = 0;
			x++;
		}
		va_end(args);
		return (j);
	}
