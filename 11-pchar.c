#include "monty.h"

/**
 * pchar - Prints the character at the top of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The line number in the Monty byte code file.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		print_error(PCHAR_STACK_ERROR, line_number, NULL);
	}
	else
	{
		int value = (*stack)->n;

		if (value >= 0 && value <= 127)  /* Check if it's a valid ASCII value */
		{
			putchar(value);
			putchar('\n');
		}
		else
		{
			print_error(PCHAR_VALUE_ERROR, line_number, NULL);
		}
	}
}

