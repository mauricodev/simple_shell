#include "header.h"

/**
 * get_PATHS - Get and tokenizes PATHS
 *
 * Return: New array of tokens of PATHS
 */
char **get_PATHS(void)
{
	int i = 0, size = 0;
	char **aux, **paths, *path;
	char delim[] = ":";

	path = get_paths_of_env_var("PATH=");
	if (path == NULL)
		return (NULL);

	paths = tokenizer(path, delim);
	if (paths == NULL || *(paths) == NULL)
		return (NULL);

	while (*(paths + i))
	{
		size++;
		i++;
	}

	aux = foreach_concat(paths, "/");
	if (aux == NULL)
		return (NULL);

	free_ar(paths);

	return (aux);
}

/**
 * foreach_concat - Concatenates the same string for each element of the array
 * @ar: ...
 * @src: ...
 *
 * Return: New array of strings
 */
char **foreach_concat(char **ar, char *src)
{
	char **new_ar;
	int size = 0, i = 0;

	if (ar == NULL || *(ar) == NULL || src == NULL)
		return (NULL);

	for (size = 0; *(ar + size); size++)
		;

	new_ar = _calloc(size + 1, sizeof(char *));
	if (new_ar == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_ar[i] = str_concat(ar[i], src);

	return (new_ar);
}

/**
 * get_paths_of_env_var - get list of the path(s) of environment variable
 * @env: Environment variable
 *
 * Return: New string of the path(s) of environment variable
 * Otherwise NULL
 */
char *get_paths_of_env_var(char *env)
{
	int i;
	char *envline, *envpath;

	if (environ == NULL || *(environ) == NULL || env == NULL)
		return (NULL);
	envline = _calloc(1024, sizeof(char));
	if (envline == NULL)
		return (NULL);
	envpath = _calloc(1024, sizeof(char));
	if (envpath == NULL)
	{
		free(envline);
		return (NULL);
	}
	for (i = 0; *(environ + i); i++)
	{
		if (_strncmp(*(environ + i), env, _strlen(env)) == 0)
		{
			_strcpy(envline, *(environ + i));
			break;
		}
	}
	if (*(envline) == '\0')
	{
		free(envline);
		free(envpath);
		return (NULL);
	}
	for (i = 0; i < (_strlen(env)); i++)
		;
	if (*(envline + i) == '\0')
	{
		free(envline);
		free(envpath);
		return (NULL);
	}
	_strcpy(envpath, envline + i);
	free(envline);
	return (envpath);
}
