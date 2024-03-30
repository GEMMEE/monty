#include "monty.h"

/**
 * mul_operation - multiplies the second top element of the stack with
 *                 the top element of the stack
 * @stk: double pointer to the top of the stack
 * @ln: line number of the bytecode file
 *
 * Description: The result(product) is stored in the second top element, and
 * the top element is removed, so that at the end:
 * the top element of the stack contains the result
 * the stack is one element shorter
 *
 * Author: Gamachu AD
 */
void mul_operation(stack_t **stk, unsigned int ln)
{
	int len, prod;
	stack_t *temp;

	len = get_len(stk);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, MUL_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	/*Multiply the second top by the top and store the result in prod*/
	prod = (*stk)->next->n * (*stk)->n;
	/*Update the second top to hold the result*/
	(*stk)->next->n = prod;
	/*Move the top pointer to the second top and free the top element*/
	temp = (*stk)->next;
	free(*stk);
	*stk = temp;
	(*stk)->prev = NULL;
}
