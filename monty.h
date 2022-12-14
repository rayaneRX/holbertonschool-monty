#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

extern int element;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;




/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*opfun)(stack_t **top, unsigned int line_number);
opfun function(char *s);


char *tokener(stack_t **top, unsigned int line_number, char *line);
void pusher(stack_t **top, unsigned int line_number);
void paller(stack_t **top, unsigned int line_number);
void noper(stack_t **top, unsigned int l);
int isEmpty(stack_t *head);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);

void reader(char *file, stack_t **top);

void _exit_(stack_t **top);
void _free(stack_t *top);
int int_error(char *s);
int no_int(char *s);


#endif
