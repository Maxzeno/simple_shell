#include "main.h"
/**
* main - The entry point of the program
* @argc: parameter of type int .
* @argv: parameter of type char **.
* Return: int .
*/
int main(int argc, char **argv)
{
	int is_interactivemode;

	is_interactivemode = isatty(STDIN_FILENO);
	if (is_interactivemode == 0 && argc == 1)
	{
		return (non_interactive_mode(argv));
	}
	return (interactive_mode(argv));
}
