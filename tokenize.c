#include "terrain.h"

/**
 * tokenize - creates an array of words from a string
 * @str: the string
 * @delimiter: the delimiteriter of words
 * Return: an array of words
 */

char **tokenize(char *str, const char *delimiter)
{
	int i, wn;
	char **array;
	char *token;
	char *copy;

	copy = strdup(str);

	token = strtok(copy, delimiter);
	array = malloc((sizeof(char *) * 2));
	array[0] = _strdup(token);

	i = 1;
	wn = 3;
	while (token)
	{
		token = strtok(NULL, delimiter);
		array = realloc(array, (sizeof(char *) * wn));
		array[i] = _strdup(token);
		i++;
		wn++;
	}
	free(copy);
	return (array);
}
