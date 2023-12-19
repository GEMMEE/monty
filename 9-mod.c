#include "monty.h"

/**
 * modulus - computes the rest of the division of the second top element of
 *           the stack by the top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void modulus(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack || !(*stack)->next)
                print_modulus_error(line_number);

	if ((*stack)->n == 0)
		print_zero_error(line_number);

        (*stack)->next->n %= (*stack)->n;
        pop(stack, line_number);
}
