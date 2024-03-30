#include "monty.h"

/**
 * add_operation - adds the top two elements of the stack
 * @stk: double pointer to the top of the stack
 * @ln: the line number in monty bytecode file
 *
 * Author: Gamachu AD
 */
void add_operation(stack_t **stk, unsigned int ln)
{
	int len, sum;
	stack_t *temp;

	len = get_len(stk);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, ADD_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	sum = (*stk)->n + (*stk)->next->n;
	(*stk)->next->n = sum;
	temp = (*stk)->next;
	free(*stk);
	*stk = temp;
	(*stk)->prev = NULL;
}
