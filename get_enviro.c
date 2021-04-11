#include "shell.h"
/**
 * _getenv - gets the environment variable value
 * @name: name of the environment vaariable you are looking for
 * @environ: the enviroment variables
 *
 * Return: the value associated with the variable
 */
char *_getenv(char *name, char **environ)
{
	char *env_value;
	char *name_copy;
	int i, length;

	length = _strlen(name);
	name_copy = malloc((sizeof(char) * length) + 1);
	if (name_copy == NULL)
		return (NULL);
	_strncpy(name_copy, name, length);
	i = 0;
	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_value, name_copy))
		{
			env_value = strtok(NULL, "\n");
			free(name_copy);
			return (env_value);
		}
		++i;
		env_value = strtok(environ[i], "=");
	}
	free(name_copy);
	return (NULL);
}
/**
 * _strncpycmd - copies paths and appens a / + command to each path
 * @dest: destination
 * @src: source
 * @command: command to append
 *
 * Return: destination address
 */
char *_strncpycmd(char *dest, char *src, char *command)
{
	int i, j, n, c;

	n = _strlen(src);
	c = _strlen(command);
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '/';
	i++;
	for (j = 0; j < c && command[j] != '\0'; j++, i++)
		dest[i] = command[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * array_env_variables - creates a double pointer array,
 * where it stores each path directory as a single pointer, NULL terminated
 * @command_0: first command that you type in the prompt
 * @environ: the environment variables
 *
 * Return: memory address of the double pointer array
 */

char **array_env_variables(char *command_0, char **environ)
{
	char **all_directories;
	char *path_env, *current_directory;
	int length, i;

	path_env = _getenv("PATH", environ);

	length = num_commands_sep(path_env, ':');
	all_directories = malloc(sizeof(char *) * (length + 1));
	if (all_directories == NULL)
		return (NULL);

	i = 0;
	current_directory = strtok(path_env, ":");
	while (current_directory != NULL)
	{
		all_directories[i] = malloc(sizeof(char) * (_strlen(current_directory)
					+ _strlen(command_0) + 2));
		if (all_directories[i] == NULL)
		{
			free_double_pointer(all_directories);
			return (NULL);
		}
		_strncpycmd(all_directories[i], current_directory, command_0);
		++i;
		current_directory = strtok(NULL, ":");
	}
	all_directories[i] = NULL;

	return (all_directories);
}

