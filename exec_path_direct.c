#include "shell.h"

/**
 * path_exec- creates a double ptr array of all your directories
 * from your $PATH variable
 * @buffer: buffer we created from getline, input string
 * @commands: double pointer array we created to store all commands
 * from the prompt
 * @env: environment variables from your login
 * @argv: argument vector from int main
 *
 * Return: void
 */
void path_exec(char **commands, char *buffer, char **env, char **argv)
{
	struct stat fileStat2;
	int i;
	char **all_directories;

	i = 0;
	all_directories = array_env_variables(commands[0], env);
	while (all_directories[i])
	{
		if (stat(all_directories[i], &fileStat2) == 0)
			execve(all_directories[i], commands, NULL);
		++i;
	}
	error_message(argv);

	free(buffer);
	free_double_pointer(commands);
	free_double_pointer(all_directories);
	exit(EXIT_SUCCESS);
}
