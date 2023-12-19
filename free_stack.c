#include "monty.h"
#include <stdlib.h>

/**
 * free_stack - Frees the memory allocated for the stack nodes.
 * @stack: A pointer to the top of the stack.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;
	stack_t *next;

	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
