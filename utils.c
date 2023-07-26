#include "shell.h"

/**
 * _strcpy - copies  source string into destination
 * @destination: the return string that gets the source
 * @source: the string to copy
 *
 * Return: pointer to the destination string
 */
char *_strcpy(char *destination, char *source)
{
	int index;

	index = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[index])
	{
		destination[index] = source[index];
		index++;
	}
	destination[index] = 0;
	return (destination);
}

/**
 * _prints - prints an input string
 * @text: text to be printed
 *
 * Return: void
 */
void _prints(char *text)
{
	int index
	
	index = 0;

	if (!str)
		return;
	while (str[index] != '\0')
	{
		_putchar(str[index]);
		index++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: returns 1 on success else error.
 */
int _putchar(char character)
{
	int index;
	int buffersize;
	char buffer[buffersize];

	buffersize = 1024;

	if (character == -1 || index >= buffersize)
	{
		write(1, buffer, index);
		index = 0;
	}
	if (character != -1)
	{
		index++;
		buffer[index] = character;
	}

	return (1);
}

/**
 * _atoi - converts a string datatype to an integer type
 * @text: the text to be converted to integer
 * Return: returns converted number or 0 
 */
int _atoi(char *text)
{
	int index;
	int sign;
	int flag;
	int output;
	unsigned int res;

	sign = 1;
	flag = 0;
	output;
	res = 0;

	for (index = 0; text[index] != '\0' && flag != 2; index++)
	{
		if (text[index] == '-')
			sign *= -1;

		if (text[index] >= '0' && text[index] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (text[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}
