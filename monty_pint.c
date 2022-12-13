#include "monty.h"

/**
 * monty_pint - prints the value at the top of the stack
 * @stack : is a stack
 * @line_number : the number of the line
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L<line_number>:%d can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}
