#include "monty.h"

/**
 * process_line - processes the line
 * @trimmed_line: the trimmed line
 * @line_number: the line number
 * @stack: the stack
 */
void process_line(char *trimmed_line, unsigned int line_number,
				stack_t **stack)
{
	char opcode[MAX_LINE_LENGTH];
	int argument;
	int matches = sscanf(trimmed_line, "%s %d", opcode, &argument);

	/* Check if the line is a comment (starts with #) */
	if (trimmed_line[0] == '#')
	{
		process_comment(trimmed_line);
		return;  /* Ignore comments */
	}
	if (matches == 2 && strcmp(opcode, "push") == 0)
	{
		if (is_valid_integer(trimmed_line + strlen("push"), &argument))
			push(stack, argument);
		else
			print_push_error(line_number);
	}
	else if (matches == 2)
	{
		print_unknown_instruction_error(line_number, trimmed_line);
	}
	else if (matches == 1)
	{
		switch_opcode(opcode, stack, line_number);
	}
}


/**
 * is_valid_integer - checks if a given string represents a valid integer.
 * @str: The input string to check.
 * @result: A pointer to store the resulting integer if valid.
 * Return: 1 if the string is a valid integer,
 *				   0 otherwise.
 */
int is_valid_integer(const char *str, int *result)
{
	/* Use strtol to convert the string to a long integer */
	char *endptr;
	long value = strtol(str, &endptr, 10);

	/* Check if the entire string is a valid integer */
	if (*endptr != '\0')
		return (0);  /* Not a valid integer */
	*result = (int)value;
	return (1);
}


/**
 * switch_opcode - handles opcode using switch statement
 * @opcode: the opcode
 * @stack: the stack
 * @line_number: the line number
 */
void switch_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	OpcodeValue ov = get_opcode_value(opcode);

	switch (ov)
	{
	case PALL:
		pall(stack);
		break;
	case PINT:
		pint(stack, line_number);
		break;
	case POP:
		pop(stack, line_number);
		break;
	case SWAP:
		swap(stack, line_number);
		break;
	case ADD:
		add(stack, line_number);
		break;
	case NOP:
		nop(stack, line_number);
		break;
	case SUB:
		sub(stack, line_number);
		break;
	case DIV:
		divide(stack, line_number);
		break;
	case MUL:
		multiply(stack, line_number);
		break;
	case MOD:
		modulus(stack, line_number);
		break;
	case PUSH:
		print_push_error(line_number);
	default:
		print_unknown_instruction_error(line_number, opcode);
	}
}

/**
 * get_opcode_value - returns the value corresponding to the opcode
 * @opcode: the opcode
 * Return: the corresponding value
 */
int get_opcode_value(char *opcode)
{
	if (strcmp(opcode, "pall") == 0)
		return (PALL);
	else if (strcmp(opcode, "pint") == 0)
		return (PINT);
	else if (strcmp(opcode, "pop") == 0)
		return (POP);
	else if (strcmp(opcode, "swap") == 0)
		return (SWAP);
	else if (strcmp(opcode, "add") == 0)
		return (ADD);
	else if (strcmp(opcode, "nop") == 0)
		return (NOP);
	else if (strcmp(opcode, "sub") == 0)
		return (SUB);
	else if (strcmp(opcode, "div") == 0)
		return (DIV);
	else if (strcmp(opcode, "mul") == 0)
		return (MUL);
	else if (strcmp(opcode, "mod") == 0)
		return (MOD);
	else if (strcmp(opcode, "push") == 0)
		return (PUSH);
	/* Add other cases as needed */
	return (UNKNOWN);
}

