#include "terrain.h"

/**
 * _atoi - converts a string into integer
 * @s: the string
 * Return: integer
 */
int _atoi(char *s)
{
	int i, integer, sign = 1;

	i = 0;
	integer = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		integer = (integer * 10) + (sign * (s[i] - '0'));
		i++;
	}
	return (integer);
}

/**
 * _strdup - copies a string in a newly allocated memory area
 * @str: the string that will be copied
 * Return: the copy of str
 */
char *_strdup(char *str)
{
	int i, l;
	char *new;

	if (!str)
	{
		return (0);
	}
	for (l = 0; str[l] != '\0';)
	{
		l++;
	}
	new = malloc(sizeof(char) * l + 1);
	if (!new)
	{
		return (0);
	}
	for (i = 0; i < l; i++)
	{
		new[i] = str[i];
	}
	new[l] = str[l];
	return (new);
}


/**
 * freearv - frees the array of words arv
 *@arv: array of words
 */

void freearv(char **arv)
{
	int i;

	for (i = 0; arv[i]; i++)
		free(arv[i]);
	free(arv);
}
