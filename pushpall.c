#include "monty.h"


/**
 * tokener - tokenizes and converts
 * @top: first node of stack
 * @line_number: number of line in file
 * @line: line of file
 *
 * Return: opcode instruction
 */
char *tokener(stack_t **top, unsigned int line_number, char *line)
{
	char *instr, *func, *tok;


	func = "push";
	instr = strtok(line, "\n ");
	if (instr == NULL)
		return (NULL);

	if (strcmp(instr, func) == 0)
	{
		tok = strtok(NULL, "\n ");
		if (tok == NULL || no_int(tok))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			_exit_(top);
		}
		if (int_error(tok))
			element = atoi(tok);
	}
	return (instr);
}

/**
 * pusher - pushes an element at the top of the stack
 * @line_number: line number
 * @top: top of stack
 *
 * Return: top of stack
 */


void pusher(stack_t **top, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;


	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed");
		_exit_(top);
	}

	if (*top == NULL)
	{
		new->n = element;
		new->next = NULL;
		new->prev = NULL;
		*top = new;
		return;
	}
	(*top)->prev = new;
	new->n = element;
	new->next = *top;
	new->prev = NULL;
	*top = new;


}

/**
 * paller - prints the stack
 * @top: top element of the stack
 * @line_number: line number of file
 *
 */
void paller(stack_t **top, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	temp = *top;

	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}


}



/**
 * int_error - isdigit control
 * @s: string
 *
 * Return: 0 on sucess, 1 on error
 */
int int_error(char *s)
{
unsigned int n = 0;

while (s[n])
{
	if (!isdigit(s[n]))
		return (0);
	n++;
}
return (1);
}

int no_int(char *s)
{
	int k;

	for (k = 0; s[k]; k++)
	{
		if (s[k] == '-' && k == 0)
			continue;
		if (isdigit(s[k]) == 0)
			return (1);
	}
	return (0);
}
