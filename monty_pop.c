#include "monty.h"

/**
 * monty_pop - function removes the top element of the stack
 * @stack : stack
 * @line_number : the number of the line
 * Return: nothing
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if (!tmp)
		return;
	
    stack_t *tmp = *stack;
    
    if (tmp->next)
	{
		tmp->next->prev = tmp->prev;
	}
	*stack = tmp->next;
	free(tmp);
}