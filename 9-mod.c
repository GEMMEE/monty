#include "monty.h"

/**
 * mod_operation - computes the rest of division of the second top element of
 *                 the stack by the top element of the stack
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The result(remainder) is stored in the second top element, and
 * the top element is removed, so that at the end:
 * the top element of the stack contains the result
 * the stack is one element shorter
 *
 * Author: Gamachu AD
 */
void mod_operation(stack_t **stk, unsigned int ln)
{
	int len, rem;
	stack_t *temp;

	len = get_len(stk);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, MOD_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	if ((*stk)->n == 0)
	{
		dprintf(STDERR_FILENO, DIV_ZERO, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	/*Store the modulus of the second top by the top rem*/
	rem = (*stk)->next->n % (*stk)->n;
	/*Update the second top to hold the result*/
	(*stk)->next->n = rem;
	/*Move the top pointer to the second top and free the top element*/
	temp = (*stk)->next;
	free(*stk);
	*stk = temp;
	(*stk)->prev = NULL;
}
