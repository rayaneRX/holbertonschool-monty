#include "monty.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @av: values of arguments
 *
 * Return: On success O, on failure 1
 */
int element = 0;
int main(int ac, char *av[])
{
	stack_t *top;


	top = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	reader(av[1], &top);
	_free(top);
	return (0);
}
