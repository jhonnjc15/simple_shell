#include "shell.h"

/**
 * error_message - writes an error message when command not found
 * @av: the argv from the int main function
 *
 * Return: nothing
 */
void error_message(char **av)
{
	char *msg = "No such file or directory\n";

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, _strlen(msg));
}
