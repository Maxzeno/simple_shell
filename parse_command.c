#include "shell.h"

/**
 * print_error_malloc - prints Error malloc
 *
 * Return: void
 */
void print_error_malloc(void)
{
	perror("Error malloc");
    exit(EXIT_FAILURE);
}

/**
 * print_error_realloc - prints Error realloc
 *
 * Return: void
 */
void print_error_realloc(void)
{
	perror("Error realloc");
    exit(EXIT_FAILURE);
}

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
		print_error_malloc();

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
				print_error_realloc();
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
