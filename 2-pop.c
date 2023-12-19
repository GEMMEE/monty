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
		print_pop_error(line_number);
	}

	*stack = (*stack)->next;

	if (*stack)
	{
		(*stack)->prev = NULL;
	}

	free(temp);
}
