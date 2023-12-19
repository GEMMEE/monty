#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack; /* Avoid unused parameter warning */
	(void)line_number; /* Avoid unused parameter warning */
}
