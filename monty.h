#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


#define MAX_LINE_LENGTH 1024



/**
 * enum ErrorType - Enumeration of error types in the Monty interpreter.
 * @USAGE_ERROR: Incorrect command-line usage error.
 * @FILE_OPEN_ERROR: File open error.
 * @MALLOC_ERROR: Memory allocation error.
 * @PUSH_ERROR: Push instruction error.
 * @UNKNOWN_INSTRUCTION_ERROR: Unknown instruction error.
 * @PINT_ERROR: Pint instruction error (stack empty).
 * @POP_ERROR: Pop instruction error (stack empty).
 * @SWAP_ERROR: Swap instruction error (stack too short).
 * @ADD_ERROR: Add instruction error (stack too short).
 * @SUBTRACT_ERROR: Subtract instruction error (stack too short).
 * @DIVIDE_ERROR: Divide instruction error (stack too short).
 * @ZERO_DIVIDE_ERROR: Division by zero error.
 * @MULTIPLY_ERROR: Multiply instruction error (stack too short).
 * @MODULUS_ERROR: Modulus instruction error (stack too short).
 * @PCHAR_STACK_ERROR: Print character instruction error (stack empty).
 * @PCHAR_VALUE_ERROR: Print character instruction error (value out of range).
 */
typedef enum ErrorType
{
	USAGE_ERROR,
	FILE_OPEN_ERROR,
	MALLOC_ERROR,
	PUSH_ERROR,
	UNKNOWN_INSTRUCTION_ERROR,
	PINT_ERROR,
	POP_ERROR,
	SWAP_ERROR,
	ADD_ERROR,
	SUBTRACT_ERROR,
	DIVIDE_ERROR,
	ZERO_DIVIDE_ERROR,
	MULTIPLY_ERROR,
	MODULUS_ERROR,
	PCHAR_STACK_ERROR,
	PCHAR_VALUE_ERROR
} ErrorType;

/**
 * struct ErrorInfo - Represents information about an error, including its type
 * and associated message.
 * @type: the type of the error
 * @message: the associated error message
 */
typedef struct ErrorInfo
{
	ErrorType type;
	const char *message;
} ErrorInfo;


/**
 * enum OpcodeValue - Represents the opcode values for Monty ByteCode
 *                    instructions
 * @PUSH: Pushes an element onto the stack
 * @PALL: Prints all values on the stack
 * @PINT: Prints the value at the top of the stack
 * @POP: Removes the top element of the stack
 * @SWAP: Swaps the top two elements of the stack
 * @ADD: Adds the top two elements of the stack
 * @NOP: No operation, does nothing
 * @SUB: Subtracts the second top element from top element
 * @DIV: Divides the second top element by the top element
 * @MUL: Multiplies the top two elements of the stack
 * @MOD: Gives remainder of division of the second top by the top element
 * @PCHAR: Prints the char at the top of the stack
 * @UNKNOWN: Represents an unknown opcode
 */
typedef enum OpcodeValue
{
	PALL,
	PINT,
	POP,
	SWAP,
	ADD,
	NOP,
	SUB,
	DIV,
	MUL,
	MOD,
	PUSH,
	PCHAR,
	UNKNOWN
} OpcodeValue;


void process_line(char *trimmed_line, unsigned int line_number,
		stack_t **stack);
char *trim_spaces(char *str);
int is_valid_integer(const char *str, int *result);
void switch_opcode(char *opcode, stack_t **stack,
		unsigned int line_number);
int get_opcode_value(char *opcode);
int is_valid_integer(const char *str, int *result);
void free_stack(stack_t *stack);


void push(stack_t **stack, int value);
void pall(stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void multiply(stack_t **stack, unsigned int line_number);
void modulus(stack_t **stack, unsigned int line_number);
void process_comment(char *trimmed_line);
void pchar(stack_t **stack, unsigned int line_number);

/* Function prototype for error-related functions */
void print_error(ErrorType type, unsigned int line_number,
			const char *extra_info);
#endif /* MONTY_H */

