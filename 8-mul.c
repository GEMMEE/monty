#include "monty.h"

/**
 * multiply - multiplies the second top element of the stack by the top element
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void multiply(stack_t **stack, unsigned int line_number)
{
        if (!stack || !*stack || !(*stack)->next)
                print_multiply_error(line_number);

        (*stack)->next->n *= (*stack)->n;
        pop(stack, line_number);
}
