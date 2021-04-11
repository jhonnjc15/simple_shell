#include "shell.h"
/**
 * print_env - prints all of the environment variables to the output
 * @environ: all environment variables for the user
 *
 * Return: void
 */
void print_env(char **environ)
{
	int i, length;

	i = 0;
	while (environ[i])
	{
		length = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
}
