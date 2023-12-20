#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
		print_error(ADD_ERROR, line_number, NULL);

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
