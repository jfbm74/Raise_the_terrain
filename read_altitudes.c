#include "terrain.h"

/**
 * read_altitudes - reads a file of altitudes and save it into 2d Array
 * @argv: value of arguments
 * Return: 2D array
 */
int **read_altitudes(char **argv)
{
	char mybuf[1024];
	char **lines;
	char **chars[8];
	int **numbers;
	int fd, i, j;

	fd = open(argv[1], O_RDWR);
	read(fd, mybuf, 1023);
	close(fd);

	numbers = malloc(sizeof(int *) * 8);
	for (i = 0; i < 8; i++)

		numbers[i] = malloc(sizeof(int) * 8);
	lines = tokenize(mybuf, "\n");

	for (i = 0; lines[i]; i++)
	{
		chars[i] = tokenize(lines[i], " ");
	}

	for (j = 0; j < 8; j++)
	{
		for (i = 0; i < 8; i++)
		{
			numbers[j][i] = atoi(chars[j][i]);
		}
	}

	freearv(lines);
	for (i = 0; i < 8; i++)
		freearv(chars[i]);

	return (numbers);
}
