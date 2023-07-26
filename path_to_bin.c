#include "shell.h"

/**
 * add_path_to_bin - this function append bin to originalString
 *
 * @originalString: string passed in
 *
 * Return: returns concatinated string bin and originalString
 */
char *add_path_to_bin(char *originalString)
{
	char *prefix;
	int newStringLength;
	char *newString;
	int prefixLength;

	prefix = "/bin/";

	prefixLength = _strlen(prefix);

	if (_strncmp(originalString, prefix, prefixLength) == 0)
		return (originalString);

	newStringLength = prefixLength + _strlen(originalString) + 1;
	newString = malloc(sizeof(char *) * newStringLength);
	_strcpy(newString, prefix);
	_strcat(newString, originalString);

	return (newString);
}
