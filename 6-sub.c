#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack || !(*stack)->next)
                print_subtract_error(line_number);

        (*stack)->next->n -= (*stack)->n;
        pop(stack, line_number);
}

