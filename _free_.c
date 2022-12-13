#include "monty.h"

/**
 * _free - frees memory
 * @top: top of the stack
 *
 *
 */

void _free(stack_t *top)
{
	stack_t *temp;

	while (top)
	{
		temp = top->next;
		free(top);
		top = temp;
	}

}

/**
 * _exit_ - exits and frees
 * @top: top of stack
 *
 */

void _exit_(stack_t **top)
{
	if (*top)
		_free(*top);
	exit(EXIT_FAILURE);
}
