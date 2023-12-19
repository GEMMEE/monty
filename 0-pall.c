#include "monty.h"
#include <stdio.h>

/**
 * pall - Prints all the values on the stack, starting from the top
 * @stack: A double pointer to the stack.
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

