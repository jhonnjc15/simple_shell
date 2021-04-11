#include "shell.h"

/**
 * num_commands_sep - finds the number of commands
 * in the string separated by sep
 * @string: the input string
 * @sep: the char separator
 * Return: number of commands
 */
int num_commands_sep(char *string, char sep)
{
	int commands = 0, i = 0, tmp = 0;

	while (string[i] != '\0')
	{
		if (string[i] != sep)
			tmp = 1;

		if ((tmp == 1 && string[i + 1] == sep)
					|| (tmp == 1 && string[i + 1] == '\0'))
		{
			++commands;
			tmp = 0;
		}
		++i;
	}

	return (commands);
}
