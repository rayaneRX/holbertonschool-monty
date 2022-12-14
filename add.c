#include "monty.h"

/**
 * _add -  adds the first two nodes of the stack
 * @stack: stack given by main
 * @line_number: the number of the line
 * Return: void
 */
void _add(stack_t **stack, unsigned int line_number)
{
	int k;

	if (!stack || !*stack || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		return;
	}

	k = ((*stack)->next->n) + ((*stack)->n);
	monty_pop(stack, line_number);/*For top node*/
	(*stack)->n = k;
}
