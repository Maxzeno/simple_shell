#include "shell.h"

/**
 * readcommand - Function reads user input
 *
 * Return: Returns the text user enters
 */
char *readcommand(void)
{
	char *readed;
	size_t buffersize;
	
	readed = NULL;
	buffersize = 0;
	printf("$ ");
    getline(&readed, &buffersize, stdin);
    
    return (readed);
}