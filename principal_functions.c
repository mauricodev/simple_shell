#include "header.h"

/**
 * validation - get and tokenizes paths
 * @ar: ...
 * @paths: ...
 * Return: void
 */
int validation(char **ar, char **paths)
{
	int i;
	char *abspath_concat = "";

	for (i = 0; paths[i] != NULL; i++)
	{
		abspath_concat = _strcat(paths[i], ar[0]);

		if (access(abspath_concat, X_OK) != -1)
		{
			ar[0] = abspath_concat;
			return (1);
		}
		free(abspath_concat);
	}

	return (0);
}

/**
 * prompt - desc
 * Return: void
 */
void prompt(void)
{
	char *pr = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, pr, _strlen(pr));
}


/**
 * get_input - desc
 * Return: Input string
 */
char *get_input(void)
{
	char *line = NULL;
	ssize_t n;
	size_t size = 0;

	n = getline(&line, &size, stdin);
	if (line == NULL)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	else if (n == 1)
	{
		free(line);
		return (NULL);
	}
	else if (n == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	return (line);
}

/**
 * compare_builtins - desc
 * @ar: ...
 * @line: ...
 * Return: 1 (Find a success compare)
 */
int compare_builtins(char **ar, char *line)
{
	if (write_exit(ar) == 1)
	{
		free_ar(ar);
		free(line);
		exit(0);
	}
	if (write_env(ar) == 1)
	{
		fprintenv(environ);
		return (1);
	}

	return (0);
}

/**
 * handle_child_process - desc
 * @ar: ...
 * @av: ...
 * @cnt: ...
 * @line: ...
 * Return: 1 (Success). It fails -1
 */
int handle_child_process(char **ar, char **av, int cnt, char *line)
{
	pid_t pid;

	if (ar == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		perror(av[0]);
		free_ar(ar);
		free(line);
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(ar[0], ar, environ) == -1)
		{
			print_error(av[0], cnt, ar[0]);
			free_ar(ar);
			free(line);
			exit(1);
		}
		free_ar(ar);
		free(line);
		exit(0);
	}
	else
	{
		wait(NULL);
	}

	return (1);
}
