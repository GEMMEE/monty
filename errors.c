#include "monty.h"


static const ErrorInfo error_messages[] = {
	{USAGE_ERROR, "USAGE: monty file"},
	{FILE_OPEN_ERROR, "Error: Can't open file %s"},
	{MALLOC_ERROR, "Error: malloc failed\n"},
	{PUSH_ERROR, "L%d: usage: push integer\n"},
	{UNKNOWN_INSTRUCTION_ERROR, "L%d: unknown instruction %s\n"},
	{PINT_ERROR, "L%d: can't pint, stack empty\n"},
	{POP_ERROR, "L%d: can't pop an empty stack\n"},
	{SWAP_ERROR, "L%d: can't swap, stack too short\n"},
	{ADD_ERROR, "L%d: can't add, stack too short\n"},
	{SUBTRACT_ERROR, "L%d: can't sub, stack too short\n"},
	{DIVIDE_ERROR, "L%d: can't div, stack too short\n"},
	{ZERO_DIVIDE_ERROR, "L%d: division by zero\n"},
	{MULTIPLY_ERROR, "L%d: can't mul, stack too short\n"},
	{MODULUS_ERROR, "L%d: can't mod, stack too short\n"},
};

/**
 * print_error - Prints an error message based on the given error type.
 * @type: The error type.
 * @line_number: The line number where the error occurred.
 * @extra_info: Additional infomation to include in the error message.
 */
void print_error(ErrorType type, unsigned int line_number,
		const char *extra_info)
{
	if (type == FILE_OPEN_ERROR)
		fprintf(stderr, error_messages[type].message, extra_info);
	else
		fprintf(stderr, error_messages[type].message, line_number, extra_info);
	exit(EXIT_FAILURE);
}

