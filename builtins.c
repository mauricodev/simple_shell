#include "header.h"

/**
 * fprintenv - Prints the current environment
 * @env: Environment variable
 *
 * Return: void
 */
void fprintenv(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		_puts(env[i]);
}