#include "header.h"

/**
 * main - main function
 * @ac: ...
 * @av: arguments of the programm
 * Return: 0 is success, Otherwise 1
 */
int main(int ac __attribute__ ((unused)), char *av[])
{
	char *line = NULL, **ar;
	int count = 0;

	while (1)
	{
		prompt();

		line = get_input();
		if (!line)
		{
			count++;
			continue;
		}

		ar = split_string(line, " \t\n");

		if (write_env(ar) == 1)
		{
			count++;
			fprintenv(environ);
		}

		if (_strcmp(ar[0], "env") != 0)
		{
			count++;
			handle_child_process(ar, av, count);
		}
		free_ar(ar);
		free(line);
	}
	return (0);
}