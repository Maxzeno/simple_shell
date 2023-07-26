#include "shell.h"

/**
 * _putchar - prints the character c
 * @c: The character to be printed
 *
 * Return: On success 1 else error.
 */
int _putchar(char c)
{
	int num = 1;

	return (write(num, &c, num));
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

void _putpid(pid_t pid)
{
	char pid_str[20];
	int i = 0;

	do {
		pid_str[i++] = pid % 10 + '0';
		pid /= 10;
	} while (pid > 0);
    
	while (i > 0)
		_putchar(pid_str[--i]);

	_putchar('\n');
}
