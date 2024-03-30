#include "monty.h"

/**
 * pint_operation - prints the value at the top of the stack + \n.
 * @stk: double pointer to top of the stack
 * @ln: the number of line in the file
 *
 * Author: Gamachu AD
 */
void pint_operation(stack_t **stk, unsigned int ln)
{
	int top;

	if (!*stk)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	top = get_top(stk);
	printf("%d\n", top);
}

/**
 * get_top - returns the top element
 * @stk: double pointer to top of the stack
 *
 * Return: the top element
 */
int get_top(stack_t **stk)
{
	return ((*stk)->n);
}
