#include "monty.h"

/**
 * void pchar_operation - prints the char at the top of the stack + \n.
 * @stk: double pointer to the top of the stack
 * @ln: line number of bytecode file
 *
 * Description: The integer stored at the top of the stack is treated as
 * the ascii value of the character to be printed
 *
 * Author: Gamachu AD
 */
void pchar_operation(stack_t **stk, unsigned int ln)
{
	if (!*stk) /*stack is empty*/
	{
		dprintf(STDERR_FILENO, PCHAR_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	if (!isascii((*stk)->n))
	{
		dprintf(STDERR_FILENO, PCHAR_NOT_ASCII, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stk)->n);
}
