#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @stack: the stack
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL)
	{
		print_error(POP_ERROR, line_number, NULL);
	}

	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
