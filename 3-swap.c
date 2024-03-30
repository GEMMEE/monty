#include "monty.h"

/**
 * swap_operation - swaps the top two elements of the stack
 * @stk: double pointer to top of the stack
 * @ln: the line number in the bytecode file
 *
 * Author: Gamachu AD
 */
void swap_operation(stack_t **stk, unsigned int ln)
{
	int len, temp;

	len = get_len(stk);
	if (len < 2)
	{
		dprintf(STDERR_FILENO, SWAP_FAIL, ln);
		free_all(1);
		exit(EXIT_FAILURE);
	}
	temp = (*stk)->n;
	(*stk)->n = (*stk)->next->n;
	(*stk)->next->n = temp;
}

/**
 * get_len - returns the number of elements in stack
 * @stk: double pointer to the stack
 *
 * Return: number of elements
 */
int get_len(stack_t **stk)
{
	int count = 0;
	stack_t *temp = *stk;

	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}
