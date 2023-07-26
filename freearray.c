#include "main.h"

/**
* free_array - frees an array of strings
* @array: the array to free
*/
void free_array(char **array)
{
	int i;

	for (i = 0; array[i] != NULL; i++)
	{
		free(array[i]);
	}
	free(array);
}
