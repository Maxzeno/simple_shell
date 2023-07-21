#include "shell.h"

/**
 * parsecommand - Parse's text that user enters and remove delimiter
 *
 * @text: the command entered by the user
 *
 * Return: returns a null terminated array of strings
 */
char **parsecommand(char *text)
{
	int buffersize;
	int index;
	char *token;
	// char *delimiter;
	// char **tokens;

	char delimiter[] = " \n\t\r\a";
	buffersize = 64;
	char **tokens = malloc(sizeof(char *) * buffersize);
	index = 0;

	token = strtok(text, delimiter);
	while (token) {
		if (index == 0)
		{
			tokens[index] = add_path_to_bin(token);
		}
		else{
			tokens[index] = token;
		}

		token = strtok(NULL, delimiter);
		index++;

		if (index >= buffersize)
		{
			buffersize += 64;
			tokens = realloc(tokens, buffersize * sizeof(char *));
			if (tokens == NULL)
			{
				perror("Error realloc");
				exit(EXIT_FAILURE);
			}
		}
	} ;
	tokens[index] = NULL;

	return (tokens);
}