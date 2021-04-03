#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{

	char *input_string = NULL;
	size_t len_string;
	int _getline;

	while(write(1 ,"$ ", 2))
	{
		_getline = getline(&input_string, &len_string, stdin);
		if (!strcmp(input_string,"exit\n") || _getline == EOF)
		{
			free(input_string);
			return (0);
		}
		else
		{
			free(input_string);
			input_string == NULL;
			len_string = 0;
		}
	}
	return (0);
}
