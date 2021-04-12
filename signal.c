#include "shell.h"
/**
 * handler - handles signals and write the prompt
 * @num: signal to handle
 *
 * Return: void
 */
void handler(int num)
{
	(void)num;
	write(STDOUT_FILENO, "\n$ ", 3);
}
