#include "shell.h"

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

	old_size = *(size_t *)((char *)ptr - sizeof(size_t));

	copy_size = old_size < new_size ? old_size : new_size;
	for (i = 0; i < copy_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];

	free(ptr);

	*(size_t *)new_ptr = new_size;

	return (new_ptr);
}
