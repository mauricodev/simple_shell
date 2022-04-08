#include "header.h"

/**
 * _strlen - Returns the length of a string
 * @s: String
 * Return: void
 */
int _strlen(char *s)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}

	return (i);
}

/**
 * _strcpy - copies the string pointed to by src, including the terminating
 * null byte (\0), to the buffer pointed to by dest.
 * @dest: Copy from the string source
 * @src: string source
 * Return: void
 */
char *_strcpy(char *dest, char *src)
{
	int len, i;
	char *p_counter = src;

	len = 0;
	while (*p_counter)
	{
		len++;
		p_counter++;
	}
	for (i = 0; i <= len; i++)
	{
		*dest = *src;

		src++;
		dest++;
	}
	while (len >= 0)
	{
		dest--;
		len--;
	}
	return (dest);
}

/**
 * _strcat - concatenates two strings.
 * @dest: First string
 * @src: Second string
 * Return: String after concatenation
 */
char *_strcat(char *dest, char *src)
{
	int len;
	int i;

	len = 0;

	while (*dest)
	{
		dest++;
		len++;
	}

	for (i = 0; *(src + i); i++)
	{
		*dest = *(src + i);
		dest++;
		len++;
	}

	*dest = '\0';

	while (len > 0)
	{
		dest--;
		len--;
	}

	return (dest);
}

/**
 * _strcmp - compares two strings.
 * @s1: First string
 * @s2: Second string
 * Return: If both strings are equal returns 0.
 * If the matching character of left string has greater ASCII value than the
 * character of the right string returns a value greater than zero.
 * If the matching character of left string has lesser ASCII value than the
 * character of the right string returns a value less than zero.
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int len_s1;
	char *p_s1 = s1;

	len_s1 = 0;
	while (*p_s1)
	{
		p_s1++;
		len_s1++;
	}
	for (i = 0; i < len_s1; i++)
	{
		if (*s1 != *s2)
		{
			if (*s1 > *s2)
			{
				return (*s1 - *s2);
			}
			else if (*s2 > *s1)
			{
				return (*s1 - *s2);
			}
		}
		s1++;
		s2++;
	}
	return (0);
}

/**
 * _strdup - desc
 * @str: desc
 *
 * Return: Pointer to the string duplicated
 */
char *_strdup(char *str)
{
	int size, i;
	char *s_array;

	if (str == NULL)
		return (NULL);

	size = 0;
	while (*(str + size))
	{
		size++;
	}

	s_array = malloc((size * sizeof(char)) + 1);

	if (s_array == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		*(s_array + i) = *(str + i);
		i++;
	}
	*(s_array + i) = '\0';

	return (s_array);
}
