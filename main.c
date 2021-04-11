#include "shell.h"

/**
 * main - main function
 * @argc: argument to count the number of parameters
 * @argv: argument with all the parameters
 * @env: environment variables
 *
 * Return: 0 on exit, 1 if any failures happen
 */


int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	char **commands;
	size_t length = 0;
	int characters;
	pid_t pid;
	struct stat fileStat;
	(void)argc;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	while (1)
	{
		characters = getline(&buffer, &length, stdin);
		if (characters == EOF)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			free(buffer);
			exit(0);
		}
		commands = array_of_commands(buffer);
		pid = fork();
		if (pid == -1)
			exit(EXIT_FAILURE);
		if (pid == 0)
			child_exec(commands, buffer, fileStat, env, argv);
		else
			parent_exec(commands, buffer);
		length = 0;
		buffer = NULL;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
	}
	return (EXIT_SUCCESS);
}
/**
 * child_exec - function to execute the child
 * @commands: double pointer array we created to store all commands
 * @buffer: buffer we created from getline
 * @fileStat: to check is the file exist
 * @env: environment variables
 * @argv: argument with all the parameters
 *
 * Return: 0 on exit, 1 if any failures happen
 */
void child_exec(char **commands, char *buffer
				 ,struct stat fileStat, char **env, char **argv)
{
	if (commands == NULL)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp("exit", commands[0]))
	{
		free(buffer);
		free_double_pointer(commands);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp("env", commands[0]))
	{
		free(buffer);
		free_double_pointer(commands);
		print_env(env);
		exit(EXIT_SUCCESS);
	}
	else if (stat(commands[0], &fileStat) == 0)
	{
		execve(commands[0], commands, NULL);
	}
	else
	{
		path_exec(commands, buffer, env, argv);
	}
}
/**
 * parent_exec- function to execute the father
 * @commands: double pointer array we created to store all commands
 * @buffer: buffer we created from getline
 *
 * Return: 0 on exit, 1 if any failures happen
 */
void parent_exec(char **commands, char *buffer)
{
	wait(NULL);
	if (commands == NULL)
	{
	free(buffer);
		free_double_pointer(commands);
	}
	else if (_strcmp("exit", commands[0]))
	{
		free(buffer);
		free_double_pointer(commands);
		exit(EXIT_SUCCESS);
	}
	else
	{
		free(buffer);
		free_double_pointer(commands);
	}
}

