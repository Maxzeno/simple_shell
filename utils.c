#include "shell.h"

/**
 * _strcpy - copies a string to dest
 * @dest: the destination string
 * @src: the source string
 *
 * Return: pointer to the destination str
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

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

/**
 * _atoi - converts a string to an integer
 * @text: the string to be converted to integer
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

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, size_t new_size) 
{
	size_t i;
	void *new_ptr;
	size_t old_size;
	size_t copy_size;

	if (new_size == 0) {
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	old_size = *(size_t*)((char*)ptr - sizeof(size_t));

	copy_size = old_size < new_size ? old_size : new_size;
	for (i = 0; i < copy_size; i++)
		((char*)new_ptr)[i] = ((char*)ptr)[i];

	free(ptr);

	*(size_t*)new_ptr = new_size;

	return (new_ptr);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to check the length
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strncmp - check if string has prefix
 * @str1: the string
 * @str2: prefix
 * @n: length of prefix
 *
 * Return: pointer to destination buffer
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] == '\0' && str2[i] == '\0')
			return (0);
		else if (str1[i] == '\0' || str1[i] < str2[i])
			return (-1);
		else if (str2[i] == '\0' || str1[i] > str2[i])
			return (1);
	}

	return 0;
}
