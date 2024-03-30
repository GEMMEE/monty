#include "monty.h"

/**
 * sub_operation - subtracts the top element of the stack from
 *                 the second top element of the stack
 * @stk: double pointer to the top of stack
 * @ln: line number of the bytecode file
 *
 * Description: the result(difference) is stored in the second top element, and
 * the top element is removed, so that at the end:
 * the top element of the stack contains the result
 * the stack is one element shorter
 *
 * Author: Gamachu AD
 */
void sub_operation(stack_t **stk, unsigned int ln)
{
	int len, diff;
	stack_t *temp;

	len = get_len(stk);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, SUB_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	/*Subtract the top from the second top and store in diff*/
	diff = (*stk)->next->n - (*stk)->n;
	/*Store the result in the second top*/
	(*stk)->next->n = diff;
	/*Remove the top element*/
	temp = (*stk)->next;
	free(*stk);
	/*Update the pointer to top*/
	*stk = temp;
	(*stk)->prev = NULL;
}
