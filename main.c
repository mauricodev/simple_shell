#include "header.h"

/**
 * main - main function
 * @ac: ...
 * @av: arguments of the programm
 * Return: 0 is success, Otherwise 1
 */
int main(int ac __attribute__ ((unused)), char *av[])
{
	char *line = NULL, **paths, **ar;
	int count = 1, status = 0;

	signal(SIGINT, continue_programm);
	while (1)
	{
		prompt();

		line = get_input(status);
		if (line == NULL)
		{
			count++;
			continue;
		}

		ar = tokenizer(line, " \t\n");
		compare_builtins(ar, av, count, &status);

		if (_strcmp(ar[0], "env") != 0 && _strcmp(ar[0], "exit") != 0)
		{
			paths = get_PATHS();
			validation(ar, paths, av, count, &status);

			free_ar(paths);
		}
		count++;
		free_ar(ar);
	}
	return (0);
}
