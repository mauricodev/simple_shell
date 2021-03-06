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
		if (ar == NULL)
			continue;

		compare_dollar(ar, status);
		compare_builtins(ar, av, count, &status);
		compare_builtins_2(ar, av, count, &status);

		if (write_builtins(ar) == 0)
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
