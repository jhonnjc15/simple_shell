#include "shell.h"
/**
 * array_of_commands - creates a double pointer array that holders pointers
 * to each string from the command line
 * @string: The input string to enter
 * Return: double pointer array of pointers that are commands
 */

char **array_of_commands(char *string)
{
	char **array_comm, *token;
	int num_comm, i;

	i = 0;
	string[_strlen(string) - 1] = '\0';
	num_comm = num_commands_sep(string, ' ');
	if (num_comm == 0)
		return (NULL);

	array_comm = malloc((sizeof(char *)) * (num_comm + 1));
	if (array_comm == NULL)
		return (NULL);
	token = strtok(string, " ");
	while (token != NULL)
	{
		array_comm[i] = malloc(_strlen(token) + 1);
		if (array_comm[i] == NULL)
		{
			free_double_pointer(array_comm);
			return (NULL);
		}
		_strncpy(array_comm[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	array_comm[i] = NULL;
	return (array_comm);
}

