#include "monty.h"

/**
 * divide - divides the second top element of the stack by the top element
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void divide(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack || !(*stack)->next)
                print_error(DIVIDE_ERROR, line_number, NULL);

	if ((*stack)->n == 0)
		print_error(ZERO_DIVIDE_ERROR, line_number, NULL);

        (*stack)->next->n /= (*stack)->n;
        pop(stack, line_number);
}

