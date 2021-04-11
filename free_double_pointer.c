#include "shell.h"

/**
 * free_double_pointer - frees all the memory
 * of a double pointer
 * @d_ptr: the double pointer to free
 *
 * Return: void
 */

void free_double_pointer(char **d_ptr)
{
	int i = 0;

	if (d_ptr == NULL)
		return;

	while (d_ptr[i])
	{
		free(d_ptr[i]);
		++i;
	}

	if (d_ptr[i] == NULL)
		free(d_ptr[i]);

	free(d_ptr);
}
