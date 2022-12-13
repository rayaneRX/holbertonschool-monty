#include "monty.h"

/**
 * reader - reads file
 * @file: file
 * @top: top of stack
 *
 */

void reader(char *file, stack_t **top)
{
	unsigned int line_num = 1;
	int fd, r;
	char *buff = NULL, *line;
	size_t size = 0;
	opfun getter;
	FILE *f = fopen(file, "r");

	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		_exit_(top);
	}
	while ((r = getline(&buff, &size, f)) != -1)
	{
		line = tokener(top, line_num, buff);
		if (line == NULL)
		{
			line_num++;
			continue;
		}
		getter = function(line);
		if (getter == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, line);
			_exit_(top);
		}
		getter(top, line_num);
		line_num++;
	}
	free(buff);
	fd = fclose(f);
	if (fd == -1)
		exit(fd);
}


/**
 * function - finds the function to perform
 * @s: line in file
 * Return: function to perform
 *
 */

opfun function(char *s)
{
	instruction_t ins[] = {
		{"push", pusher},
		{"pall", paller},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"nop", noper},
		{NULL, NULL},
	};

	int i;

	i = 0;

	while (ins[i].f != NULL && strcmp(s, ins[i].opcode) != 0)
	{
		i++;
	}
	return (ins[i].f);

}

