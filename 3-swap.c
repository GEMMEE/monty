#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty byte code file.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!stack || !*stack || !(*stack)->next)
	{
		print_error(SWAP_ERROR, line_number, NULL);
	}

	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;

	*stack = temp;
}
