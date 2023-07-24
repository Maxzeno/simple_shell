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
	char *delimiter;
	char **tokens;

	delimiter = " \n\t\r\a";
	buffersize = 64;
	tokens = malloc(sizeof(char *) * buffersize);
	index = 0;

	if (tokens == NULL)
	{
        perror("Error malloc");
        exit(EXIT_FAILURE);
    }

	token = strtok(text, delimiter);
	while (token)
	{
		if (token[0] == '#')
			break;
		
		tokens[index] = token;

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
	};

	if (index == 0)
	{
		tokens[index] = "";
		index++;
	}

	tokens[index] = NULL;

	return (tokens);
}
