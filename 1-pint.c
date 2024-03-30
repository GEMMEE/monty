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

	top = get_dnode_top(stk, ln);
	printf("%d\n", top);
}

/**
 * get_dnode_top - returns the top element
 * @stk: double pointer to top of the stack
 * @ln: the line number
 *
 * Return: the top element
 */
int get_dnode_top(stack_t **stk, unsigned int ln)
{
	if (!*stk)
	{
		dprintf(STDERR_FILENO, PINT_FAIL, ln);
		exit(EXIT_FAILURE);
	}
	return ((*stk)->n);
}
