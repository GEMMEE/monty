#include "monty.h"

/**
 * print_usage_error - Prints an error message for incorrect command-line usage
 *		       Exits the program with a failure status
 */
void print_usage_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * print_file_open_error - Prints an error message when the Monty interpreter
 *			   is unable to open the specified file.
 * @filename: The name of the file that could not be opened.
 */
void print_file_open_error(const char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * print_malloc_error - Prints an error message when dynamic memory allocation
 * using malloc fails. Exits the program with a failure status.
 */
void print_malloc_error(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * print_push_error - Prints an error message related to the push instruction.
 * Indicates an issue with the usage of the push instruction.
 * @line_number: The line number where the error occurred.
 */
void print_push_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * print_unknown_instruction_error - Prints an error message when an unknown
 * instruction is encountered in the Monty byte code file.
 * @line_number: The line number where the error occurred.
 * @instruction: The unrecognized instruction encountered.
 */
void print_unknown_instruction_error(unsigned int line_number,
					const char *instruction)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, instruction);
	exit(EXIT_FAILURE);
}

/**
 * print_pint_error - Prints an error message if the stack is empty
 * @line_number: the line number
 */
void print_pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * print_pop_error - Prints an error message if the stack is empty
 * @line_number: the line number
 */
void print_pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * print_swap_error - Prints an error message for the swap opcode.
 * @line_number: The line number in the Monty byte code file where
 * the error occurred.
 */
void print_swap_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}

/**
 * print_add_error - Prints the 'can't add, stack too short' error message.
 * @line_number: The line number in the Monty byte code file.
 */
void print_add_error(unsigned int line_number)
{
	fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
	exit(EXIT_FAILURE);
}
